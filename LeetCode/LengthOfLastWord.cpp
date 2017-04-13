class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int e = strlen(s) - 1;
        int len = 0;
        
        while (e >= 0 && s[e] == ' ') e --;
        
        while (e >= 0 && s[e] != ' ') {
            len ++;
            e --;
        }
        
        return len;
    }
};