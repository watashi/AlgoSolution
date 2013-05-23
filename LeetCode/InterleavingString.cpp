class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (s3.length() != s1.length() + s2.length()) return false;
        if (s1.length() == 0) return s2 == s3;
        if (s2.length() == 0) return s1 == s3;
        
        vector<vector<bool> > isOK(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        
        isOK[0][0] = true;
        for (int i = 1; i <= s1.length(); i ++) 
            if (s1[i - 1] == s3[i - 1]) isOK[i][0] = true;
            else break;
        
        for (int i = 1; i <= s2.length(); i ++) 
            if (s2[i - 1] == s3[i - 1]) isOK[0][i] = true;
            else break;
            
        for (int i = 1; i <= s1.length(); i ++) {
            for (int j = 1; j <= s2.length(); j ++) {
                if (s1[i - 1] == s3[i + j - 1] && isOK[i - 1][j]) isOK[i][j] = true;
                else if (s2[j - 1] == s3[i + j - 1] && isOK[i][j - 1]) isOK[i][j] = true;
            }
        }
        
        return isOK[s1.length()][s2.length()];
    }
};