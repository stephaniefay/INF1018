/*
int f (int x) { return x+2; }

void map2 (int* um, int * outro, int n) {
  int i;
  for (i=0; i<n; i++)
    *(outro+i) = f(*(um+i));
}
*/

.data

.globl map2, f

f:

	pushq	%rbp
	movq	%rsp, %rbp

	addl	$2, %edi
	movl	%edi, %eax

	leave
	ret

map2:

	pushq	%rbp
	movq	%rsp, %rbp

	movl	$0, %ecx

L1:	cmpl	%ecx, %edx
	je	L2

	addq	%ecx, %rdi
	call 	f
	addq	%ecx, %rsi
	movl	%eax, (%rsi)

	addl	$1, %ecx
	jmp	L1
L2:
		
	leave
	ret
