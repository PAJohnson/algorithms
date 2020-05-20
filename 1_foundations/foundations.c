//Patrick Johnson 2020
//foundations chapter
#include "stdio.h"
#include "limits.h"
#include "stdlib.h"

//two sorting algorithms

void insertionSort(int *array, int length){
    //translation of code from book
    int j;
    int i;
    int key;
    for(j = 1; j < length; j++){
        key = array[j];
        i = j-1;
        //insert array[j] into the sorted sequence array[1..j-1]
        while(i >= 0 && array[i] > key){
            array[i+1] = array[i];
            i = i - 1;
        }
        array[i+1] = key;
    }
    return;
}

void merge(int *array, int low, int mid, int high){
    //function to merge two sorted arrays
    //first array is array[low..mid], second is array[mid+1..high]
    int i;
    int j;
    int *left, *right;
    int len1 = mid-low+1;
    int len2 = high-mid;
    
    //make two new arrays
    left = malloc((len1+1)*sizeof(int));
    right = malloc((len2+1)*sizeof(int));
    
    //initialize two new arrays
    for(i = 0; i < (len1); i++){
        left[i] = array[low+i];
    }
    
    for(i = 0; i < (len2); i++){
        right[i] = array[mid+i+1];
    }
    
    //sentinel values
    left[len1] = INT_MAX;
    right[len2] = INT_MAX;
    
    i = 0;
    j = 0;
    
    //actual merging
    for(int k = low; k < high+1; k++){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i = i + 1;
        }
        else{
            array[k] = right[j];
            j = j + 1;
        }
    }
    
    free(left);
    free(right);
    
}

void mergeSort(int *array, int low, int high){
    if(low < high){
        int mid;
        mid = (low+high)/2;
        mergeSort(array,low,mid);
        mergeSort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}



int main(){
    int unsorted[10] = {10,9,8,7,6,5,4,3,2,1};
    int unsorted_2[10] = {10,9,8,7,6,5,4,3,2,1};
    
    printf("insertion sort\n\r");
    printf("unsorted: ");
    for(int i = 0; i < 10; i++){
        printf("%d ",unsorted[i]);
    }
    
    insertionSort(unsorted,10);
    printf("\n\rsorted: ");
    for(int i = 0; i < 10; i++){
        printf("%d ",unsorted[i]);
    }
    
    printf("\n\rmerge sort\n\r");
    printf("unsorted: ");
    for(int i = 0; i < 10; i++){
        printf("%d ",unsorted_2[i]);
    }
    
    mergeSort(unsorted_2,0,9);
    printf("\n\rsorted: ");
    for(int i = 0; i < 10; i++){
        printf("%d ",unsorted_2[i]);
    }
    
    return 0;
}
