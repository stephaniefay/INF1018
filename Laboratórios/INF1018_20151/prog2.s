

.data
nums:	.byte	10, -21, -30, 45
Sf:	.string "%d\n"		# string de formato para printf

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
	pushl	%ebx		/* salva ebx */
/*******/

	movb	$0, %ebx	/* ebx = 0; */
	movb	$nums, %ecx	/* ecx = &nums; */
L1:	cmpb	$4, %ebx	/* if (ebx == 4) ? */
	je	L2		/* goto L2 */
	movb	(%ecx), %eax	/* eax = *ecx; */

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

	addb	$1, %ebx	/* ebx += 1; */
	addb	$4, %ecx	/* ecx += 4; */
	jmp	L1		/* goto L1; */
L2:	movb	$0, %eax	/* eax = 0;  (valor de retorno) */

/****** nao mexa - finalizacao!!!! */
	popl	%ebx		
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/



