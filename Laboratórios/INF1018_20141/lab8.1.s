/* #include <stdlib.h>
  int main() {
    system("ls -ls");
    return 0;
  }
*/

.data

s1: .string "ls -ls"
.text
.globl main
	
main:
	/* prologo */
	pushl	%ebp
	movl	%esp, %ebp

	movl	$s1, %eax

	
        pushl   %eax
        pushl   $s1
 	call	system	
        addl    $8, %esp


	/* finalizacao */
	movl	%ebp, %esp
	popl	%ebp
	ret
