// time: O(n log n), space: O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        int j = 0;

        if (n < 2) return intervals;

        sort(intervals.begin(), intervals.end()); // time: O(n log n)
        ans.push_back(intervals[0]);

        // time: O(n)
        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans[j][1] >= intervals[i][0]) // overlap
            {
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            }
            else
            {
                j++;
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};