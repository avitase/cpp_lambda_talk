#!/usr/bin/env python3

import os
import sys


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print(f'Error: Usage {sys.argv[0]} [file_name]')
        sys.exit(1)

    file_name = sys.argv[1]
    if not os.path.isfile(file_name):
        print(f'Error: File \'{file_name}\' does not exist!')
        sys.exit(1)

    out_lines = []
    skip_state = False
    with open(file_name, 'r') as f:
        for line in f.readlines():
            if line.strip().startswith('% REMOVE_FOR_PRINT {'):
                if skip_state:
                    print('Parsing error!')
                    sys.exit(2)

                skip_state = True
            elif line.strip().startswith('% REMOVE_FOR_PRINT }'):
                if not skip_state:
                    print('Parsing error!')
                    sys.exit(3)

                skip_state = False
            elif not skip_state:
                out_lines.append(line)

    file_name = file_name.rstrip('.tex') + '_pv.tex'
    with open(file_name, 'w') as f:
        f.write(''.join(out_lines))
