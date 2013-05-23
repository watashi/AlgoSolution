class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        if (x < 10) return true;
    
        int b = 10, e = 10, flag = 0;
        while (b <= x) {
            if (b > INT_MAX / 10) {flag = 1; break;}  //easy to overflow here...
            b *= 10;
        }
        if (!flag) b /= 10;
    
        while (b >= e) {
            if (x / b % 10 == (x % e) / (e / 10)) {
                b /= 10;
                e *= 10;
            } else return false;
        }
        return true;
    }
};