// Prim’s Algorithm — Minimum Spanning Tree via adjacency matrix
// Input: 0 denotes no edge; symmetric matrix assumed
// Output: edge trace and total cost

#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX 20

int main() {
    int a[MAX][MAX], visited[MAX] = {0}, n;
    int total = 0, edges_made = 0;

    printf("Enter total number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = INF;
        }

    // Begin MST construction from vertex 0
    visited[0] = 1;

    printf("\n--- Prim's Algorithm: Minimum Spanning Tree ---\n");
    printf("Selected edges:\n");

    // Loop until MST includes exactly (n - 1) edges
    while(edges_made<n-1)
    {
        int u=-1,v=-1,min=INF;
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!visited[j]&&a[i][j]<min)
                    {
                        u=i,v=j,min=a[i][j];
                    }
                }
            }
        }
        
        if(v!=-1)
        {
            visited[v]=1;
            total+=min;
            printf("Edge : (%d , %d) Cost: %d\n",u,v,min);
            edges_made++;
        }
    }

    printf("Total Cost = %d\n", total);
    return 0;
}
