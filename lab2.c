// Design & Implement C/C++ Program to find Minimum Cost Spanning Tree of a given connected graph using Prim's algorithm.
#include <stdio.h>

int cost[10][10], n;

void prim() {
    int vt[10] = {0};
    int a = 0, b = 0, min, mincost = 0, ne = 0;
    
    vt[0] = 1;
    while (ne < n - 1) {
        min = 999;
        for (int i = 0; i < n; i++) {
            if (vt[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (cost[i][j] < min && vt[j] == 0) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        
        printf("Edge from vertex %d to vertex %d and the cost = %d \n", a, b, min);
        vt[b] = 1;
        ne++;
        mincost += min;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("The minimum spanning tree cost is %d \n", mincost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    prim();
    return 0;
}

/*
Enter the number of vertices: 4
Enter the cost adjacency matrix: 
0 10 20 999
10 0 5 15
20 5 0 12
999 15 12 0
Edge from vertex 0 to vertex 1 and the cost = 10 
Edge from vertex 1 to vertex 2 and the cost = 5 
Edge from vertex 2 to vertex 3 and the cost = 12 
The minimum spanning tree cost is 27 
*/