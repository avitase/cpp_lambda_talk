# g92 
  | X::X(int):
 6|   push rbp
 6|   mov rbp, rsp
 6|   mov QWORD PTR [rbp-8], rdi
 6|   mov DWORD PTR [rbp-12], esi
 6|   mov rax, QWORD PTR [rbp-8]
 6|   mov edx, DWORD PTR [rbp-12]
 6|   mov DWORD PTR [rax], edx
 6|   nop
 6|   pop rbp
 6|   ret
  | X::operator()(int) const:
 8|   push rbp
 8|   mov rbp, rsp
 8|   mov QWORD PTR [rbp-8], rdi
 8|   mov DWORD PTR [rbp-12], esi
 9|   mov rax, QWORD PTR [rbp-8]
 9|   mov edx, DWORD PTR [rax]
[...]
