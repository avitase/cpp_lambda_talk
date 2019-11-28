import json
import os
import sys
from collections import defaultdict

import requests


def require(p, error_msg):
    if not p:
        print(f'Error: {error_msg}')
        sys.exit(1)


def read_source(file_name):
    lines = open(file_name, 'r').readlines()
    while len(lines) > 0 and not lines[0].strip():
        lines = lines[1:]

    while len(lines) > 0 and not lines[-1].strip():
        lines = lines[:-1]

    return ''.join(lines)


def read_cfg(file_name):
    lines = open(file_name, 'r').readlines()
    return defaultdict(lambda: None, json.loads(''.join(lines)))


def truncate_source(source, max_lines=20):
    lines = source.split('\n')
    if len(lines) > max_lines + 1:
        lines = lines[:max_lines - 1]
        lines.append('[...]\n')
    return '\n'.join(lines)


def compile(source, compiler, flags=None):
    flags = flags if flags else ''

    filters = {
        'binary': False,
        'commentOnly': True,
        'demangle': True,
        'directives': True,
        'execute': False,
        'intel': True,
        'labels': True,
        'libraryCode': False,
        'trim': True,
    }

    data = {
        'source': source,
        'options': {
            'userArguments': flags,
            'compilerOptions': {},
            'filters': filters,
        }
    }

    url = f'https://godbolt.org/api/compiler/{compiler}/compile'
    headers = {'Content-type': 'application/json', 'Accept': 'application/json'}
    response = requests.post(url, data=json.dumps(data), headers=headers)

    if response.status_code == 200:
        content = json.loads(response.content.decode('utf8'))
        asm = content['asm'] if 'asm' in content else []

        lines = [f'# {compiler} {flags}', ]
        for line in asm:
            txt = line['text']
            src = line['source']

            if not txt.strip().startswith('#'):
                n = src['line'] if src and 'line' in src else ''
                lines.append(f'{n:>2}| {txt}')

        return '\n'.join(lines)
    return None


def upload(source, compiler=None, flags=None, compile=True, execute=False):
    flags = flags if flags else ''

    compiler_cfg = {'id': compiler, 'options': flags, }
    executor_cfg = {'compiler': compiler_cfg, }

    data = {
        'sessions': [{
            'id': 1,
            'language': 'c++',
            'source': source,
            'compilers': [compiler_cfg, ] if compile else [],
            'executors': [executor_cfg, ] if execute else [],
        }, ],
    }

    url = 'https://godbolt.org/shortener'
    headers = {'Content-type': 'application/json', 'Accept': 'text/plain'}
    response = requests.post(url, data=json.dumps(data), headers=headers)
    if response.status_code == 200:
        body = json.loads(response.content.decode('utf8'))
        if 'url' in body:
            return body['url']
    return None


def make_listing(source, url=None, options=None):
    options = options if options else []

    if url:
        title = url.lstrip('http://').lstrip('https://').lstrip('www.')
        title = title.replace('_', r'\_')
        options.append(r'title=\href{' + url + r'}{\texttt{' + title + '}}')

    tex = r'\begin{lstlisting}'
    tex += '[' + ','.join(options) + ']\n'
    tex += source.rstrip() + '\n'
    tex += r'\end{lstlisting}' + '\n'
    return tex


if __name__ == '__main__':
    require(len(sys.argv) == 2, 'Usage {} [file.cfg]'.format(sys.argv[0]))

    cfg_file = sys.argv[1]
    root, _ = os.path.splitext(cfg_file)
    require(os.path.isfile(cfg_file), f'File \'{cfg_file}\' does not exist!')

    cfg = read_cfg(cfg_file)
    cpp_file = os.path.join(os.path.dirname(cfg_file), cfg['cpp_file'])
    require(cpp_file, 'Could not find property \'cpp_file\'!')

    require(os.path.isfile(cpp_file), f'File \'{cpp_file}\' does not exist!')
    source = read_source(cpp_file)
    require(source, f'File \'{cpp_file}\' is empty!')

    compiler = cfg['compiler']
    url = upload(source=source,
                 compiler=compiler,
                 flags=cfg['flags'],
                 compile=(cfg['compile'] is True),
                 execute=(cfg['execute'] is True))
    if not url:
        print('Error: Could not receive URL from godbold.org!')
        url = '???'

    if cfg['compile'] is True:
        asm = compile(source=source, compiler=compiler, flags=cfg['flags'])
        if asm:
            with open(root + '_asmlst.tex', 'w') as f:
                if cfg['truncate'] is not False:
                    asm = truncate_source(asm)

                f.write(make_listing(asm, url=url, options=['language={}', 'numbers=none']))
            open(root + '.asm', 'w').write(asm)
        else:
            print('Error: Could not receive compilation result from godbold.org!')

    with open(root + '_cpplst.tex', 'w') as f:
        if cfg['truncate'] is not False:
            source = truncate_source(source)

        f.write(make_listing(source, url=url))
