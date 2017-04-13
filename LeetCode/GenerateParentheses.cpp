class Solution {
public:
    
    void generate(int left, int right, int n, string &s, vector<string> &ans) {
        if (left <= right) return;
        
        if (left == n) {
            ans.push_back(s);
            return;
        }
        
        for (int i = left + right; i < s.length() - 1; i ++) {
            s[i] = '(';
            generate(left + 1, i - left, n, s, ans);
            s[i] = ')';
        }
    }
    
    void generate2(int left, int right, int n, string &s, vector<string> &ans) {
        if (left < right) return;
        
        if (left == n && right == n) {
            ans.push_back(s);
            return;
        }
        
        if (left + right >= s.length()) return;
        
        s[left + right] = '(';
        generate2(left + 1, right, n, s, ans);
        s[left + right] = ')';
        generate2(left, right + 1, n, s, ans);
    }
    
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        string s = string(n, '(') + string(n, ')');
        
        generate(1, 0, n, s, ans);
        //generate2(0, 0, n, s, ans);
        
        return ans;   
    }
};