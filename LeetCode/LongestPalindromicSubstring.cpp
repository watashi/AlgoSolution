class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() < 2) return s;
        
        vector<vector<bool> > isOK(s.length(), vector<bool>(s.length(), false));
        
        int maxLen = 1, begin = 0;
        
        for (int len = 2; len <= s.length(); len ++) {
            for (int i = 0; i <= s.length() - len; i ++) {
                int end = i + len - 1;
                if (s[i] == s[end] && ((i + 1 >= end - 1) || isOK[i + 1][end - 1])) {
                    isOK[i][end] = true;
                    
                    if (maxLen < len) {
                        begin = i;
                        maxLen = len;
                    }
                }
            }
        }
        
        return s.substr(begin, maxLen);
    }
};