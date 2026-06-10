// Design and implement C/C++ program to find All-Pairs Shortest Paths problem using Floyd's algorithm.
#include <stdio.h>

int min(int a, int b) {
    return (a < b ? a : b);
}

void floyd(int d[][10], int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != 999 && d[k][j] != 999) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, cost[10][10];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            
            // Converts 0 to 999 automatically if it's not a self-loop
            if (i != j && cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }
    
    floyd(cost, n);
    
    printf("\nAll pair shortest path:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

/*
Enter number of vertices: 4
Enter the cost matrix:
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0

All pair shortest path:
0       1       3       2
2       0       2       1
999     999     0       999
1       2       1       0
*/