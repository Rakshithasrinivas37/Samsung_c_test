/* 
Program to make sum of arr elemnts equals to zero
i/p : n , arr
where n -> size of array
arr -> input the array elements

explanation:
->if arr[] = {2,0,1,-1,0};
->find out the index i and value which is to be replaced at the particular position in array, such that sum of all elements in the array is equal to zero 
->here -2 should be placed at index 1 
so arr becomes => arr[] = {2,-2,1,-1,0}

arr[0] + arr[1] = 0
arr[0] + arr[1] + arr[2] + arr[3] = 0
arr[0] + arr[1] + arr[2] + arr[3] + arr[4] = 0

Output:
3

Sample2:
Input:
4
0 0 0 0

Ouput:
4
*/


#include <stdio.h>

int sum_arr(int *arr,int n); 
void change_index(int *arr,int n,int sum);
int check_arr(int *arr,int n);

int main()
{
    int arr[10];
    int n, res;

    scanf("%d",&n);
    
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    res = check_arr(arr,n);
    if(res == 0)
    printf("%d\n",res);
    else
    printf("%d\n",res);
    return 0;
}

int sum_arr(int *arr,int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

void change_index(int *arr,int n,int sum)
{
    arr[n - 1] = -sum;
}

int check_arr(int *arr,int n)
{
    int count=0, j=0,m=2,sum=0, total_sum = 0;
    int size = (n%2 == 0)?(n/2 - 1):n/2;
    
    while(count <= size)
    {
        if(m < n)
        {
            sum = sum_arr(arr, m - 1);
            change_index(arr, m, sum);
        }
        else{
            sum = sum_arr(arr, n - 1);
            change_index(arr, n, sum);
        }
        while(j < m && j < n)
        {
            total_sum = total_sum + arr[j]; 
            j++;
        }
        m = m + 2;
        j = 0;
        if(total_sum == 0)
        {
            count++;
        }
    }
    return count;
}