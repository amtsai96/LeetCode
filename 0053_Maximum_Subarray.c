

int maxSubArray(int* nums, int numsSize){
    int i = 0, sum = 0, min = 0;
    int max = nums[0];
    for(i=0;i<numsSize;i++){
        sum += nums[i];
        if(sum - min > max) max = sum - min;
        if(sum < min) min = sum;
    }
    return max;
}

