/*double foo2 (float a, float b) {
  return sin(a) + cos(b);
}
*/

.global foo2
foo2:
	push	%ebp
	movl	%esp, %ebp

	fldl	8(%ebp)
	call	sin

	fldl	12(%ebp)
	call	cos
	
	faddp


	movl	%ebp, %esp
	pop	%ebp
	ret
