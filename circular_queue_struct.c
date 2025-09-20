#include <stdio.h>

#define MAX 3

typedef struct{
    int data[MAX],f,r;
}Queue;

int isFull(Queue ** q)
{
    return ((*q)->f==((*q)->r+1)%MAX)?1:0;
}

int isEmpty(Queue * q)
{
    return (q->f==-1)?1:0;
}
void nq(Queue *q)
{
    if(isFull(&q))
    {
        printf("Overflow !!");
    }
    else
    {
        if(q->f==-1)
            q->f=0;
        printf("Data :");
        q->r=(q->r+1)%MAX;
        scanf("%d",&q->data[q->r]);
    }
}

void dq(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue Empty !!");
    }
    else
    {
        if(q->f==q->r)
            q->f=q->r=-1;
        else
            q->f=(q->f+1)%MAX;
    }
}

void peek(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue Empty !!");
    }
    else
    {
        printf("%d ",q->data[q->r]);
    }
}

void traverse(Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue Empty !!");
    }
    else
    {
        int i=q->f;
        while(1)
        {
            printf("%d ",q->data[i]);
            if(i==q->r)
                break;
            i=(i+1)%MAX;
        }
    }
}
void main()
{
    Queue q={.f=-1,.r=-1};
    int c;
    while(1)
    {
        printf("\n====================\nEnter Your Choice\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Traverse\n5.Exit?:");
        scanf("%d",&c);
        printf("====================\n");
        switch(c)
        {
            case 1:nq(&q);
                break;
            case 2:dq(&q);
                break;
            case 3:peek(&q);
                break;
            case 4:traverse(&q);
                break;
            case 5:printf("Program Terminated !!");
                    return;
            default:printf("Enter a Valid Choice !!");
        }
    }

}
