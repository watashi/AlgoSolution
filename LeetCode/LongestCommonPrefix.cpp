class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans = "";
        
        if (strs.size() <= 0) return ans;
        
        for (int i = 0; i < strs[0].length(); i ++) {
            bool flag = true;
            for (int j = 1; j < strs.size(); j ++) {
                if (strs[0][i] != strs[j][i]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) ans += strs[0][i];
            else break;
        }
        
        return ans;
    }
};