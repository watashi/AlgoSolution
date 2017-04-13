class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (divisor == 0 || divisor == 1) return dividend;
        if (dividend == 0) return 0;
        
        bool p1 = (dividend & (1 << 31)) == 0;
        bool p2 = (divisor & (1 << 31)) == 0;
        
        // when a number is negative, 0 - dividend might overflow, eg: -2147483648
        if (!p1 && p2) {
            return 0 - divide(dividend, 0 - divisor);
        }
        
        if (p1 && !p2) {
            return 0 - divide(0 - dividend, divisor);
        }
        
        int d = divisor;
        
        if (p1 && p2) {
            if (dividend < divisor) return 0;
            
            int i = 0;
            while (dividend - d >= d) {
                d <<= 1; i ++;
            }
            
            return (1 << i) + divide(dividend - d, divisor);
        }
        
        // !p1 && !p2
        if (dividend > divisor) return 0;
            
        int i = 0;
        while (dividend - d <= d) {
            d <<= 1; i ++;
        }
            
        return (1 << i) + divide(dividend - d, divisor);
    }
};