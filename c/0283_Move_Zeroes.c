// time: O(n), space: O(1)
void moveZeroes(int* nums, int numsSize){
    int i, ptr = 0;

    if (numsSize < 2) return;

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            if (ptr != i)
            {
                nums[ptr] = nums[i];
                nums[i] = 0;
            }

            ptr++;
        }
    }
}