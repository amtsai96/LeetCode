// time: O(n), space: O(1)
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        int carry = 0, x1, x2, sum = 0;
        string ans;

        while (p1 >= 0 || p2 >= 0)
        {
            x1 = p1 >= 0 ? num1[p1--] - '0' : 0;
            x2 = p2 >= 0 ? num2[p2--] - '0' : 0;

            sum = x1 + x2 + carry;
            carry = sum / 10;
            ans.push_back((sum % 10) + '0');
        }

        if (carry > 0)
        {
            ans.push_back(carry + '0');
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};