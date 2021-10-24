/*
Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].

Input:
N = 2
arr[] = {1,0}
Output: 0 1
Explanation: 
arr[arr[0]] = arr[1] = 0.
arr[arr[1]] = arr[0] = 1.

Input:
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1

Constraints:
1 <= N <= 10^7
0 <= Arr[i] < N
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int max;

int *Function()
{
    int n;
    // printf("\nenter size of array: ");
    scanf("%d",&n);
    if(1<= n && n<= pow(10,7))
    {
        max=n;
        int array[n];
        // printf("enter the element of array:\n");
        int m=0;
        while(m!=n)
        {
            int ele;
            scanf("%d",&ele);
            if(ele<n)
            {
                array[m]=ele;
                m++;
            }
            // else
            // {
            //     printf("%d is greater or equal to %d\n",ele,n);
            // }
        }
        int *pk=(int *)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        {
            *(pk+i)=array[array[i]];
        }
        return pk;
    }
    else
    {
        // printf("Enter the valid n (1 <= N <= 10^7)");
        return Function();
    }

    
}

int main()
{
    int *p = Function();
    // printf("Print:- \n");
    for(int i=0;i<max;i++)
    {
        printf("%d\t",*(p+i));
    }
    free(p);
    return 0;
}