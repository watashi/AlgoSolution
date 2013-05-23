class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int N = s.length();
        if (N <= 0) return 0;  // Case 0...
        
        int b = 0, e = 1, ans = 1;
        int h[256];
        memset(h, 0, sizeof(h));
        h[s[0]] = 1;   // Initial case...
        
        while (e < N) {
            if (e < N && h[s[e]] == 0) {
                h[s[e]] = 1;
                ans = max(ans, e - b + 1);
            } else {
                while (b < N && s[b] != s[e]) {
                    h[s[b ++]] = 0;
                }
                b ++;
            }
            
            e ++;
        }
        
        return ans;
    }
};