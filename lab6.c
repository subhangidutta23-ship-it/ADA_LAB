// Design and implement C/C++ Program to solve 0/1 Knapsack problem using Dynamic Programming method.
#include <stdio.h>

int n, m, p[10], w[10];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack_DP() {
    int v[10][10], i, j;
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j < w[i]) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }
    
    // Printing the dynamic programming table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    
    // Backtracking to find the items included
    printf("Items included in the knapsack:\n");
    while (n > 0) {
        if (v[n][m] != v[n - 1][m]) {
            printf("Item %d \n", n);
            m = m - w[n];
        }
        n--;
    }
}

int main() {
    int i;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    printf("Enter weights of items: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    
    printf("Enter prices of items: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);
    
    knapsack_DP();
    
    return 0;
}

/*
Enter number of items: 4
Enter weights of items: 7 3 4 5
Enter prices of items: 42 12 40 25
Enter capacity of knapsack: 10 
0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 42 42 42 0 
0 0 0 12 12 12 12 42 42 42 0 
0 0 0 12 40 40 40 52 52 52 0 
0 0 0 12 40 40 40 52 52 65 65 
Items included in the knapsack:
Item 4 
Item 3 
*/