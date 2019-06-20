class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                if(i+1 < s.length() && (s[i+1]=='V' || s[i+1]=='X')){
                    value -= 1;
                }
                else{
                    value += 1;
                }
            }
            else if(s[i]=='V'){
                value += 5;
            }
            else if(s[i]=='X'){
                if(i+1 < s.length() && (s[i+1]=='L' || s[i+1]=='C')){
                    value -= 10;
                }
                else{
                    value += 10;
                }
            }
            else if(s[i]=='L'){
                value += 50;
            }
            else if(s[i]=='C'){
                if(i+1 < s.length() && (s[i+1]=='D' || s[i+1]=='M')){
                    value -= 100;
                }
                else{
                    value += 100;
                }
            }
            else if(s[i]=='D'){
                value += 500;
            }
            else if(s[i]=='M'){
                value += 1000;
            }
        }
        return value;
    }
};
