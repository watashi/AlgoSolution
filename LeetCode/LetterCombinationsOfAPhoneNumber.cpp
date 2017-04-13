class Solution {
public:
    vector<string> s;
    vector<string> ans;
    
    void init() {
        ans. clear();
        s.push_back("");
        s.push_back("");
        s.push_back("abc");
        s.push_back("def");
        s.push_back("ghi");
        s.push_back("jkl");
        s.push_back("mno");
        s.push_back("pqrs");
        s.push_back("tuv");
        s.push_back("wxyz");
    }
    
    void search(const string &digits, int pos, string & curr) {
        if (pos >= digits.length()) {
            ans.push_back(curr);
            return;
        }
        
        int num = digits[pos] - '0';
        for (int i = 0; i < s[num].length(); i ++) {
            curr += string(1, s[num][i]);
            search(digits, pos + 1, curr);
            curr = curr.substr(0, pos);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        init();
        string curr = "";
        search(digits, 0, curr);
        
        return ans;
    }
};