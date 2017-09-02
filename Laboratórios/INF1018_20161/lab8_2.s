/*
#include <stdio.h>
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
	pushq %rbp
	movq  %rsp, %rbp
	subq  $16, %rsp
	movq  %rbx, -8(%rbp)
	movq  %r12, -16(%rbp)

	movq $nums, %rbx
	movq $0, %r12

L1:	cmpq $5, %r12
	je L2

	movq (%rbx), %rdi
	movq $1, %rsi
	call filtro

	movq $s1, %rdi
	movq %rax, %rsi
	movl $0, %eax
	call printf

	addq $4, %rbx
	addq $1, %r12
	jmp L1
	
L2:	movq -8(%rbp), %rbx
	movq -16(%rbp), %r12
	leave
	ret
