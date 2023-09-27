// time: O(n), space: O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.empty()) return nums;

        vector<int> ans;
        int idx;
        for (int i = 0; i < nums.size(); i++)
        {
            idx = abs(nums[i]) - 1;

            if (nums[idx] < 0)
            {
                ans.push_back(idx + 1);
            }

            nums[idx] *= -1;
        }

        return ans;
    }
};