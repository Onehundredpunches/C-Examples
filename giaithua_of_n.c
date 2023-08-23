#include <stdio.h>

unsigned long long int Factorial(long long int n)
{
    unsigned long long int F = 1;
    unsigned long long int i;
    for ( i = 1; i <= n; i++)
    {
        F = F * i;
    }

    return F;
}

int main()
{
    printf("%d", Factorial(30));

    return 0;
}

/*
#include <stdio.h>

unsigned long long int factorial(unsigned int i) {

   if(i <= 1) {
      return 1;
   }
   return i * factorial(i - 1);
}

int  main() {
   int i = 30;
   printf("Factorial of %d is %d\n", i, factorial(i));
   return 0;
}
*/