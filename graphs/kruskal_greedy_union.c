/* KRUSKAL'S ALGORITHM — MINIMUM SPANNING TREE
   --------------------------------------------
   Builds MST from a weighted adjacency matrix.
   Uses greedy edge selection and union-find with path compression.
   Skips cycles, logs edges, tracks total cost.

   Input  : adjacency matrix (0 → INT_MAX)
   Output : MST edges + total cost

   Steps:
     1. Replace 0s with ∞ to ignore missing edges
     2. While MST has < n - 1 edges:
        - Find min edge across disjoint sets
        - Merge sets, log edge, update cost
*/

#include<stdio.h>
#include<limits.h>

#define MAX 20

int parent[MAX];

int find(int i)
{
    if(parent[i]!=i)
        parent[i]=find(parent[i]);
    return parent[i];
}

void main()
{
    int a[MAX][MAX],n;
    // variables to implement kruskal
    int edges=0,u,v,min,mincost=0;
    printf("Enter total number of vertices :");
    scanf("%d",&n);
    //create n disjoint set
    for(int i=0;i<n;i++)
            parent[i]=i;
    // accept the adjaceny matrix
    printf("Enter the adjacency matrix :\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                a[i][j]=INT_MAX;
        }
        
    printf("-----Kruskals-----\n");
    while(edges<n-1)
    {
        u=v=-1,min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]<min&&find(i)!=find(j))
                {
                    u=i,v=j,min=a[i][j];
                }
            }
        }
        
        if(u!=-1)
        {
            //union
            parent[find(u)]=find(v);
            printf("Edge %d -- (%d,%d) : %d\n",++edges,u,v,min);
            mincost+=min;
        }
    }
    
    printf("------------------\nMincost = %d",mincost);
}
