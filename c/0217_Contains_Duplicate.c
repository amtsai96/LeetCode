// time: O(n), space: O(n)
bool containsDuplicate(int* nums, int numsSize){
    if (numsSize < 2) return false;
    
    int max = nums[0], min = nums[0], i;
    
    for (i = 1; i < numsSize; i++)
    {
        max = max < nums[i] ? nums[i] : max;
        min = min > nums[i] ? nums[i] : min;
    }
    
    int *hashTable = calloc((max - min + 1), sizeof(int));
    
    for (i = 0; i < numsSize; i++)
    {
        if (hashTable[nums[i] - min] != 0) return true;
        hashTable[nums[i] - min] = 1;
    }
    
    return false;
}

// time: O(n log n), space: O(1)
void swap(int *a, int *b)
{
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}

void heapify(int *nums, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
        largest = left;
    if (right < n && nums[right] > nums[largest])
        largest = right;

    if (largest != i)
    {
        swap(&nums[largest], &nums[i]);
        heapify(nums, n, largest);
    }
}

bool containsDuplicate(int* nums, int numsSize){
    if (numsSize < 2) return false;

    int i;
    
    // Generate a Max Heap
    for (i = numsSize / 2 - 1; i >= 0; i--)
        heapify(nums, numsSize, i);

    // Heap Sort
    for (i = numsSize - 1; i > 0; i--)
    {
        if (nums[0] == nums[i]) return true;
        swap(&nums[0], &nums[i]);
        heapify(nums, i, 0);
    }

    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i+1]) return true;
    }
    
    return false;
}