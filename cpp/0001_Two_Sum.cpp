class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a = {0, 1};
        for(int i=0;i < nums.size();i++){
            for(int j=0; j < nums.size();j++){
                if(i == j){continue;}
                if((nums[i] + nums[j]) == target){
                    a = {i, j};
                    return a;
                }
            }
        }
        return a;
    }
};
