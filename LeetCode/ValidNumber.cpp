/**
    Validate if a given string is numeric.

    Some examples:
    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true

    Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

 */

class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int signCnt = 0, eCnt = 0, dotCnt = 0, numCnt = 0, spaceCnt = 0;
        
        if (!s || s[0] == '\0') return false;
        
        while (*s != '\0') {
            if (*s == '+' || *s == '-') {
                if ( ++ signCnt > 1) return false;
                if (numCnt > 0) return false; // 1+1 is false, 1e1+1 is false
            } else if (*s == '.') {
                if ( ++ dotCnt > 1) return false;
                if (spaceCnt > 0) return false;
                signCnt ++; // .+8 is false, sign could only in the beginning or after e
            } else if (*s == 'e') {
                if (numCnt <= 0) return false;   // e3 is false
                if ( ++ eCnt > 1) return false;  
                if (spaceCnt > 0) return false;  // extra space is false
                numCnt = 0;  // 0e is false
                signCnt = 0; // could add sign after e
                dotCnt ++;   // no dot after e
            } else if (*s >= '0' && *s <= '9') {
                numCnt ++;
                if (spaceCnt > 0) return false;  // extra space is false
            } else if (*s == ' ') {
                if (signCnt > 0 || eCnt > 0 || dotCnt > 0 || numCnt > 0) spaceCnt ++;
            } else return false;
            
            s ++;
        }
        
        if (numCnt <= 0) return false;
        
        return true;
    }
};