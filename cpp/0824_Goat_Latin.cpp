class Solution {
private:
    bool isVowel(char ch)
    {
        bool ret = false;

        switch (ch)
            {
                case 'a':
                case 'A':
                case 'e':
                case 'E':
                case 'i':
                case 'I':
                case 'o':
                case 'O':
                case 'u':
                case 'U':
                    ret = true;
                    break;

                default:
                    break;
            }

        return ret;
    }

public:
    string toGoatLatin(string sentence) {
        vector<string> data;
        string cur;
        char tmp;
        int i, start = 0, pos = sentence.find(' '), a_cnt = 1;

        while (pos != -1 || start < sentence.length())
        {
            if (pos == -1) cur = sentence.substr(start);
            else cur = sentence.substr(start, pos - start);
 
            if (!isVowel(cur[0]))
            {
                tmp = cur[0];
                cur = cur.substr(1);
                cur += tmp;
            }

            cur += "ma";
            for (i = 0; i < a_cnt; i++) cur += "a";
            data.push_back(cur);

            if (pos == -1) break;
            a_cnt++;
            start = pos + 1;
            pos = sentence.find(' ', start);
        }

        cur = "";
        for (i = 0; i < data.size(); i++)
        {
            if (i > 0) cur += ' ';
            cur += data[i];
        }

        return cur;
    }
};