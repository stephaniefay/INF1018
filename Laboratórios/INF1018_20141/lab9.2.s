/* int add1 (int *a, int n) {
  int i;
  int s = 0;
  for (i=0; i<n; i++) s += *a++;
  return s;
} */

.text

.global	add1
add1:	push	%ebp
	movl	%esp, %ebp
	
	push	%ebx	/* empilha %ebx para deixar ok */

	movl	$0, %ebx	/* %ebx == i */
	movl	$0, %eax	/* valor de retorno */
	movl	8(%ebp), %ecx	/* %ecx == *a */
L2:	
	cmpl    12(%ebp), %ebx   /* i == n? */
	je	L1
	
		
	addl	(%ecx), %eax    /* s+= *a */
	

	addl	$4, %ecx       /* próximo índice  */
	addl	$1, %ebx	/* incrementa i */
	jmp	L2

L1:	
	popl	%ebx	/* desempilha %ebx para devolver ok */
	movl	%ebp, %esp
	pop	%ebp
	ret
