#include<stdio.h>
#include<time.h>
void merge(int arr[],int left,int mid,int right);
void mergesort(int arr[], int left, int right);
void printarr(int arr[], int n);

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
    mergesort(arr,0,n-1);
    end=clock();    
    printf("\nThe sorted array:");
    printarr(arr,n);
    printf("\nTime taken %f in sec",(((double)(end-start))/(CLOCKS_PER_SEC)));
}

void mergesort(int arr[], int left, int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        r[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
}