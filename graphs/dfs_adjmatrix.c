#include <stdio.h>
#define v 10

int g[v][v];

int main() {
    int n,c=1,v1,v2,w;
    printf("Enter Number of vertices in your graph : ");
    scanf("%d",&n);
    printf("Enter your adjaceny matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    
    //dfs logic starts here
    int start,visited[v]={0},stack[v],top=-1;
    printf("Enter start node : ");
    scanf("%d",&start);
    visited[start]=1;
    stack[++top]=start;
    while(top!=-1)
    {
        int current=stack[top--];
        printf("%d->",current);
        for(int i=0;i<n;i++)
        {
            if(g[current][i]==1&&!visited[i])
            {
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
    return 0;
}
