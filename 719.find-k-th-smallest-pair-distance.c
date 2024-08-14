#include <stdlib.h>
#include <limits.h>

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to count how many pairs have a difference less than or equal to diff
int sliding(int diff, int* arr, int n) {
    int count = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (arr[i] - arr[j] > diff) {
            j++;
        }
        count += (i - j);
    }
    return count;
}

// Function to find the k-th smallest distance pair
int smallestDistancePair(int* arr, int numsSize, int k) {
    // Sort the array
    qsort(arr, numsSize, sizeof(int), compare);

    // Initialize binary search bounds
    int low = 0;
    int high = arr[numsSize - 1] - arr[0];

    // Binary search
    while (low < high) {
        int mid = (low + high) / 2;
        int count = sliding(mid, arr, numsSize);

        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}
