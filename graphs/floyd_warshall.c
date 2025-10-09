/*
 * Description : Implementation of Floyd-Warshall algorithm for all-pairs shortest paths.
 *               Accepts a cost matrix and replaces zero-cost non-diagonal entries with INF.
 *               Iteratively updates shortest paths using each vertex as an intermediate.
*/

#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

#define v 10

int g[v][v];

int main() {
    int n;
    printf("Enter Number of vertices in your graph : ");
    scanf("%d",&n);
    
    printf("\nEnter the cost Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                scanf("%d",&g[i][j]);
                if(i!=j&&!g[i][j])
                    g[i][j]=INF;
            }
        g[i][i]=0;
    }
    
    //Floyd Warshall algorithm logic
    
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                {
                    if(g[i][k]<INF&&g[k][j]<INF&&g[i][j]>g[i][k]+g[k][j])
                        g[i][j]=g[i][k]+g[k][j];
                }
     

    printf("\nAll Pair Shortest path :\n--------------------------\n");
    for(int i=0;i<n;printf(" %5d",i),i++);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d",i);
        for (int j = 0; j < n; j++) {
            printf("%5d ", g[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
