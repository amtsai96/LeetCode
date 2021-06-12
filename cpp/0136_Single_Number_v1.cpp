class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        set<int> single = {nums[0]};
        for (int i = 1; i < nums.size(); i++)
        {
            set<int>::iterator it = find(single.begin(), single.end(), nums[i]);
            if (it != single.end())
                single.erase(it);
            else
                single.insert(nums[i]);
        }
        return *single.begin();
    }
};