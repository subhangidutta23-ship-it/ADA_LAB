// Design and implement C/C++ Program to sort a given set of $n$ integers elements using Selection Sort method and compute its time complexity. Run the program for varied values of $n > 5000$ and record the time taken to sort. Plot a graph of the time taken versus $n$. The elements can be read from a file or can be generated using the random number generator.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Selection sort
void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; ++i){
        int minIndex = i;
        for(int j = i + 1; j < n; ++j){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        // Swap the found min element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void generaterandomnumbers(int arr[], int n){
    srand(time(0));  // Seed the random number generator
    for(int i = 0; i < n; ++i){
        arr[i] = rand() % 10000;  // Generate random numbers b/w 0 & 9999
    }
}

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    
    if (n <= 5000) {
        printf("Please enter a value greater than 5000.\n");
        return 1;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    generaterandomnumbers(arr, n);
    
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();
    
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Time taken to sort %d elements: %f seconds \n", n, timeTaken);
    
    free(arr);
    return 0;
}