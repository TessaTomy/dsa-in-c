#include <stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack* next;
}; 

typedef struct stack* s;

s createNode()
{
    s nnode=malloc(sizeof(struct stack));
    printf("Data :");
    scanf("%d",&nnode->data);
    return nnode;
}

void push(s* tos)
{
    s dummy;
    dummy=createNode();
    dummy->next=*tos;
    *tos=dummy;
}

int empty(s tos)
{
    if(!tos)
    {
        printf("Empty Stack !!\n");
        return 1;
    }
    return 0;
}
void pop(s* tos)
{
    if(empty(*tos))
        printf("Underflow !!\n");
    else
    {
        printf("%d Poped !!",(*tos)->data);
        *tos=(*tos)->next;
    }
}

void traverse(s tos)
{
    for(s temp=tos;temp!=NULL;temp=temp->next)
        printf("%d -> ",temp->data);
    printf("NULL\n");
}

void peek(s tos)
{
    if (empty(tos))
        return;
    else
        printf("TOS = %d",tos->data);
}

int main() {
    
    s tos=NULL;
    int c;
    while(1)
    {
        printf("\n====================\nEnter Your Choice\n1.Push\n2.Pop\n3.Peek\n4.Traverse\n?:");
        scanf("%d",&c);
        printf("====================\n");
        switch(c)
        {
            case 1:push(&tos);
                break;
            case 2:pop(&tos);
                break;
            case 3:peek(tos);
                break;
            case 4:traverse(tos);
                break;
            default:exit(0);
        }
    }
    return 0;
}
