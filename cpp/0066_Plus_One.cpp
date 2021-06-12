class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size()-1] += 1; // plus one
        for(int i=digits.size()-1;i>=0;i--){
            digits[i] += carry;
            carry = 0;
            if(digits[i]>=10){
                digits[i] %= 10;
                carry = 1;
            }
        }
        if(carry == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
