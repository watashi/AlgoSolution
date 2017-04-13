/*
 Given a string s, partition s such that every substring of the partition is a palindrome.

 Return the minimum cuts needed for a palindrome partitioning of s.

 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 
 * At first I used an N * N * N time comlexity DP, saves m[i][j], which would TLE.
 * In fact, we just need to save m[i] because we always need a palindrome in the tail.
 *
*/

class Solution {
public:
  int minCut(string s) {
    if (s.length() == 1) return 0;
    
    vector<vector<bool> > isPalin(s.length(), vector<bool>(s.length(), false));
    
    for (int L = 1; L <= s.length(); L ++) {
      for (int i = 0; i < s.length() - L + 1; i ++) {
        int j = i + L - 1;
        if (s[i] == s[j]) {
          if (i + 1 >= j - 1 || isPalin[i + 1][j - 1]) {
            isPalin[i][j] = true;
          }
        }
      }
    }
    
    vector<int> m(s.length(), INT_MAX);
    
    for (int i = 0; i < s.length(); i ++) {
      m[i] = i;
    }
    
    for (int i = 0; i < s.length(); i ++) {
      if (isPalin[0][i]) {
        m[i] = 0;
        continue;
      }
      
      for (int j = i - 1; j >= 0; j --) {
        if (isPalin[j + 1][i]) {
          m[i] = min(m[i], 1 + m[j]);
        }
      }
    }
    
    return m[s.length() - 1];
  }
};