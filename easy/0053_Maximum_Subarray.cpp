class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_v = INT_MIN;
        return findMax(nums, 0, nums.size()-1, max_v);
    }
    int findMax(vector<int>& nums, int start, int end, int val){
        int max_v = val;
        if(start > end) return INT_MIN;
        int mid = (start+end)/2;
        int left_max = findMax(nums, start, mid-1, max_v);
        int right_max = findMax(nums, mid+1, end, max_v);
        max_v = max(left_max, max_v);
        max_v = max(right_max, max_v);
        
        int sum = 0, lmax = 0, rmax = 0;
        for(int i=mid-1;i>=start;i--){
            sum += nums[i];
            if(sum > lmax) lmax = sum;
        }
        sum = 0;
        for(int i=mid+1;i<=end;i++){
            sum += nums[i];
            if(sum > rmax) rmax = sum;
        }
        max_v = max(max_v, lmax+rmax+nums[mid]);
        
        return max_v;
    }
};
