#include"NumClass.h"
#include <math.h>
#include <stdio.h>
int lengthN(int n);


int lengthN(int n)
{
    int count = 0;
    while (n!=0)
    {
        n /=10;
        count++;
    }
    return count;
}
int isArmStrong(int n)
{
    int sum = 0;
    int copyN = n;
    int length = lengthN(n);
    while (copyN>0)
    {
        sum+= pow(copyN%10,length);
        copyN /=10;
    }
    if (sum == n)
    {
        return 1;
    }
    return 0;
}
int isPalindrome(int n)
{
    int reverse = 0;
    int temp = n;
    int length = lengthN(n);
    for (int i = 0; i < lengthN(n); i++)
    {
        reverse += (temp%10) * pow(10,length-i-1);
        temp = temp/10; 
    }
    if (n==reverse)
    {
        return 1;
    }
    return 0;
    
}
