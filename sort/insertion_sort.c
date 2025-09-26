#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n ; i++) {
        int j,key=arr[i];
        for(j=i-1;key<arr[j]&&j>=0;j--)
            arr[j+1]=arr[j];
        arr[j+1]=key;
    }
}

void readArray(int *arr, int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);  

    printf("Enter %d elements:\n", *n); 
    for (int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main() {
    int arr[100], n;
    readArray(arr,&n);
    
    insertionSort(arr, n);

    printf("Sorted array: ");
    display(arr, n);
}
