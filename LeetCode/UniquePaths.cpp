class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        m --, n --; //Remember to minus 1 at first!
        if (m > n) swap(m, n);
        
        long long ans = 1;
        for (int i = m + n; i > n; i --) {
            ans *= i;
        }
        
        for (int i = 2; i <= m; i ++) {
            ans /= i;
        }
        
        return ans;
    }
};