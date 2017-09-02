/*
#include <stdio.h>


int main (void) {
  int contador = 0;

  while (contador < 11){
    printf ("%d ", (contador*contador) );
    contador++;
}

  printf("\n");
  return 0;

}*/


.data

Sg:   .string "%d " 
Sh:   .string "\n"

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
/*******/
	movl	$1, %ecx	/* ecx = 1; */
L1:	cmpb	$11, (%ecx)	/* while( ecx < 11 ) */
	je	L2		/* goto L2 */
	imul	%ecx
	movsbl	(%ecx), %eax	/* eax = *ecx; */

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

	addl	$1, %ecx	/* ecx += 1; */
	jmp	L1		/* goto L1; */
L2:	movl	$0, %eax	/* eax = 0;  (valor de retorno) */

/****** nao mexa - finalizacao!!!! */	
	popl	%ebx
        movl    %ebp, %esp
        popl    %ebp
	ret			
/*******/


