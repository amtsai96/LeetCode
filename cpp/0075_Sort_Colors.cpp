// time: O(n), space: O(1)
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> cnt(3);
        int i, cur_idx;

        for (i = 0; i < nums.size(); i++)
            cnt[nums[i]]++;

        for (int j = 0, cur_idx = 0; j < 3; j++)
            for (i = 0; i < cnt[j]; i++)
            {
                nums[cur_idx++] = j;
            }
    }
};

// time:O(n), space: O(1)
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low++], nums[mid++]);
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};