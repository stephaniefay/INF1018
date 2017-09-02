/*
int add2 (struct X *x) {
  if (x == NULL) return 0;
  else return x->c + add2(x->next);
}
*/
.global add2

add2:
	push	%ebp
	movl	%esp, %ebp

	movl	8(%ebp), %ecx
	cmpl	$0, %ecx
	je	L2
	addl	$4, %ecx
	movl	%ecx, %edx
	push	%edx
	call	add2
	subl	$4, %ecx
	addl	%ecx, %eax
	

L2:	movl	$0, %eax	

	movl	%ebp, %esp
	pop	%ebp
	ret
