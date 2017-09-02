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

	pushq %rbp
	movq  %rsp, %rbp

	movq $s1, %rdi
	
	call system
  

	leave
	ret
