// time: O(n), space: O(1)
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        // case 1: non-overlapping
        while (i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        // case 2: overlapping, find the interval to merge
        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);

        // push back the remain intervals
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};