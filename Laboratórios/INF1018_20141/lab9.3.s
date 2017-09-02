/*void foo (int a[], int n) {
  int i;
  int s = 0;
  for (i=0; i<n; i++) {
    s += a[i];
    if (a[i] == 0) {
      a[i] = s;
      s = 0;
    }
  }
}*/

.text

.global foo
foo:	push	%ebp
	movl	%esp, %ebp
	push	%ebx	/* empilha %ebx por segurança */
	
	movl	$0, %ebx	/* %ebx como contador i */
	movl	8(%ebp), %ecx	/* %ecx = a[] */
	movl	$0, %edx	/* %edx = s */

L1:	cmpl	12(%ebp), %ebx	/* i = n ? */
	je L2

	addl	(%ecx), %edx	/* s+=a[i] */
	cmpl	$0, (%ecx)	/* a[i] == 0 ? */
	jne	L3
	movl	%edx, (%ecx)	/* a[i]= s */
	movl	$0, %edx	/* s = 0 */
	

	

L3:	imul	$4, %ebx
	addl	8(%ebp), %ecx
	addl	$1, %ebx

	jmp L1
	
L2:
	pop	%ebx		/* desempilha %ebx para devolver ok */
	movl	%ebp, %esp
	pop	%ebp
	ret
