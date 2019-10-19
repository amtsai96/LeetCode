class Solution {
public:
    string countAndSay(int n) {
        if(n<1) return "";
        if(n==1) return "1";
        string ans = "1";
        string tmp;
        int ctr;
        char c;
        for(int i=1;i<n;i++){
            tmp = "";
            ctr = 0;
            c = ans[0];
            for(int j=0;j<ans.length();j++){
                if(ans[j] == c) ctr++;
                else{
                    tmp += to_string(ctr);
                    tmp += c;
                    c = ans[j];
                    ctr = 1; //reset
                }
                if(j == ans.length()-1){
                    tmp += to_string(ctr);
                    tmp += c;
                }
            }
            ans = tmp;
        }
        return ans;
    }
};
