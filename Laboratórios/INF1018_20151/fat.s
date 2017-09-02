/*int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}
*/

.global fat

fat:	push	%ebp
	movl	%esp, %ebp
	
	movl	8(%ebp), %ecx
	cmpl	$0, %ecx
	je	L1
	subl	$1, %ecx
	push	%ecx
	call	fat
	addl	$4, %esp
	imul	8(%ebp), %eax
	jmp L2



L1:	movl	$1, %eax	

L2:	movl	%ebp, %esp
	pop %ebp
	ret
