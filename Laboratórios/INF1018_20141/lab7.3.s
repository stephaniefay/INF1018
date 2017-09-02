/*
#include <stdio.h>

char S2[] = {65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0};

int main (void) {
  char *pc = S2;
  int contador = 0;

  while (*pc){
	contador++;
	*pc++;
}

  printf("%d \n",contador);
  return 0;

*/

.data
S2:	.byte 65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0

Sg:   .string "%d " 
Sh:   .string "\n"

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
        push    %ebp
        movl    %esp, %ebp
	pushl	%ebx		/* salva ebx */
/*******/

	movl 	$0, %ebx
	movl	$S2, %ecx	/* ecx = &S2; */
L1:	cmpb	$0, (%ecx)	/* while(*pc) */
	je	L2		/* goto L2 */
	addl	$1, %ebx
	addl	$1, %ecx	/* ecx += 4; */
	jmp	L1		/* goto L1; */
L2:	mov	%ebx, %eax	/* eax = *ecx; */

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


