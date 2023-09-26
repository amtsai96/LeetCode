// time: O(n), space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0, tmp;

        // [rob1, rob2, n, n+1]
        for (int i = 0; i < nums.size(); i++)
        {
            tmp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }

        return rob2;
    }
};