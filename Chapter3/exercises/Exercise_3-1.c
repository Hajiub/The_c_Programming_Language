/*
Etargetercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.
*/

#include <stdio.h>


int binSearch(int target, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (target <= v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (low < n && v[low] == target) {
        return low;
    } else {
        return -1;
    }
}

int main() {
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int target = 7;

    int result = binSearch(target, sortedArray, size);

    if (result != -1) {
        printf("Element %d found at indetarget %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}