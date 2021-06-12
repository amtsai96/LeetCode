class Solution {
public:
    string addBinary(string a, string b) {
        // Reverse a & b
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string sum = "";
        int carry = 0;
        int len = max(a.length(), b.length());
        for(int i=0;i<len;i++){
            if(i < a.length()) carry += (a[i]-'0');
            if(i < b.length()) carry += (b[i]-'0');
            sum.push_back(carry%2 + '0');
            carry /= 2;
        }
        if(carry > 0) sum.push_back('1');
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
