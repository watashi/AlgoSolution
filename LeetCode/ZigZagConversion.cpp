/*
 * TEST mie
    n=4
    P            I           N
    A       L    S       I   G
    Y   A        H   R
    P            I

    N=5
    P              H
    A          S   I
    Y      I       R
    P   L          I   G
    A              N

*/
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows <= 1) return s;
        
        vector<string> ans(nRows, "");
        
        int c = 0, i = 0, N = s.length();
        
        while (i < N) {
            if (nRows == 2 || c % (nRows - 1) == 0) {
                for (int j = 0; j < nRows && i < N; j ++) {
                    ans[j] += string(1, s[i ++]);
                }
            } else {
                ans[nRows - c % (nRows - 1) - 1].push_back(s[i ++]);
            }
            c ++;
        }
        
        string ret = ans[0];
        for (int i = 1; i < nRows; i ++) {
            ret += ans[i];
        }
        
        return ret;
    }
};
