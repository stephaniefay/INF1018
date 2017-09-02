/*
struct X {
  int val;
  struct X *next;
};

int add (struct X *x) {
  int a = 0;
  for (; x != NULL; x = x->next)
    a += x->val;
  return a;
}
*/

.data

.globl add
add:

	pushq %rbp
	movq  %rsp, %rbp
	
	movl $0, %eax
	
L1:	cmpq $0, %rdi
	je L2

	addl (%rdi), %eax
	movq 8(%rdi), %rdi
	jmp L1

L2:	
	leave
	ret
