# g92 -std=c++17
  | main::{lambda(int)#1}::operator()(int) const:
 8|   push rbp
 8|   mov rbp, rsp
 8|   sub rsp, 80
 8|   mov QWORD PTR [rbp-56], rdi
 8|   mov DWORD PTR [rbp-60], esi
 8|   mov eax, DWORD PTR [rbp-60]
 8|   add eax, 1
 8|   mov DWORD PTR [rbp-4], eax
 8|   lea rdx, [rbp-4]
 8|   lea rax, [rbp-32]
 8|   mov rsi, rdx
 8|   mov rdi, rax
 8|   call std::variant<int, double>::variant<int, void, void, int, void>(int&&)
 8|   mov rax, QWORD PTR [rbp-32]
 8|   mov rdx, QWORD PTR [rbp-24]
 8|   mov QWORD PTR [rbp-48], rax
 8|   mov QWORD PTR [rbp-40], rdx
[...]
