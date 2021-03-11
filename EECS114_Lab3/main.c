//
//  main.c
//  EECS114_Lab3
//
//  Created by Hao-Ming Chiang on 1/20/21.
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
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);

int linearSearch(int arr[], int size, int target) {
    int index = -1;
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            index = i;
        }
    }
    return index;
}

int binarySearch(int arr[], int size, int target) {
    int index = -1;
    int start = 0;
    int end = size - 1;
    while(start < end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            end = mid;
        } else if(arr[mid] < target) {
            start = mid;
        }
    }
    return index;
}

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
    time_t t;
    srand((unsigned)time(&t));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 200;
    }
}

int main(int argc, const char * argv[]) {
   
    int arr[90000];
    randArr(arr,90000);
    int target_val = arr[0];
    merge_sort(arr,0,90000-1);

    clock_t begin, end;
    double time;
    begin = clock();
    int index = binarySearch(arr,90000,target_val);
    end = clock();
    time = (double)(end - begin) * 1000;

    printf("Execution Time: %f\n", time);
    printf("The target value %d is at index %d in the array.\n\n", target_val, index);
    
    printf("Linear Search:\n");
    int arrTest[10];
    randArr(arrTest,10);
    int target = arrTest[0];
    printf("Array before sorting:\n");
    printArr(arrTest,10);
    printf("\n");
    merge_sort(arrTest, 0, 10-1);
    printf("Array after sorting:\n");
    printArr(arrTest,10);
    printf("\n");
    printf("My targe value is %d.\n\n", target);
    int index2 = linearSearch(arrTest,10,target);
    printf("The target value %d is at index %d in the array.\n\n", target, index2);
    
    printf("Binary Search:\n");
    int arrTest2[11];
    randArr(arrTest2,11);
    int target2 = arrTest2[0];
    printf("Array before sorting:\n");
    printArr(arrTest2,11);
    printf("\n");
    merge_sort(arrTest2, 0, 11-1);
    printf("Array after sorting:\n");
    printArr(arrTest2,11);
    printf("\n");
    printf("My targe value is %d.\n\n", target2);
    int index3 = binarySearch(arrTest2,11,target2);
    printf("The target value %d is at index %d in the array.\n\n", target2, index3);

    return 0;
}

