class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool first = true;
        for(int i=0;i<s.length();i++){
            if(s[i] != ' '){
                if(first==false) len++;
                else{
                    len = 1;
                    first = false;
                }
            }
            else first = true;
        }
        return len;
    }
};
