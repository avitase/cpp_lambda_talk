# g92 -std=c++17
  | std::exception::exception() [base object constructor]:
63|   push rbp
63|   mov rbp, rsp
63|   mov QWORD PTR [rbp-8], rdi
63|   mov edx, OFFSET FLAT:_ZTVSt9exception+16
63|   mov rax, QWORD PTR [rbp-8]
63|   mov QWORD PTR [rax], rdx
63|   nop
63|   pop rbp
63|   ret
  | std::bad_variant_access::what() const:
1203|   push rbp
1203|   mov rbp, rsp
1203|   mov QWORD PTR [rbp-8], rdi
1204|   mov rax, QWORD PTR [rbp-8]
1204|   mov rax, QWORD PTR [rax+8]
1204|   pop rbp
1204|   ret
[...]
