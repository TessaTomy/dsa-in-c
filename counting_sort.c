// NOTE : Only works with non-negative small datasets
#include <stdio.h>
#include <stdlib.h>

int findMax(int* a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) 
    { 
        if (max < a[i])
            max = a[i];
    }
    return max;
}

void countSort(int* a, int n) {
    int c[n];
    int size = findMax(a, n);
    int* b = malloc(sizeof(int) * (size + 1));

    if (b == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // initialize to 0
    for (int i = 0; i < size+1; i++) {
        b[i] = 0;
    }
    // get count
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }
    // cummulative count
    for (int i = 1; i < size+1; i++) {
        b[i] += b[i - 1];
    }
    // sorting logic right->left
    for (int i = n - 1; i >= 0; i--) {
        c[b[a[i]] - 1] = a[i];
        b[a[i]]--;
    }

    free(b);

    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
}

int main() {
    int a[100];
    int n = 0;
    int choice;
    while (1) {
        printf("\n----- Menu -----\n1. Enter array\n2. Display array\n3. Sort array using Counting Sort\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter %d elements:\n", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }
        }
        else if (choice == 2) {
            if (n == 0) {
                printf("Array is empty. Please enter array first.\n");
            } else {
                printf("Array elements: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
            }
        }
        else if (choice == 3) {
            if (n == 0) {
                printf("Array is empty. Please enter array first.\n");
            } else {
                printf("Sorted array: ");
                countSort(a, n);
                printf("\n");
            }
        }
        else if (choice == 4) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
