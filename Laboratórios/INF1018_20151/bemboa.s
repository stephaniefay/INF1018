/*int bemboba (int num) {
  int local[3];
  int *a;
  int i;

  for (i=0,a=local;i<3;i++) {
    *a = num;
    a++;
  }
  return addl (local, 3);
}
*/

.data
.global bemboba

bemboba:
	push	%ebp
	movl	%esp, %ebp

	sub	$12, %esp
	movl	$0, %edx
	movl	%ebp, %ecx
	subl 	$12, %ecx
	
	cmpl	$3, %edx
	je	L1
	
	movl	8(%ebp), %esi
	movl	%esi, %ecx
	addl	$1, %edx
	
	
	movl	%ebp, %esp
	pop	%ebp
	ret
