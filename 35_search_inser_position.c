#include <stdio.h>

int searchInsert(int* nums, int n, int target) {
    int l = 0;
    int r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return l;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int n = sizeof(nums) / sizeof(nums[0]);

    int index = searchInsert(nums, n, target);
    printf("Insert position: %d\n", index);  // Output: 2

    target = 2;
    index = searchInsert(nums, n, target);
    printf("Insert
