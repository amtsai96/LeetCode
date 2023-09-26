// time: O(n log n), space: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        if (strs.size() == 1) return strs[0];
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs[0].size(); i++)
        {
            if (strs[0][i] != strs[strs.size() - 1][i]) return ans;
            ans += strs[0][i];
        }

        return ans;
    }
};