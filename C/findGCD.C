//Here, we are using Euclid's algorithm to find Greatest Common Divisor or G.C.D of two numbers so that we can reduce them to lowest terms.

#include <stdio.h>
int gcd(int u, int v)
{
 int temp;
 while (u > 0)
 {
  if (u < v)
  {
   temp = u;
   u = v;
   v = temp;
  }
  u = u -v;
 }
 return v;
}

int main ()
{
 int number1, number2;
 while(scanf("%d, %d", &number1, &number2) != EOF)
  if(number1 > 0 && number2 > 0)
   printf ("%d %d %d \n", number1, number2, gcd(number1, number2));
   
 return 0;
}

  
 
