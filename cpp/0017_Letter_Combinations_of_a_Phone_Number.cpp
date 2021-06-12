class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result = {""};
        for (int i = 0; i < digits.size(); i++)
        {
            string letters = dict[digits[i] - '0'];
            vector<string> tmp = {};
            for (int j = 0; j < letters.size(); j++)
            {
                for (string s : result)
                    tmp.push_back(s + letters[j]);
            }
            result = tmp;
        }
        return result;
    }
};