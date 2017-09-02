/* #include <stdio.h>
#define LIM 1

int filtro(int x, int lim);

int nums[5] = {3,-5,7,8,-2};

int main() {
  int i;
  int *p = nums;
  for (i = 0; i < 5; i++) {
    printf("%d\n", filtro(*p,LIM));
    p++;
  }
  return 0;
}

*/

.data
nums: .int 3, -5, 7, 8, -2
s1:   .string "%d\n"

.text
.globl main
main:
	/* prologo */
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx	
	pushl	%edx

	movl	$nums, %ebx	/* ecx = nums */
	movl	$0, %edx	/* contador */

L1:	cmpl	$5, %edx	/* contador < 5 */
	je	L2

	push	%edx		/* salva contador */
	pushl	$1		/* MAX */
	pushl	(%ebx)		/* num */
	call	filtro		/* chama func */
	addl	$8, %esp	/* se livra dos parametros */
	pushl	%eax		/* push o resultado da filtro */
	pushl	$s1		/* push o tipo de string pra printar */
	call	printf		/* chama printf */
	addl	$8, %esp	/* se livra dos parametros */
	popl	%edx		/* recupera contador */

	addl	$4, %ebx	/* vai para o proximo valor */
	addl	$1, %edx	/* contador++ */
	jmp	L1		/* goto L1; */

L2:	/* finalizacao */
	popl	%edx
	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
