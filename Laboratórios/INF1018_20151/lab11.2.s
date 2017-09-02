/*float foo1 (float a, float b) {
  return sin(a) + b;
}*/

.global foo1
foo1:
	push	%ebp
	movl	%esp, %ebp
	
	fldl	8(%ebp)
	call	sin
	
	flds	12(%ebp)
	
	faddp
	
	movl	%ebp, %esp
	pop	%ebp
	ret
