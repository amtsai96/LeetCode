class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0)
            return true;
        if(s[0] ==')' || s[0] ==']' || s[0] =='}')
            return false;
        int e = s.length()-1;
        if(s[e] =='(' || s[e] =='[' || s[e] =='{')
            return false;
        string stack = string(1,s[0]);
        int i = 1;
        while(i < s.length()){
            int la = stack.length()-1;
            if(s[i] ==')'){
                if(stack.length()==0) return false;
                if(stack[la]=='(')
                    stack = stack.substr(0, la);
                else return false;
            }
            else if(s[i] ==']'){
                if(stack.length()==0) return false;
                if(stack[la]=='[')
                    stack = stack.substr(0, la);
                else return false;
            }
            else if(s[i] =='}'){
                if(stack.length()==0) return false;
                if(stack[la]=='{')
                    stack = stack.substr(0, la);
                else return false;
            }
            else{
                stack += s[i];
            }
            i++;
        }
        if(stack.length()!=0) return false;
        return true;
    }
};
