// Design and implement C/C++ Program to solve discrete knapsack and continuous knapsack problems using greedy approximation method.
#include <stdio.h>

int n, m, p[10], w[10];

void greedy_knapsack() {
    float max, profit = 0;
    int i, j, k = 0;
    
    printf("Items included is:\n");
    for (i = 0; i < n; i++) {
        max = 0;
        for (j = 0; j < n; j++) {
            if ((float)p[j] / w[j] > max) {
                k = j;
                max = (float)p[j] / w[j];
            }
        }
        
        if (w[k] <= m) {
            printf("Item %d\n", k);
            m = m - w[k];
            profit += p[k];
            p[k] = 0;
        } else {
            break;
        }
    }
    
    printf("Total profit is %f\n", profit);
    printf("Continuous knapsack also include item %d with fraction: %f\n", k, (float)m / w[k]);
    profit = profit + ((float)m / w[k]) * p[k];
    printf("Continuous knapsack profit is = %f\n", profit);
}

int main() {
    int i;
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    printf("Enter weights of items: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    
    // Note: The handwritten main function missed asking for prices input.
    // Added here so the values exist for p[j] calculations to avoid trash values.
    printf("Enter profits/prices of items: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("Enter capacity of knapsack: ");
    scanf("%d", &m);
    
    greedy_knapsack();
    return 0;
}

/*
Enter profits/prices of items: 12 10 20 15
Enter capacity of knapsack: 5
Items included is:
Item 1
Item 3
Total profit is 25.000000
Continuous knapsack also include item 2 with fraction: 0.666667
Continuous knapsack profit is = 38.333332
*/