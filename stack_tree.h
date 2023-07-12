#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;


typedef struct StackNode{
    Node node;
    struct StackNode* link;
}StackNode;

typedef struct {
    StackNode* head;
    int size;
}LinkedListStack;

LinkedListStack newLinkedListStack(LinkedListStack linkedliststack)
{
    linkedliststack.head = (StackNode*)malloc(sizeof(StackNode));
    linkedliststack.size = 0;
    linkedliststack.head->link = NULL;
    
    return linkedliststack;
}

int sizeLinkedListStack(LinkedListStack linkedliststack)
{
    return linkedliststack.size;
}

int topLinkedListStack(LinkedListStack linkedliststack)
{
    return linkedliststack.head->node.data;
}

LinkedListStack pushLinkedListStack(LinkedListStack linkedliststack, Node _node)
{
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    temp->node = _node;
    temp->link = linkedliststack.head;
    linkedliststack.size = linkedliststack.size + 1;
    linkedliststack.head = temp;
    return linkedliststack;
}

LinkedListStack popLinkedListStack(LinkedListStack linkedliststack)
{
    if (linkedliststack.size == 0)
    {
        printf("\nlinked list queue is empty in pushLinkedListStack");
        exit(1);
    }
    else{
    StackNode* temp = linkedliststack.head;
    linkedliststack.head = linkedliststack.head->link;
    linkedliststack.size = linkedliststack.size - 1;
    free(temp);
    }
    return linkedliststack;
}

LinkedListStack dropLinkedListStack(LinkedListStack linkedliststack)
{
    StackNode * temp = linkedliststack.head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(linkedliststack.head);
        linkedliststack.head = temp;
    }
    linkedliststack.size = 0;
    return linkedliststack;
}

void displayLinkedListStack(LinkedListStack linkedliststack)
{
    printf("\nTOP");
    LinkedListStack temp = linkedliststack;
    for (int i = 0; i < linkedliststack.size; i++)
    {
        printf("->%i", temp.head->node.data);
        temp.head = temp.head->link;
    }
    
}