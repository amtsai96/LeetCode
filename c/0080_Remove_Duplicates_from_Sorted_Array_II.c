// time:O(n), space: O(1)
int removeDuplicates(int* nums, int numsSize){
    int pre = 0, cur = 1, count = 1;

    if (numsSize < 3) return numsSize;

    while (cur < numsSize)
    {
        if (nums[pre] == nums[cur] && count == 0) cur++;
        else
        {
            if (nums[pre] == nums[cur]) count--;
            else count = 1; // reset
            nums[++pre] = nums[cur++];
        }
    }

    return pre + 1;
}

// time:O(n), space: O(1)
int removeDuplicates(int* nums, int numsSize){
    int pre = 0;

    if (numsSize < 3) return numsSize;

    for (int i = 0; i < numsSize; i++)
    {
        if (pre < 2 || nums[i] > nums[pre - 2])
            nums[pre++] = nums[i];
    }

    return pre;
}