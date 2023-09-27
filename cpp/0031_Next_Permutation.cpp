// time: O(n), space: O(1)
class Solution {
public:
    void swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    void nextPermutation(vector<int>& nums) {
        int i, j;
        int n = nums.size();

        for (i = n - 2; i >= 0; i--)
        {
            if (nums[i + 1] > nums[i])
            {
                break;
            }
        }

        for (j = n - 1; j >= i && i != -1; j--)
        {
            if (nums[j] > nums[i])
            {
                swap(nums[j], nums[i]);
                break;;
            }
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};