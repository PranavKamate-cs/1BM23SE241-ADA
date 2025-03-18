#include<stdio.h>
#include<time.h>
int partition(int arr[],int left,int right);
void quickSort(int arr[], int low, int high);
void printarr(int arr[], int n);
void swap(int *i,int *j);
void main(){
    int n;
    printf("Enter the numbr of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The unsorted array:");
    printarr(arr,n);
    clock_t start,end;
    start=clock();
    quickSort(arr,0,n-1);
    end=clock();    
    printf("\nThe sorted array:");
    printarr(arr,n);
    printf("\nTime taken %f in sec",(((double)(end-start))/(CLOCKS_PER_SEC)));
}

void swap(int *i,int *j){
    int t=*i;
    *i=*j;
    *j=t;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high); 
    }
}

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= high && arr[left] <= pivot) {
            left++;
        }
        while (right > low && arr[right] > pivot) {
            right--;
        }
        if (left < right) {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[low], &arr[right]);
    return right;
}

