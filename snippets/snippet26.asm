# g92 -std=c++17
  | .LC1:
  |   .string "auto area(const Shape&)"
  | .LC2:
  |   .string "./example.cpp"
  | .LC3:
  |   .string "false"
  | area(Shape const&):
13|   push rbp
13|   mov rbp, rsp
13|   sub rsp, 32
13|   mov QWORD PTR [rbp-24], rdi
14|   mov rax, QWORD PTR [rbp-24]
14|   mov eax, DWORD PTR [rax]
14|   test eax, eax
14|   je .L2
14|   cmp eax, 1
14|   je .L3
14|   jmp .L6
[...]
