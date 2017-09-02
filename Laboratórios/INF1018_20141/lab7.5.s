/*
#include <stdio.h>

int nums[4] = {65, -105, 111, 34};

int main (void) {
  int i;
  int s = 0;

  for (i=0;i<4;i++)
    s = s+nums[i];

  printf ("soma = %d\n", s);

  return 0;
}
*/

.data
S2:	.int 65, -105, 111, 34

Sg:	.string "%d " 
Sh:	.string "\n"

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
	pushl	%ebx
/*******/
	movl	$0, %eax	
	movl	$0, %ebx	/* inicializa contador */
	movl	$S2, %ecx	/* ecx = &S2; */

L1:	cmpl	$4, %ebx	/* contador < 4 */
	je	L2		/* goto L2 */
	addl	(%ecx), %eax	/* eax += ecx; */ 
	addl	$1, %ebx
	addl	$4, %ecx
	jmp	L1		/* goto L1; */


L2:
/****** nao mexa - imprime o valor de %eax !!!! */
/* pode estragar o valor de %eax           ******/
        pushl   %ecx
        pushl   %edx
        pushl   %eax
        pushl   $Sg
 	call	printf	
        addl    $8, %esp
        popl   	%edx
        popl   	%ecx
/*******/

	movl	$0, %eax	/* eax = 0;  (valor de retorno) */

	pushl   %ecx
        pushl   %edx
        pushl   %eax
        pushl   $Sh
 	call	printf	
        addl    $8, %esp
        popl   	%edx
        popl   	%ecx


/****** nao mexa - finalizacao!!!! */

	popl	%ebx
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/


