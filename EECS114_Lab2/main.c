//
//  main.c
//  EECS114_Lab2
//
//  Created by Hao-Ming Chiang on 1/13/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void insertion_sort(int arr[], int size);
void merge_sort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);
void printArr(int arr[], int size);
void randArr(int arr[], int size);

void insertion_sort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge_sort(int arr[], int start, int end) {
    if(start < end) {
        int mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int arr[], int start, int mid, int end) {
    int first_arr[mid - start + 1 + 1];
    int second_arr[end - mid + 1];
    
    for(int i = 0; i < mid - start + 1; i++) {
        first_arr[i] = arr[i + start];
    }
    
    for(int j = 0; j < end - mid; j++) {
        second_arr[j] = arr[j + mid + 1];
    }
    
    first_arr[mid - start + 1] = INT_MAX;
    second_arr[end - mid] = INT_MAX;
    
    int first_arr_index = 0;
    int second_arr_index = 0;
    
    for(int i = start; i <= end; i++) {
        if(first_arr[first_arr_index] < second_arr[second_arr_index]) {
            arr[i] = first_arr[first_arr_index++];
        } else {
            arr[i] = second_arr[second_arr_index++];
        }
    }
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 200;
    }
}

int main(int argc, const char * argv[]) {
    int arr[4], arr2[7], arr3[10], arr4[4], arr5[7], arr6[10];
    
    randArr(arr,4);
    randArr(arr2,7);
    randArr(arr3,10);
    randArr(arr4,4);
    randArr(arr5,7);
    randArr(arr6,10);
    
    int arrTest[900000];
    randArr(arrTest,900000);
    clock_t begin, end;
    double time;
    begin = clock();
    merge_sort(arrTest, 0, 900000 - 1);
    end = clock();
    time = (double)(end - begin) * 1000;
    printf("%f\n", time);
        
    printf("Insertion Sort:\n\n");
    printf("Before sorted:\n");
    printArr(arr,4);
    insertion_sort(arr,4);
    printf("After sorted\n");
    printArr(arr,4);
    printf("\n");

    printf("Before sorted:\n");
    printArr(arr2,7);
    insertion_sort(arr2,7);
    printf("After sorted\n");
    printArr(arr2,7);
    printf("\n");

    printf("Before sorted:\n");
    printArr(arr3,10);
    insertion_sort(arr3,10);
    printf("After sorted\n");
    printArr(arr3,10);
    printf("\n");

    printf("Merge Sort:\n\n");
    printf("Before sorted:\n");
    printArr(arr4,4);
    merge_sort(arr4,0,3);
    printf("After sorted\n");
    printArr(arr4,4);
    printf("\n");

    printf("Before sorted:\n");
    printArr(arr5,7);
    merge_sort(arr5,0,6);
    printf("After sorted\n");
    printArr(arr5,7);
    printf("\n");

    printf("Before sorted:\n");
    printArr(arr6,10);
    merge_sort(arr6,0,9);
    printf("After sorted\n");
    printArr(arr6,10);
    printf("\n");

    return 0;
}
