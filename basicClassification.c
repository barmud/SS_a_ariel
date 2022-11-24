#include"NumClass.h"
//#include<math.h>

int factorial(int n)
{
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum*= i;
    }
    return sum;
}
int isPrime(int n)
{
    //0 isn't prime number
    if (n==0)
    {
        return 0;
    }
    for (int i = 2; i <= n/2; i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
    }
    return 1;
    
}
int isStrong(int n)
{
    //0! == 1 - 0 isn't strong number
    if (n==0)
    {
        return 0;
    }
    int sum = 0;
    int copyN = n;
    while (copyN>0)
    {
        sum+= factorial(copyN%10);
        copyN /=10;
    }
    if (sum == n)
    {
        return 1;
    }
    return 0;
}
