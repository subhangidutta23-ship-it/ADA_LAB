// Design and implement C/C++ program to find the transitive closure using Warshal's algorithm.
#include <stdio.h>

void warshal(int a[][10], int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}

int main() {
    int n, adj[10][10];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    warshal(adj, n);
    
    printf("Transitive closure of the given graph is \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
Enter number of vertices: 4
Enter the adjacency matrix 
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
Transitive closure of the given graph is 
1 1 1 1 
1 1 1 1 
0 0 0 0 
1 1 1 1 
*/