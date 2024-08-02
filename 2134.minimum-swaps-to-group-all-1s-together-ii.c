#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int minSwapsHelper(int* data, int length, int val) {
    int totalValCount = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (data[i] == val) totalValCount++;
    }

    if (totalValCount == 0 || totalValCount == length) return 0;

    int start = 0, end = 0;
    int maxValInWindow = 0, currentValInWindow = 0;

    while (end < totalValCount) {
        if (data[end++] == val) currentValInWindow++;
    }
    maxValInWindow = max(maxValInWindow, currentValInWindow);

    while (end < length) {
        if (data[start++] == val) currentValInWindow--;
        if (data[end++] == val) currentValInWindow++;
        maxValInWindow = max(maxValInWindow, currentValInWindow);
    }

    return totalValCount - maxValInWindow;
}

int minSwaps(int* nums, int numsSize) {
    int op1 = minSwapsHelper(nums, numsSize, 0);
    int op2 = minSwapsHelper(nums, numsSize, 1);
    return min(op1, op2);
}