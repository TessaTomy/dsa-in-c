#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct Node{
    int v;
    struct Node* next;
}node;

node* adj_list[MAX];

void initialize(int n)
{
    for(int i=0;i<n;i++)
        adj_list[i]=NULL;
}

void create(int v1,int v2)
{
    node* nnode=malloc(sizeof(node));
    nnode->v=v2;
    nnode->next=adj_list[v1];
    adj_list[v1]=nnode;
    
    nnode=malloc(sizeof(node));
    nnode->v=v1;
    nnode->next=adj_list[v2];
    adj_list[v2]=nnode;
    
}

void display(int n)
{
    for(int i=0;i<n;i++,printf("\n"))
    {
        printf("%d->",i);
        for(node* temp=adj_list[i];temp!=NULL;temp=temp->next)
            printf("%d->",temp->v);
    }
}

void dfs(int start,int n)
{
    int visited[MAX]={0},stack[MAX],top=-1;
    visited[start]=1;
    stack[++top]=start;
    while(top!=-1)
    {
        int v=stack[top--];
        printf("%d->",v);
        for(node* temp=adj_list[v];temp!=NULL;temp=temp->next)
        {
            if(!visited[temp->v])
            {
                visited[temp->v]=1;
                stack[++top]=temp->v;
            }
        }
    }
}

void main()
{
    int n,v1,v2,w,c;
    printf("Total Number of Nodes :");
    scanf("%d",&n);
    initialize(n);
    while(1)
    {
        printf("Enter the edge to add (v1,v2) : ");
        scanf("%d %d",&v1,&v2);
        if(v1>=n||v2>=n)
            continue;
        create(v1,v2);
        printf("Press 0 to stop : ");
        scanf("%d",&c);
        if(c==0)
            break;
    }
    
    display(n);
    printf("=================\n");
    dfs(0,n);
}
