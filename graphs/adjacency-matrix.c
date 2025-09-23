#include <stdio.h>
#define v 10

int g[v][v];

int main() {
    int n,c=1,v1,v2,w;
    printf("Enter Number of vertices in your graph : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            g[i][j]=0;
    }
    while(c)
    {
        printf("Enter vertices and weight (eg: v1 v2 weight) : ");
        scanf("%d %d %d",&v1,&v2,&w);
        if (v1 >= n || v2 >= n || v1 < 0 || v2 < 0) {
            printf("Invalid vertices. Try again.\n");
            continue;
        }
        g[v1][v2]=g[v2][v1]=w;
        printf("Wanna add another edge (0/1): ");
        scanf("%d",&c);
    }
    
    printf("\nAdjacency Matrix:\n   ");
    //to print column label
    for (int i = 0; i < n; i++) printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < n; i++) {
        
        printf("%2d ", i); //row labels
        
        for (int j = 0; j < n; j++) {
            printf("%2d ", g[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}
