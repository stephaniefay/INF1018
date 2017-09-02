/*
int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}
*/

.data

.globl fat
fat:

	pushq %rbp
	movq  %rsp, %rbp
	
	push 
	
	cmpq $0, %rdi
	je L1

	imulq %rdi, %rsi
	subq $1, %rdi	
	call fat

L1:
	movq %rsi, %rax
	
	leave
	ret
