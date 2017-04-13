class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < n; i ++) {
            
            for (int j = A[i]; j > 0; j --) {
                if (i + j >= n) continue;
                if (dp[i + j] <= dp[i] + 1) break;
                dp[i + j] = dp[i] + 1;
            }
        }
        return dp[n - 1];
    }
};