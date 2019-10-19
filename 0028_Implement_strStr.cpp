class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle, 0);
        // if(needle=="") return 0;
        // for(int j=0;j<haystack.length();j++){
        //     if(haystack[j] == needle[0]){
        //         if(needle.length()==1) return j;
        //         for(int i=1;i<needle.length();i++){
        //             if(j+i>=haystack.length()) break;
        //             if(haystack[j+i] != needle[i]) break;
        //             if(i==needle.length()-1) return j;
        //         }
        //     }
        // }
        // return -1;
    }
};
