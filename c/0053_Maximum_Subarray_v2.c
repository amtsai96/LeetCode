int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int local = nums[0];
    for (int i = 1; i < numsSize; i++) {
        local = (local > 0)? local + nums[i]: nums[i];
        max = (max < local)? local: max;
    }
    return max;
}
