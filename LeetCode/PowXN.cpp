class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == INT_MIN) n += 2; // When -2147483648, add by 2, so it is also an even number..
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n < 0) return 1 / pow(x, -n);
        
        double ans = 1, p = x;
        
        for (int i = 0; i < 32; i ++) {
            if ( 1 << i & n) {
                ans *= p;
            }
            p *= p;
        }
        
        return ans;
    }
};