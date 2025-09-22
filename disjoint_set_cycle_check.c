#include <stdio.h>
#define MAX 10

int parent[MAX];

void makeSet(int n)
{
    for(int i=0;i<n;i++)
        parent[i]=i;
}

int find(int u)
{
    if(parent[u]!=u)
        parent[u]=find(parent[u]);
    return parent[u];
}

void unionn(int u,int v)
{
    int parent_u=find(u);
    int parent_v=find(v);
    if(parent_u==parent_v)
        printf("Cannot merge both as it leads to a cycle !!\n");
    else
    {
        printf("Edge (%d,%d) formed !!\n",u,v);
        parent[parent_u]=parent_v;
    }
}

void display(int n)
{
    printf("Node : Representative\n");
    for(int i=0;i<n;i++)
    {
        printf("%d   :   %d\n",i,find(i));
    }
}

int main() {
    
    int n,count,u,v;
    printf("Enter Number of Elments : ");
    scanf("%d",&n);
    makeSet(n);
    printf("Enter number of union operations to perform :");
    scanf("%d",&count);
    for(int i=0;i<count;i++)
    {
        printf("\nEnter the edge pair (eg: u v) : ");
        scanf("%d %d",&u,&v);
        unionn(u,v);
    }
    display(n);
    return 0;
}
