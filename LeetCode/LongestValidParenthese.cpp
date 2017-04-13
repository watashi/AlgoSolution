class Solution {
public:

    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0;
        int count = 0, start = 0;
        
        for (int i = 0; i < s.length(); i ++) {
            count = s[i] == '(' ? count + 1 : count - 1;
            
            if (count < 0) {
                count = 0;
                start = i + 1;
            } else if (count == 0) {
                ans = max(ans, i - start + 1);  
            }
        }

        if (count > 0) {
            count = 0;
            start = s.length() - 1;
            for (int i = s.length() - 1; i >= 0; i --) {
                count = s[i] == ')' ? count + 1 : count - 1;
                
                if (count < 0) {
                    count = 0;
                    start = i - 1;
                } else if (count == 0) {
                    ans = max(ans, start - i + 1);
                }
            }
        }
        
        return ans;
    }
};