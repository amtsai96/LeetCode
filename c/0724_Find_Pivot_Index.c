int pivotIndex(int* nums, int numsSize){
    int left_sum = 0;
    int right_sum = 0;
    int i;

    for (i = 0;i < numsSize; i++)
    {
        right_sum += nums[i];
    }

    for (i = 0;i < numsSize; i++)
    {
        right_sum -= nums[i];

        if (left_sum == right_sum)
        {
            return i;
        }

        left_sum += nums[i];
    }

    return -1;
}