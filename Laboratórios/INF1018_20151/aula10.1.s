/*
int novonum(void) {
  int minhalocal;
  printf("numero: ");
  scanf("%d",&minhalocal);
  return minhalocal;
} */


.data

Sf:	.string "%d"
Sg:	.string "numero: "

.global	novonum

novonum:
	push	%ebp
	movl	%esp, %ebp

	push	$Sg
	call	printf
	addl	$4, %esp

	subl	$8, %esp
	movl	%ebp, %eax
	sub	$4, %eax
	
	push 	%eax
	push	$Sf
	call	scanf
	
	movl	-4(%ebp), %eax


	movl	%ebp, %esp
	pop	%ebp
	ret
