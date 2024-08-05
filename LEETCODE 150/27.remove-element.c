void remove_val(int *arr, int n, int pos) {
    for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

int removeElement(int* nums, int numsSize, int val) {
    int newSize = numsSize;
    
    for(int i = 0; i < newSize; i++) {
        if(nums[i] == val) {
            remove_val(nums, newSize, i);
            newSize--;
            i--;
  
        }
    }

    return newSize;
}