// time: O(n), space: O(1)
void swap(int *a, int *b){
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}
void reverse(int *a, int len){
    int i=0, j=len-1;
    while(i < j){
        swap(&a[i], &a[j]);
        i++;j--;
    }
}
void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    reverse(nums, numsSize);
    reverse(nums, k);
    reverse(nums+k, numsSize-k);
    
    return nums;
}

// time: O(n), space: O(1)
void reverse(int* nums, int start, int end)
{
    int tmp;
    
    while(start < end)
    {
        tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize < 2) return;
    if (k == 0) return;
    
    k %= numsSize;
    
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}