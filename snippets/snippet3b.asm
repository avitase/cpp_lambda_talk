# g92 -O0
  | main::{lambda(int)#1}::operator()(int) const:
 2|   push rbp
 2|   mov rbp, rsp
 2|   mov QWORD PTR [rbp-8], rdi
 2|   mov DWORD PTR [rbp-12], esi
 2|   mov eax, DWORD PTR [rbp-12]
 2|   pop rbp
 2|   ret
  | main:
 1|   push rbp
 1|   mov rbp, rsp
 1|   sub rsp, 16
 3|   lea rax, [rbp-1]
 3|   mov esi, 42
 3|   mov rdi, rax
 3|   call main::{lambda(int)#1}::operator()(int) const
 3|   nop
 4|   leave
 4|   ret