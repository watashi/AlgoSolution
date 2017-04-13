class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int dp[n + 1]; // n + 1 here!
        
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i ++) { //take n inclusive!
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};