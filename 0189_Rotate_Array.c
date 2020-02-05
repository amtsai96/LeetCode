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

