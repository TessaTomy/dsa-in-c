#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// To represent each node
typedef struct Node {
    int v;
    struct Node* next;
} Node;

// adjaceny list 
typedef struct {
    int vCount;
    Node* adj[MAX];
} Graph;

// as its undirected graph create as assign node bidirectionly
void addEdge(int v1,int v2,Graph* g)
{
    Node* nnode=malloc(sizeof(Node));
    nnode->v=v2;
    nnode->next=g->adj[v1];
    g->adj[v1]=nnode;
    
    Node* nnode2=malloc(sizeof(Node));
    nnode2->v=v1;
    nnode2->next=g->adj[v2];
    g->adj[v2]=nnode2;
}

// create adjacency list
Graph* read()
{
    int v1,v2;
    Graph* g=malloc(sizeof(Graph));
    printf("Total Number of Vertices :");
    scanf("%d",&g->vCount);
    for(int i=0;i<g->vCount;i++)
        g->adj[i]=NULL;
    int c=1;
    while(c==1)
    {
        printf("Enter the Edge to add (v1 v2) : ");
        scanf("%d %d",&v1,&v2);
        addEdge(v1,v2,g);
        printf("Wanna Continue (0/1):");
        scanf("%d",&c);
    }
    return g;
}

// display method
void print(Graph* g)
{
    for(int i=0;i<g->vCount;i++,printf("\n"))
    {
        printf("%d ->",i);
        for(Node* temp=g->adj[i];temp!=NULL;temp=temp->next)
            printf("%d ->",temp->v);
    }
}
void main()
{
    Graph* g=read();
    print(g);
}
