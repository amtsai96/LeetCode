class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
            return s;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = maxAroundCenter(s, i, i);
            int len2 = maxAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int maxAroundCenter(string s, int l, int r)
    {
        int left = l, right = r;
        while (left >= 0 and right < s.length() and s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};