class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > dp(word1.length() + 1, vector<int>(word2.length() + 1, INT32_MAX));
        
        dp[0][0] = 0;
        
        for (int i = 1; i <= word1.size(); i ++) dp[i][0] = i;
        for (int i = 1; i <= word2.size(); i ++) dp[0][i] = i;
        
        for (int i = 1; i <= word1.size(); i ++) {
            for (int j = 1; j <= word2.size(); j ++) {
                // dp[i - 1][j]: delete word1[i]
                // dp[i][j - 1]: insert word2[j] to word1[i + 1]
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        
        return dp[word1.length()][word2.length()];
    }
};