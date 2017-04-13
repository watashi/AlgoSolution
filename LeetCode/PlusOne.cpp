class Solution {
public:
    void reverse(vector<int> &digits) {
        int b = 0, e = digits.size() - 1;
        while (b < e) swap(digits[b ++], digits[e --]);
    }
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(digits);
        
        int delta = 1;
        for (int i = 0; i < digits.size(); i ++) {
            digits[i] = digits[i] + delta;
            if (digits[i] >= 10) {
                delta = 1;
                digits[i] -= 10;
            } else delta = 0;
        }
        
        if (delta > 0) digits.push_back(delta);
        reverse(digits);
        
        return digits;
    }
};