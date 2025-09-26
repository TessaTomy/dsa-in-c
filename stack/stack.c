#include<stdio.h>
#define MAX 3

int top=-1;
int stack[MAX];

void push()
{
    if(top==MAX-1)
    {
        printf("Stack Overflow !!");
        return;
    }
    printf("Data :");
    scanf("%d",&stack[++top]);
    printf("%d Pushed to Stack !!",stack[top]);
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow !!");
        return;
    }
    else
    {
        printf("%d Poped from stack !!",stack[top--]);
    }
}

void traverse()
{
    for(int i=top;i>=0;printf("%d->",stack[i]),i--);
}

void main()
{
    for(;;)
    {
        int c;
        printf("\n=====================\n1.Push\n2.Pop\n3.Peek\n4.Traverse\n5.Exit\n>>");
        scanf("%d",&c);
        if(c==1)
            push();
        else if(c==2)
            pop();
        else if(c==3)
            printf("TOS = %d",stack[top]);
        else if(c==4)
            traverse();
        else
            return;
    }
}
