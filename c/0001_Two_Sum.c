// time: O(n^2), space O(1)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *returnArray = (int *)malloc(2 * sizeof(int));

    *returnSize = 2;

    for (i = 0; i < numsSize-1; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;
                return returnArray;
            }
        }
    }

    return returnArray;
}

// time: O(n), space: O(n)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *returnArray = malloc(2 * sizeof(int));
    int max = nums[0], min = nums[0], i, checkIndex;

    *returnSize = 2;

    for (i = 1; i < numsSize; i++)
    {
        max = max < nums[i] ? nums[i] : max;
        min = min > nums[i] ? nums[i] : min;
    }

    int *hashTable = calloc(max - min + 1, sizeof(int));

    hashTable[nums[0] - min] = -1; // avoid judging error

    for (i = 1; i < numsSize; i++)
    {
        hashTable[nums[i] - min] = i;
    }

    for (i = 0; i < numsSize; i++)
    {
        checkIndex = target - nums[i] - min;

        if (checkIndex < 0 || checkIndex > (max - min)) continue;

        if (hashTable[checkIndex] == 0)
        {
            hashTable[nums[i] - min] = i;
        }
        else
        {
            returnArray[0] = i;
            returnArray[1] = hashTable[checkIndex];
            
            if (hashTable[checkIndex] < 0)
            {
                returnArray[1] = 0;
            }

            if (returnArray[0] == returnArray[1]) continue;

            free(hashTable);
            return returnArray;
        }
    }

    free(hashTable);
    return returnArray;
}

// time: O(n), space: O(n)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *returnArray = malloc(2 * sizeof(int));
    int max = nums[0], min = nums[0], i, checkIndex;

    *returnSize = 2;

    for (i = 1; i < numsSize; i++)
    {
        max = max < nums[i] ? nums[i] : max;
        min = min > nums[i] ? nums[i] : min;
    }

    int *hashTable = calloc(max - min + 1, sizeof(int));

    hashTable[nums[0] - min] = -1; // avoid judging error

    for (i = 1; i < numsSize; i++)
    {
        checkIndex = target - nums[i] - min;

        if (checkIndex < 0 || checkIndex > (max - min)) continue;

        if (hashTable[checkIndex] == 0)
        {
            hashTable[nums[i] - min] = i;
        }
        else
        {
            returnArray[0] = i;
            returnArray[1] = hashTable[checkIndex];
            
            if (hashTable[checkIndex] < 0)
            {
                returnArray[1] = 0;
            }

            if (returnArray[0] == returnArray[1]) continue;

            free(hashTable);
            return returnArray;
        }
    }

    free(hashTable);
    return returnArray;
}