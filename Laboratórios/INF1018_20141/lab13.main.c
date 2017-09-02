#include <stdio.h>
#include <math.h>

#define getsig(x)        ((x)>>31 & 1)
#define getexp(x)        ((x)>>23 & 0xff)
#define getfrac(x)       ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union {
  float f;
  unsigned int i;
} U;


float int2float(int i);
int float2int(float f);

int main() {
   int i;
   float f;

   printf("\n******** int2float ****************\n");
   i = 0;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 1;  
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -1;  
   printf(" %d -> %10.4f\n", i, int2float(i));
   i = 0x7fffffff;  
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -i;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));

   printf("\n******** float2int ****************\n");
   f = 0.0;  
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 1.0;  
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = -1.0;  
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 12345.0;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = -12345.0;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 1.5;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 2.5;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 2.4;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 0.5;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = (float) pow(2,31);
   printf(" %+10.4f (2^31) = overflow -> %d\n", f, float2int(f));
   f = -f;
   printf(" %+10.4f (-2^31) -> %d\n", f, float2int(f));
   f = (float) pow(2,32);
   f = -f;
   printf(" %+10.4f (-2^32 = overflow) -> %d\n", f, float2int(f));

   return 0;
}

