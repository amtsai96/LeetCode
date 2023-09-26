// time: O(n), space: O(1)
class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int positive = 1;
        int tmp;
        int i = 0;

        while (s[i] == ' ') i++;

        if (s[i] == '-')
        {
            positive = 0;
            i++;
        }
        else if (s[i] == '+') i++;

        for (i; i < s.length(); i++)
        {
            if (s[i] < '0' || s[i] > '9') break;

            tmp = s[i] - '0';

            if (ans > (INT_MAX - tmp) / 10)
                return (positive == 1) ? INT_MAX : INT_MIN;

            ans = ans * 10 + tmp;
        }

        if (positive == 0) ans *= -1;

        return ans;
    }
};