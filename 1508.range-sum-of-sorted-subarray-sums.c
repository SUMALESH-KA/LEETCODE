#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
    int len = (n * (n + 1)) / 2;
    int* sum_array = malloc(len * sizeof(int));
    if (sum_array == NULL) {
        return -1;
    }

    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            sum_array[index++] = sum;
        }
    }
    qsort(sum_array, index, sizeof(int), compare);

    const int MOD = 1e9 + 7; // 10^9 + 7
    int ans = 0;
    for (int i = left - 1; i < right; i++) {
        ans = (ans + sum_array[i]) % MOD;
    }

    free(sum_array);  // Don't forget to free the allocated memory
    return ans;
}
