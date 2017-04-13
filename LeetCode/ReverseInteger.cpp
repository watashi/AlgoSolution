class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (x < 0) {
            return 0 - reverse(0 - x);
        }
        
        int ans = 0;
        
        while (x > 0) {
            ans = 10 * ans + x % 10;
            x /= 10;
        }
        
        return ans;
    }
};