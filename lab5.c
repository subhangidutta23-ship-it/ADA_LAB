// Design and implement C/C++ Program to obtain the Topological ordering of vertices in a given digraph.
#include <stdio.h>

int cost[10][10], n, colsum[10];

void cal_colsum() {
    for (int j = 0; j < n; j++) {
        colsum[j] = 0;
        for (int i = 0; i < n; i++) {
            colsum[j] += cost[i][j];
        }
    }
}

void source_removal() {
    int i, j, k, select[10] = {0};
    printf("Topological order of vertices: \n");
    for (i = 0; i < n; i++) {
        cal_colsum();
        for (j = 0; j < n; j++) {
            if (colsum[j] == 0 && select[j] == 0) { // Found a source vertex
                printf("%d ", j);
                select[j] = 1; // Mark this vertex as selected
                for (k = 0; k < n; k++) {
                    cost[j][k] = 0; // Remove outgoing edges from this
                }
                break; // Break to recalculate column sums after removing edges
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge): \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    source_removal();
    return 0;
}

/*
Enter the number of vertices: 5
Enter the adjacency matrix (use 1 for edge, 0 for no edge): 
0 1 0 1 0
0 0 1 1 0
0 0 0 0 0
0 0 1 0 1
0 0 0 0 0
Topological order of vertices: 
0 1 3 2 4 
*/