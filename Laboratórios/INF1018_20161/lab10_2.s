/*
int add2 (struct X *x) {
  if (x == NULL) return 0;
  else return x->val + add2(x->next);
}
*/

.data

.globl add
add:

	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp		
	movq    %rbx, -8(%rbp)

	movq	$0, %rbx

L1:	cmpq	$0, %rdi
	je	L2
	
	movq	(%rdi), %rbx
	movq	8(%rdi), %rdi
	call	add
	addq	%rax, %rbx

L2:	
	movq	%rbx, %rax
	
	movq	-8(%rbp), %rbx
	leave
	ret
