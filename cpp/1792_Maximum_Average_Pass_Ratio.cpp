//time: O(n), space: O(nlogn)
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        //priority_queue優先判定為!cmp,由大排到小需反向定義,實現最小值優先
        double aa = (double)(a.first + 1)/((double)(a.second + 1)) - (double)a.first/(double)a.second;
        double bb = (double)(b.first + 1)/((double)(b.second + 1)) - (double)b.first/(double)b.second;
        return aa < bb;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
        double ratio = 0;
        pair<int, int> t;
        for(vector<int>i: classes)
        {
            q.push(make_pair(i[0], i[1]));
        }
        while(extraStudents--)
        {
            t = q.top();
            t.first++, t.second++;
            q.pop();
            q.push(t);
        }
        while(!q.empty())
        {
            t = q.top();
            ratio += ((double)t.first/(double)t.second);
            q.pop();
        }
        return (double)ratio / (double)classes.size();
    }
};