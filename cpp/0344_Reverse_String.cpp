// time: O(n), space: O(1)
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }
};

// time: O(n), space: O(1)
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        char tmp;

        for (int i = 0; i < s.size() / 2; i++)
        {
            tmp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = tmp;
        }
    }
};