/*
int add (int a, int b, int c) {
return a+b+c;
}
*/

.data

.globl add
add:

	pushq %rbp
	movq  %rsp, %rbp
	
	addq %rdi, %rsi
	addq %rsi, %rdx

	movq %rdx, %rax
  	
	
	leave
	ret
