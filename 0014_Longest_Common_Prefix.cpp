class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int min_len = strs[0].length();
        for(int i=1;i<strs.size();i++){
            if(strs[i].size() < min_len)
                min_len = strs[i].size();
        }
        if(min_len == 0)
            return "";
        
        string prefix = "";
        char test = strs[0][0];
        for(int i=0;i<min_len;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] != test){
                    return prefix;
                }
            }
            prefix += strs[0][i];
            test = strs[0][i+1];
        }
        return prefix;
    }
};
