// time: O(n), space: O(1)
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() < 2 || s.length() < numRows || numRows == 1) return s;

        string ans = "";
        int zigzag_num = (numRows - 1) * 2;

        for(int i = 0; i < numRows; i++)
        {
            int base = i;
            while (base < s.length())
            {
                ans += s[base];

                if (i != 0 && i != numRows - 1)
                {
                    int idx = base + zigzag_num - i * 2;

                    if (idx < s.length())
                        ans += s[idx];
                }

                base += zigzag_num;
            }
        }

        return ans;
    }
};