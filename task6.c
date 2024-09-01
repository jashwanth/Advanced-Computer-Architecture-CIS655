#include <stdio.h>
int main()
{
  unsigned long a = 0;
  unsigned long b = 0;
  asm volatile ("lea (%%rip), %0\n\t"
		  "lea (%%rip), %1\n\t"
		  :"=r"(a),"=r"(b) /* output */
		  : /* input */
		  :"%eax" /* clobbered register */
	       );
//  printf("b = %lx, a = %lx size of unsigned long = %lu\n", b, a, sizeof(unsigned long));
  printf("b-a=%ld\n",b-a);
  asm volatile ("lea (%%rip), %0\n\t"
		  "nop\n\t"
		  "lea (%%rip), %1\n\t"
		  :"=r"(a),"=r"(b) /* output */
		  : /* input */
		  :"%eax" /* clobbered register */
	       );
//  printf("b = %ld, a = %ld", b, a);
  printf("b-a=%ld\n",b-a);
  return 0;
}
