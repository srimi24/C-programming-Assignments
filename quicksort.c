#include <stdio.h>

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    //Your code here
    int pivot=arr[low];
    int start=low,end=high;
    while(start<end){
        while(start<end && arr[start]<=pivot)
            start++;
        while(start<=end && arr[end]>pivot)
            end--;
        if(start<end){
            swap(arr,start,end);
        }
    }
    swap(arr,low,end);
    return end;
}

// Function to perform quick sort on an array
void quickSort(int arr[], int low, int high) {
    //Your code here
    if(low<high){
        int pivot_pos=partition(arr,low,high);
      
        quickSort(arr,low,pivot_pos-1);
        quickSort(arr,pivot_pos+1,high);
    }
}

int main() {
    int treasure[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&treasure[i]);
    }

    quickSort(treasure, 0, n - 1);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", treasure[i]);
    }
    printf("\n");

    printf("The adventurer is pleased with the sorted treasure and can now count their wealth.\n");
    return 0;
}