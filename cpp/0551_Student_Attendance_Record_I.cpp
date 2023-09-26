// time: O(n), space: O(1)
class Solution
{
public:
    bool checkRecord(string s)
    {
        int a_cnt = 0, l_idx = -1, i;

        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                a_cnt++;
                l_idx = -1;
                if (a_cnt == 2)
                    return false;
            }
            else if (s[i] == 'L')
            {
                if (l_idx == -1)
                {
                    l_idx = i;
                }
                else if ((i - l_idx + 1) >= 3)
                {
                    return false;
                }
            }
            else // present
            {
                l_idx = -1;
            }
        }

        return true;
    }
};

// time: O(n), space: O(1)
class Solution
{
public:
    bool checkRecord(string s)
    {
        int a_cnt = 0, l_cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                l_cnt = 0;
                if (++a_cnt >= 2)
                    return false;
            }
            else if (s[i] == 'L')
            {
                if (++l_cnt >= 3)
                    return false;
            }
            else // present
            {
                l_cnt = 0;
            }
        }

        return true;
    }
};