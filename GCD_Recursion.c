#include<stdio.h>

int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}

int fact_recursive(int num)
{
  if (num == 0)		// Base case for recursion.
    return 1;     // fact() return 1 if argument is 0
  else
    return num * fact_recursive(num-1);      // Call recursively with lesser number.
}
int main()
{
  int number, fact1;
  int num1, num2;
  number = 5;
  fact1 = fact_recursive(number);        // Call the Recursive version
  printf("Number=%d\n", number);
  printf("Recursive_Factorial=%d\n", fact1);

  num1= 4;
  num2 = 12;
  printf("GCD of %d & %d = %d\n", num1, num2, gcd(num1, num2));
  printf("Number=%d\n", 4%12);
  return 0;
}

