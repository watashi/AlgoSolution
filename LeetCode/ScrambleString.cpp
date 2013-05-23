class Solution {
public:
  bool isScramble(string s1, string s2) {   
    // Start typing your C/C++ solution below   
    // DO NOT write int main() function   
    
    if (s1.length() != s2.length()) return false;
    
    int len = s1.length();
    if (len == 1) return s1[0] == s2[0];
    
    vector<int> f(26, 0);
    
    for (int i = 0; i < len; i ++) { f[s1[i] - 'a'] ++; f[s2[i] - 'a'] --; }
    
    for (int i = 0; i < 26; i ++) if (f[i] != 0) return false;
    
    for (int i = 1; i < len; i ++) {
        bool ret = isScramble(s1.substr(0, i), s2.substr(0, i)) 
        && isScramble(s1.substr(i, len - i), s2.substr(i, len - i));
        
        ret = ret || ( isScramble(s1.substr(0, i), s2.substr(len - i, i))
        && isScramble(s1.substr(i, len - i), s2.substr(0, len - i)) );
        
        if (ret) return ret;
    }
    
    return false;
  }
};
