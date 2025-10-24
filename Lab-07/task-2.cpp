#include<iostream>
using namespace std;

void merge(int arr[],int start, int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end-mid;

    int left[100] = {0};
    int right[100] = {0};

    for(int i=0;i<n1;i++){
        left[i] = arr[start+i];
    }

    for( int i=0;i<n2;i++){
        right[i] = arr[mid+i+1];
    }

    int i=0,j=0, k = start;

    while (i<n1 && j<n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }

    while(i<n1){
        arr[k] = right[i];
        j++;
        k++;
    }
}

void mergesort(int arr[],int start,int end){
    if(start >= end){
        return;
    }

    int mid = (start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(){

    int arr[10] = {10,8,56,2,9,63,4,7,5,11};

    mergesort(arr,0,9);

    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}