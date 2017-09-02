/*
double foo3 (double *a, int n) {
  int i;
  double r = 0.0;
  for (i=0; i<n; i++) {
    r += sin(*a);
    a++;
  }
  return r;
}

*/

.global foo3

foo3:
	push	%ebp
	movl	%esp, %ebp
	push	%ebx
	push	%esi
	
	subl	$8, (%esp)
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	
	movl	$0, %ebx
	movl	8(%ebp), %esi
	
L1:	cmpl	12(%ebp), %ebx
	je	L2
	
	fldl	(%esi)
	sub     $8, %esp
        fstpl   (%esp)
	call	sin
        add     $8, %esp
	
	fldl	-16(%ebp)
	faddp	
	fstpl	-16(%ebp)

	addl	$1, %ebx
	addl	$8, %esi

	jmp	L1


L2:	fldl	-16(%ebp)
	movl	-8(%ebp), %esi
	movl	-4(%ebp), %ebx
	movl	%ebp, %esp
	pop	%ebp
	ret
