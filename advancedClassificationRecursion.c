    #include"NumClass.h"
    #include<math.h>
    #include<stdio.h>

int isPalindrome2(int n,int length);
int isArmStrong2(int n,int length);
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


int isPalindrome2(int n,int length)
{
    if (n>0)
    {
       return (n%10) * pow(10,length-1) + isPalindrome2(n/10,length-1);
    }
    return 0;
}
int isPalindrome(int n)
{   
    int length = lengthN(n);
    int reserve = isPalindrome2(n,length);
    if (reserve == n)
    {
        return 1;
    }
    return 0;
}

int isArmStrong(int n)
{
    int sum = isArmStrong2(n,lengthN(n));
    if (sum == n)
    {
        return 1;
    }
    return 0;
    
}
 int isArmStrong2(int n,int length)
 {
    if (n>0)
    { 
        int return1 = isArmStrong2(n/10,length) + pow(n%10,length);
        return return1;
    }
    return 0;
 }