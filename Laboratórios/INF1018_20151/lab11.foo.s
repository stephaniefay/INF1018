/*
float foo (double a, float b) {
  return (a+b)*(a-b);
}
*/
.text

.globl foo

foo:

push %ebp
movl %esp, %ebp

flds 16(%ebp)
fldl  8(%ebp)
fsubp

flds 16(%ebp)
fldl  8(%ebp)
faddp

fmulp


movl %ebp, %esp
popl %ebp
ret

