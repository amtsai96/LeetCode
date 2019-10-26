class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        map<int, int> m;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++)
        {
            it = m.find(nums[i]);
            if (it != m.end())
            {
                m[nums[i]] += 1;
                if (m[nums[i]] > nums.size() / 2)
                    return nums[i];
            }
            else
                m[nums[i]] = 1;
        }
        return -1;
    }
};