int removeDuplicates(int* nums, int numsSize){

    if (numsSize <= 2)
        return numsSize;
    int prev = 1;       // point to previous
    int curr = 2;       // point to current

    // Traverse all elements in a while loop
    while (curr < numsSize) {
        // If the curr index matches the previous two elements, skip it...
        if (nums[curr] == nums[prev] && nums[curr] == nums[prev - 1]) {
            curr++;
        }
        // Otherwise, count that element and update...
        else
        {
            prev++;
            nums[prev] = nums[curr];
            curr++;
        }
    }
    return prev + 1;
}