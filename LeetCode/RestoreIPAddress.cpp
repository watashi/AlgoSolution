class Solution {
public:
  
  bool isOK(const string & s, int index, int len) {
    if (index + len > s.length() || len > 3) return false;
    
    string ip = s.substr(index, len);
    if (ip[0] == '0' && len > 1) return false;
    if (len == 3) return ip <= "255";
    
    return true;
  }
  
  void search(const string &s, vector<string> &ans, int curr, int index, vector<int> &stk) {
    if (index > s.length() || curr > 4) return;
    
    if (curr == 4) {
      if (index == s.length()) {
        string ret = s.substr(0, stk[0]);
        for (int i = 1; i < stk.size(); i ++) {
            ret += ".";
            ret += s.substr(stk[i - 1], stk[i] - stk[i - 1]);
        }
        ans.push_back(ret);
      }
      return;
    }
    
    for (int len = 1; len <= 3; len ++) {
      if (isOK(s, index, len)) {
        stk[curr] = index + len;
        search(s, ans, curr + 1, index + len, stk);
      }
    }
  }
  
  vector<string> restoreIpAddresses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> ans;
    vector<int> stk(4, 0);
    search(s, ans, 0, 0, stk);
    
    return ans;
  }
};