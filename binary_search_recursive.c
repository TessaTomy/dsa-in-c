#include <stdio.h>

void binarySearch(int *arr,int low,int high,int target)
{
    if(low>high)
    {
        printf("Element Not Found !!");
        return;
    }
    int m=(low+high)/2;
    if(arr[m]==target)
    {
        printf("%d found at position - %d",target,m+1);
        return;
    }
    else if(arr[m]>target)
        binarySearch(arr,low,m-1,target);
    else
        binarySearch(arr,m+1,high,target);
}

void search(int arr[], int n) {
    int target;
    printf("Element to search for ?: ");
    scanf("%d",&target);
    binarySearch(arr,0,n,target);
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
    search(arr, n);

}
