//
//  main.c
//  EECS114_Lab4
//
//  Created by Hao-Ming Chiang on 1/27/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

struct leftRightSum {
    int left, right, max;
};

struct leftRightSum maxSubArr_bruteForce(int arr[], int size);
struct leftRightSum maxSubArr_divideConquer(int arr[], int start, int end);
struct leftRightSum crossMax(int arr[], int start, int mid, int end);
void printArr(int arr[], int size);
void randArr(int arr[], int size);
void printResult(struct leftRightSum result);

struct leftRightSum maxSubArr_bruteForce(int arr[], int size) {
    struct leftRightSum result = {-1, -1, 0};
    int max = INT_MIN;
    for(int i = 0; i < size; i++) {
        int curr = 0;
        for(int j = i ; j < size; j++) {
            curr += arr[j];
            if(curr > max) {
                max = curr;
                result.left = i;
                result.right = j;
                result.max = max;
            }
        }
    }
    return result;
}

struct leftRightSum maxSubArr_divideConquer(int arr[], int start, int end) {
    if(start == end) {
        struct leftRightSum result = {-1, -1, 0};
        result.left = start;
        result.right = end;
        result.max = arr[start];
        return result;
    } else {
        struct leftRightSum final = {-1, -1, 0};
        struct leftRightSum left = {-1, -1, 0};
        struct leftRightSum right = {-1, -1, 0};
        struct leftRightSum cross = {-1, -1, 0};

        int mid = start + (end - start) / 2;
        left = maxSubArr_divideConquer(arr, start, mid);
        right = maxSubArr_divideConquer(arr, mid + 1, end);
        cross = crossMax(arr, start, mid, end);
        
        if(left.max > right.max) {
            final = left;
        } else {
            final = right;
        }
        
        if(cross.max > final.max) {
            final = cross;
        }
        
        return final;
    }
}

struct leftRightSum crossMax(int arr[], int start, int mid, int end) {
    struct leftRightSum result = {-1, -1, 0};
    int left_max = INT_MIN;
    int right_max = INT_MIN;
    int left_sum = 0;
    int right_sum = 0;
    int left_index = -1;
    int right_index = -1;
    
    for(int i = mid; i >= start; i--) {
        left_sum += arr[i];
        if(left_sum > left_max) {
            left_max = left_sum;
            left_index = i;
        }
    }
    for(int j = mid + 1; j <= end; j++) {
        right_sum += arr[j];
        if(right_sum > right_max) {
            right_max = right_sum;
            right_index = j;
        }
    }
    result.left = left_index;
    result.right = right_index;
    result.max = left_max + right_max;
    return result;
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
        arr[i] = rand() % 401 - 200;
    }
}

void printResult(struct leftRightSum result) {
    printf("Left Index: %d\n", result.left);
    printf("Right Index: %d\n", result.right);
    printf("Maximum Sum: %d\n\n", result.max);
}

int main(int argc, const char * argv[]) {
    int arr[7];

//    printf("Brute-Force Method\n");
    printf("Divide-and-Conquer Method:\n\n");

    printf("Array 1:\n");
    randArr(arr, 7);
    printArr(arr, 7);
    struct leftRightSum result = maxSubArr_divideConquer(arr, 0, 6);
    printResult(result);
    
//    clock_t begin, end;
//    double time;
//    for(int i = 1; i <= 1000000; i++) {
//        int arr[i];
//        randArr(arr,i);
//        begin = clock();
//        struct leftRightSum result = maxSubArr_bruteForce(arr, i);
//        end = clock();
//        time = (double)(end - begin) * 1000;
//        printf("%f\n", time);
//    }

//    struct leftRightSum result = {-1,-1,0};
//    for(int k = 10000; k<=90000; k=k+10000) {
//        int arr[k];
//        randArr(arr,k);
//        clock_t begin, end;
//        double time;
//        begin = clock();
//        result = maxSubArr_bruteForce(arr, k);
//        end = clock();
//        time = (double)(end - begin) * 1000;
//        printf("%f\n", time);
//    }
//    printResult(result);
    return 0;
}
