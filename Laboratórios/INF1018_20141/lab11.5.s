/*double f(double x) {
  return x * 2.0;
}

double foo (int a[], double b[], int n) {
  int *pint;
  double *pdouble;

  double sum = 0.0;

  for (pint = a, pdouble = b; n-- ; pint++, pdouble++) {
    *pdouble = f((double)*pint);
    sum += *pdouble;
  }

  return sum;
}*/

.global f
f:
	push	%ebp
	movl	%esp, %ebp

	fld1
	fld1
	faddp

	fldl	8(%ebp)
	fmulp

	movl	%ebp, %esp
	pop	%ebp
	ret


.global foo
foo:

	push	%ebp		
	movl	%esp, %ebp	
	push	%ebx
	push	%esi

	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)	//variavel double local (sum)
	
	movl	8(%ebp), %ebx	// ponteiro para a[]
	movl	12(%ebp), %esi	// ponteiro para b[]

L1:	cmpl	$0, 20(%ebp)
	je	L2
	
	fistpl	8(%ebp)
	call	f		//calculei f
	fstl	12(%ebp)	//guarda b[]
	fldl	-16(%ebp)	//soma parcial
	faddp			//somatorio
	fstpl	-16(%ebp)	// guardei na local

	addl	$4, %ebx
	addl	$4, %esi
	subl	$1, 20(%ebp)	//atualiza todos os valores
	jmp	L1

L2:	fldl	-16(%ebp)
	pop	%esi
	pop	%ebx
	movl	%ebp, %esp
	pop	%ebp
	ret
