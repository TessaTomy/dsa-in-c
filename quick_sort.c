#include <stdio.h>

int findPivot(int *arr,int l,int h)
{
    int i=l,j=h,key=arr[i];
    while(i<j)
    {
        for(;arr[i]<=key&&i<h;i++);
        for(;arr[j]>key&&j>l;j--);
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[l];
    arr[l]=arr[j];
    arr[j]=temp;
    return j;
}
void quickSort(int *arr,int l,int h)
{
    if(l>h)
        return;
    int p=findPivot(arr,l,h);
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,h);
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
    
    quickSort(arr,0,n-1);

    printf("Sorted array: ");
    display(arr, n);
}
