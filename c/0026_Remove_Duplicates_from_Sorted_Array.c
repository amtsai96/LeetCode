// time: O(n), space: O(1)
int removeDuplicates(int* nums, int numsSize){
    int sorted_idx = 0, track_idx, current_num = nums[0];

    for (track_idx = 1; track_idx < numsSize; track_idx++)
    {
        if (current_num == nums[track_idx]) continue;
        
        nums[++sorted_idx] = nums[track_idx];
        current_num = nums[track_idx];
    }
    
    return sorted_idx + 1;
}

// time: O(n), space: O(1)
int removeDuplicates(int* nums, int numsSize){
    int sorted_idx = 0, track_idx;

    for (track_idx = 1; track_idx < numsSize; track_idx++)
    {
        if (nums[sorted_idx] == nums[track_idx]) continue;
        nums[++sorted_idx] = nums[track_idx];
    }
    
    return sorted_idx + 1;
}