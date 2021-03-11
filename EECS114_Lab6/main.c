//
//  main.c
//  EECS114_Lab6
//
//  Created by Hao-Ming Chiang on 2/10/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void radixSort(int arr[], int size, int digit);
void insertion_sort(int arr[], int size, int digit);
void printArr(int arr[], int size);
void randArr(int arr[], int size);

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int partition(int arr[], int start, int end) {
    int p = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if(arr[j] < p) {
            i += 1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return i + 1;
}

void radixSort(int arr[], int size, int digit) {
    for(int i = 1; i <= pow(10,digit); i *= 10) {
        insertion_sort(arr, size, i);
    }
}

void insertion_sort(int arr[], int size, int digit) {
    for(int i = 1; i < size; i++) {
        int temp = arr[i];
        int key = temp / digit % 10;
        int j = i - 1;
        while(j >= 0 && key < arr[j] / digit % 10) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
        arr[i] = rand() % 1000;
    }
}

int main(int argc, const char * argv[]) {
    int arr1[5], arr2[10], arr3[15], arr4[20];
    randArr(arr1, 5);
    printf("Array 1 Before Sorted:\n");
    printArr(arr1, 5);
    quickSort(arr1, 0, 4);
    printf("Array 1 After Sorted:\n");
    printArr(arr1, 5);
    
    randArr(arr2, 10);
    printf("\nArray 2 Before Sorted:\n");
    printArr(arr2, 10);
    quickSort(arr2, 0, 9);
    printf("Array 2 After Sorted:\n");
    printArr(arr2, 10);
    
    randArr(arr3, 15);
    printf("\nArray 3 Before Sorted:\n");
    printArr(arr3, 15);
    radixSort(arr3, 15, 3);
    printf("Array 3 After Sorted:\n");
    printArr(arr3, 15);
    
    randArr(arr4, 20);
    printf("\nArray 4 Before Sorted:\n");
    printArr(arr4, 20);
    radixSort(arr4, 20, 3);
    printf("Array 4 After Sorted:\n");
    printArr(arr4, 20);
    return 0;
}
