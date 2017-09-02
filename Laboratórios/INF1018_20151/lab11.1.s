/*float foo (double a, float b) {
  return (a+b)*(a-b);
}
*/

.global foo
foo:
	push	%ebp
	movl	%esp, %ebp
	
	flds	16(%ebp)	//float
	fldl	8(%ebp)		//double
	fsubp

	flds	16(%ebp)
	fldl	8(%ebp)
	faddp

	fmulp

	movl	%ebp, %esp
	pop	%ebp
	ret
