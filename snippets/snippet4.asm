# g92 -O0
  | main::{unnamed type#1}::operator()() const:
 3|   push rbp
 3|   mov rbp, rsp
 3|   mov QWORD PTR [rbp-8], rdi
 4|   mov eax, 5
 5|   pop rbp
 5|   ret
  | main:
 1|   push rbp
 1|   mov rbp, rsp
 1|   sub rsp, 16
 7|   lea rax, [rbp-1]
 7|   mov rdi, rax
 7|   call main::{unnamed type#1}::operator()() const
 7|   nop
 8|   leave
 8|   ret