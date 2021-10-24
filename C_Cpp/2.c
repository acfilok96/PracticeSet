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
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

#define key  10
node* Hash_table[key];


void Insert_element()
{
    int n;
    printf("\nenter element: ");
    scanf("%d",&n);
    int p=n%key;
    node *tempo = Hash_table[p];
    while(tempo->next!=NULL)
    {
        tempo=tempo->next;
    }
    node *temp=(node* )malloc(sizeof(node));
    temp->data=n;
    temp->next=NULL;
    tempo->next=temp;
    return;
}


void Show_table()
{
    int arr[10];
    for(int i=0;i<key;i++)
    {
        arr[i]=0;
    }
    for(int i=0;i<key;i++)
    {
        node *tempo=Hash_table[i]->next;
        while(tempo!=NULL)
        {
            arr[i]=arr[i]+1;
            tempo = tempo->next;
        }
    }
    printf("\n");
    int p=0;
    for(int i=0;i<key;i++)
    {
        if(arr[i]!=0)
        {
            p=arr[i];
            break;
        }
    }

    for(int i=0;i<key;i++)
    {
        if(arr[i]!=0)
        {
            if(p!=arr[i])
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
    for(int i=0;i<key;i++)
    {
        Hash_table[i]=(node *)malloc(sizeof(node));
        Hash_table[i]->data=8267225;
        Hash_table[i]->next=NULL;
    }

    int n;
    printf("Enter number of input: ");
    scanf("%d",&n);
    printf("Please enter the digit (0 to 9): \n");
    for(int i=0;i<n;i++)
    {
        Insert_element();
    }
    
    Show_table();
    return 0;
}

