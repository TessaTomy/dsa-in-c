#include <stdio.h>

void linearSearch(int arr[], int n) {
    int target;
    printf("Element to search for ?: ");
    scanf("%d",&target);
    for (int i = 0; i < n ; i++) {
        if(arr[i]==target)
        {
            printf("%d found at Position - %d",target,i+1);
            return;
        }
    }
    printf("Element Not Found !!");
}

void readArray(int *arr, int *n) {
    printf("Enter number of elements: ");
    scanf("%d", n);  

    printf("Enter %d elements:\n", *n); 
    for (int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}


void main() {
    int arr[100], n;
    readArray(arr,&n);
    linearSearch(arr, n);
}
