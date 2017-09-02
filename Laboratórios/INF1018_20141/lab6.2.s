/*
int nums[] = {10, -21, -30, 45};
int main() {
  int i, *p;
  for (i = 0, p = nums; i != 4; i++, p++)
    printf("%d\n", *p);
  return 0;
}
*/

.data
nums:	.int	10, -21, -30, 45
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
	movl	$0, %eax
L1:	cmpl	$4, %ebx	/* if (ebx == 4) ? */
	je	L2		/* goto L2 */
	addl	(%ecx), %eax	/* eax += *ecx; */
        


	addl	$1, %ebx	/* ebx += 1; */
	addl	$4, %ecx	/* ecx += 4; */
	jmp	L1		/* goto L1; */
	
L2:
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
	movl $0, %eax	/*   (valor de retorno) */


/****** nao mexa - finalizacao!!!! */
	popl	%ebx		
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/


