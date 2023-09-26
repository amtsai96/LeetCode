// time: O(n log n)?, space: O(n^2);
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<vector<string>> data;
        vector<string> ans, digitLogs;
        int i, pos;

        // partition(letter, digit)
        for (i = 0; i < logs.size(); i++)
        {
            pos = logs[i].find(' ');
            if (logs[i][pos + 1] >= '0' && logs[i][pos + 1] <= '9')
            {
                digitLogs.push_back(logs[i]);
                continue;
            }

            data.push_back({logs[i].substr(0, pos), logs[i].substr(pos + 1)});
        }
        
        // letter log sorting
        sort(data.begin(), data.end(), [](vector<string>& a, vector<string>& b)
        {
            return (a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]));
        });

        for (i = 0; i < data.size(); i++)
        {
            ans.push_back(data[i][0] + ' ' + data[i][1]);
        }

        // push letter log
        for (i = 0; i < digitLogs.size(); i++)
        {
            ans.push_back(digitLogs[i]);
        }

        return ans;
    }
};