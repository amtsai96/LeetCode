class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        set<int> single = {};
        for (int i = 0; i < nums.size(); i++)
            single.insert(nums[i]);
        return 2 * sum(single) - sum(nums);
    }
    int sum(set<int> s)
    {
        int val = 0;
        for (int i : s)
            val += i;
        return val;
    }
    int sum(vector<int> s)
    {
        int val = 0;
        for (int i : s)
            val += i;
        return val;
    }
};