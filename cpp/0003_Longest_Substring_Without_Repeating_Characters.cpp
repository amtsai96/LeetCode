class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int left_index = -1;
        unordered_map<int, int> map;
        for(int i=0;i<s.size();i++){
            if(map.count(s[i]) && (map[s[i]] > left_index)){
                left_index = map[s[i]];
            }
            map[s[i]] = i;
            max_len = max(max_len, i-left_index);
        }
        
        return max_len;
    }
};