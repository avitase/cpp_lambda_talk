# g92 -O0
  | main::{unnamed type#1}::operator()(int) const:
 3|   push rbp
 3|   mov rbp, rsp
 3|   mov QWORD PTR [rbp-8], rdi
 3|   mov DWORD PTR [rbp-12], esi
 4|   mov eax, DWORD PTR [rbp-12]
 5|   pop rbp
 5|   ret
  | main:
 1|   push rbp
 1|   mov rbp, rsp
 1|   sub rsp, 16
 7|   lea rax, [rbp-1]
 7|   mov esi, 42
 7|   mov rdi, rax
 7|   call main::{unnamed type#1}::operator()(int) const
 7|   nop
 8|   leave
 8|   ret