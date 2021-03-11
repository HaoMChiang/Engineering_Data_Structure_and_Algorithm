//
//  main.c
//  EECS114_Lab5
//
//  Created by Hao-Ming Chiang on 2/3/21.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void maxHeapify(int arr[], int size, int index);
void buildMaxHeap(int arr[], int size);
void heapSort(int arr[], int size);
void printArr(int arr[], int size);
void randArr(int arr[], int size);

void maxHeapify(int arr[], int size, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;
    if(arr[left] > arr[index] && left < size) {
        largest = left;
    }
    if(arr[right] > arr[largest] && right < size) {
        largest = right;
    }
    if(largest != index) {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size) {
    for(int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }
}

void heapSort(int arr[], int size) {
    buildMaxHeap(arr, size);
    for(int i = size - 1; i >= 1; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        maxHeapify(arr, i, 0);
    }
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void randArr(int arr[], int size) {
    time_t t;
    srand((unsigned)time(&t));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 401 - 200;
    }
}

int main(int argc, const char * argv[]) {
    int arr1[5], arr2[10], arr3[15], arr4[20];
    randArr(arr1, 5);
    printf("Array 1 Before Sorted:\n");
    printArr(arr1, 5);
    heapSort(arr1, 5);
    printf("Array 1 After Sorted:\n");
    printArr(arr1, 5);
    
    randArr(arr2, 10);
    printf("\nArray 2 Before Sorted:\n");
    printArr(arr2, 10);
    heapSort(arr2, 10);
    printf("Array 2 After Sorted:\n");
    printArr(arr2, 10);
    
    randArr(arr3, 15);
    printf("\nArray 3 Before Sorted:\n");
    printArr(arr3, 15);
    heapSort(arr3, 15);
    printf("Array 3 After Sorted:\n");
    printArr(arr3, 15);
    
    randArr(arr4, 20);
    printf("\nArray 4 Before Sorted:\n");
    printArr(arr4, 20);
    heapSort(arr4, 20);
    printf("Array 4 After Sorted:\n");
    printArr(arr4, 20);
    return 0;
}
