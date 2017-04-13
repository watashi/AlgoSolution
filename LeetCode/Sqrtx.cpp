class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long b = 0, e = x / 2 + 1;
        
        while (b <= e) {
            long long mid = b + (e - b) / 2;
            
            if (mid * mid > x) {
                e = mid - 1;
            } else b = mid + 1;
        }
        
        return b - 1;
    }
};