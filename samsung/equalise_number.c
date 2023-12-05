/*
Given three inputs A B and N.
You can do any one of the following operations.
Increment A by B 
Increment B by A

Return the min number of increments to make A or B greater than N.
Sample1:
Input:
4 4 16
output:
3

Sample2:
Input:
1 2 3
Output:
2

*/

#include<stdio.h>

int equalise(int a,int b, int n)
{
    int count = 0;
    while(a <= n)
    {
        a = a+b;
        count++;
    }
    return count;
}

int main()
{
    int A, B, N;
    scanf("%d%d%d", &A, &B, &N);

    int count1 = 0, count2 = 0, res;
    
    if(A > B || A < B)
    {
        count1 = equalise(A, B, N);
        count2 = equalise(B, A, N);
        if(count1 > count2)
        {
            res = count2;
        }
        else{
            res = count1;
        }
    }
    else if(A == B)
    {
        count1 = equalise(A, B, N);
        res = count1 - 1;
    }
    printf("%d\n", res);
}