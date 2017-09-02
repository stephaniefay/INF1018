/*struct X {
  int val;
  struct X *next;
};

int add (struct X *x) {
  int a = 0;
  for (; x != NULL; x = x->next)
    a += x->val;
  return a;
}*/

.global add

add:
	push	%ebp
	movl	%esp, %ebp
	
	movl	$0, %eax
	movl	8(%ebp), %edx

L2:	cmpl	$0, %edx
	je L1
	addl	(%edx), %eax
	addl	$4, %edx
	movl	(%edx), %ecx
	movl	%ecx, %edx
	jmp	L2
	

L1:	movl	%ebp, %esp
	pop	%ebp
	ret
