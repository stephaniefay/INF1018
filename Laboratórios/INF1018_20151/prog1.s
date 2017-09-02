.data
nums:	.int	10, -21, -30, 45, 0
Sf:	.string "%d\n"		# string de formato para printf

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
	pushl	%ebx		/* salva ebx */
/*******/

	movl	$0, %ebx	/* ebx = 0; */
	movl	$nums, %ecx	/* ecx = &nums; */
L1:	cmpl	$0, (%ecx)	/* if (ecx == 0) ? */
	je	L2		/* goto L2 */
	movl	(%ecx), %eax	/* eax = *ecx; */



/****** nao mexa - imprime o valor de %eax !!!! */
/* pode estragar o valor de %eax           ******/
        pushl   %ecx
        pushl   %edx
        pushl   %eax
        pushl   $Sf
 	call	printf	
        addl    $8, %esp
        popl   %edx
        popl   %ecx
/*******/
	addl    $1, %ebx
	addl    $4, %ecx
	jmp     L1
L2: 	movl $0, %eax	

/****** nao mexa - finalizacao!!!! */
	popl	%ebx		
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/



