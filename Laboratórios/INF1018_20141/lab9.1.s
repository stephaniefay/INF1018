.text

.global	add
add:	push	%ebp
	movl	%esp, %ebp

	movl	8(%ebp), %eax
	addl	12(%ebp), %eax
	addl	16(%ebp), %eax

	movl	%ebp, %esp
	pop	%ebp
	ret
