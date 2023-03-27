#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

int main()
{
    struct ListNode *l1;
    struct ListNode *l2;
    printf("Enter List 1: ");

    int option;

    switch (option)
    {
    case 1:
        insertList()
        break;
    
    default:
        break;
    }

    
}


void insertList(struct ListNode **l,int data)
{
    struct ListNode *new_node;
    new_node->val = data;
    new_node->next =NULL;
}