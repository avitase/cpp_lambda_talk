# g92 
  | main::{lambda(int)#1}::operator()(int) const:
 3|   push rbp
 3|   mov rbp, rsp
 3|   mov QWORD PTR [rbp-8], rdi
 3|   mov DWORD PTR [rbp-12], esi
 3|   mov rax, QWORD PTR [rbp-8]
 3|   mov edx, DWORD PTR [rax]
 4|   mov eax, DWORD PTR [rbp-12]
 4|   add eax, edx
 5|   pop rbp
 5|   ret
  | main:
 1|   push rbp
 1|   mov rbp, rsp
 1|   sub rsp, 16
 2|   mov DWORD PTR [rbp-4], 1
 5|   mov eax, DWORD PTR [rbp-4]
 5|   mov DWORD PTR [rbp-12], eax
[...]
