/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.


Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].

Input: deck = [1,1,1,2,2,2,3,3]
Output: false


Contraints:
1 <= deck.length <= 10^4
0 <= deck[i] < 10^4
*/

#include<stdio.h>

int max_function(int arr[], int n)
{
    int p=arr[0];
    for(int i=1;i<n;i++)
    {
        if(p<arr[i])
        {
            p=arr[i];
        }
    }
    return p;
}


void main_function(int arr[], int n)
{
    int p=max_function(arr,n)+1;
    int b_array[p];
    for(int i=0;i<p;i++)
    {
        b_array[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        b_array[arr[i]]= b_array[arr[i]] + 1;
    }
    printf("\n");
    
    int flag=max_function(b_array,p);
    for(int i=0;i<p;i++)
    {
        if(b_array[i]!=0)
        {
            if(flag!=b_array[i])
            {
                printf("False\n");
                return;
            }
        }
    }
    printf("True\n");
    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("\n\n");
    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    main_function(array,n);
    return 0;
}