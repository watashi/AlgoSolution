class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() <= 0) return 0; // The 0 case
        
        vector<int> dp(s.length() + 1, 0);
        
        dp[0] = 1;
        if (s[0] >= '1') dp[1] = 1; // If s[0] == '0', it is impossible.
        
        for (int i = 2; i <= s.length(); i ++) {
            if (s[i - 1] >= '1') dp[i] = dp[i - 1]; // Remember, >= '1' condition
            
            if ((s[i - 2] == '2' && s[i - 1] <= '6') || (s[i - 2] == '1')) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[s.length()];
    }
};