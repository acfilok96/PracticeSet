/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].


Input:
K = 4
arr[][]={{1,2,3,4}{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9

Constraints:
1 <= K <= 100

*/

#include<stdio.h>

int main()
{
    int k=2;
    int p=0;
    int array[k][k],list[k*k];
    for(int i=0;i<k;i++)
    {
        printf("enter %d array: \n",i+1);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&array[i][j]);
            list[p]=array[i][j];
            p=p+1;
        }
    }
    for(int i=0;i<(k*k)-1;i++)
    {
        for(int j=0;j<(k*k)-i-1;j++)
        {
            if(list[j]>list[j+1])
            {
                int temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
    printf("\n\n");
    for(int i=0;i<k*k;i++)
    {
        printf("%d\t",list[i]);
    }
    return 0;
}