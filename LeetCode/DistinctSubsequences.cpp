/**
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some 
 * (can be none) of the characters without disturbing the relative positions of the remaining characters. 
 * (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 */
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // dp[i][j] means how much subsequence in S(1..i) match pattern T(1..j), offset count from 1
        vector<vector<int> > dp(S.length() + 1, vector<int>(T.length() + 1, 0));
        
        // dp[i][0] = 1 means when pattern is empty string, any string match the pattern
        for (int i = 0; i <= S.length(); i ++) {
            dp[i][0] = 1;
        }
        
        // dp[j][i] = dp[j - 1][i] is always valid, which means we can omit the last character in S(1..j)
        // how many ways that S(1..j - 1) matches T(1..i), cause how many ways to S(1..j)
        // in another situation, when S[j - 1] == T[i - 1], we could match a character in current position
        // thus, we should add dp[j - 1][i - 1] to it.
        for (int i = 1; i <= T.length(); i ++) {
            for (int j = 1; j <= S.length(); j ++) {
                dp[j][i] = dp[j - 1][i];
                if (S[j - 1] == T[i - 1]) {
                    dp[j][i] += dp[j - 1][i - 1];
                }
            }
        }
        
        /*
        // We can also change the computing sequence as following:
        for (int i = 1; i <= S.length(); i ++) {
            for (int j = 1; j <= T.length(); j ++) {
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        */
        
        return dp[S.length()][T.length()];
    }
};
