// time: O(n + klogn), space: O(n)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(), gifts.end());
        long long result = 0;
        while(k--)
        {
            int value = q.top();
            q.pop();
            q.push(int(sqrt(value)));
        }

        while(!q.empty())
        {
            result += q.top();
            q.pop();
        }

        return result;
    }
};