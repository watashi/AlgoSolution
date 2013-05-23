/**
  Given a string s, partition s such that every substring of the partition is a palindrome.

  Return all possible palindrome partitioning of s.

  For example, given s = "aab",
  Return

    [
      ["aa","b"],
      ["a","a","b"]
    ]
  
  */
class Solution {
public:
  vector<vector<string> > ans;
  
  void recursive(const string & s, int position, vector<string> &v, vector<vector<bool> > &matrix) {
    if (position >= s.length()) {
      ans.push_back(v);
      return;
    }
    
    for (int len = 1; len < s.length() - position + 1; len ++) {
      if (matrix[position][position + len - 1]) {
        v.push_back(s.substr(position, len));
        recursive(s, position + len, v, matrix);
        v.pop_back();
      }
    }
  }
  
  void initMatrix(const string & s, vector<vector<bool> > &matrix)
  {   
    for (int len = 1; len <= s.length(); len ++) {
      for (int pos = 0; pos < s.length() - len + 1; pos ++) {
        if (s[pos] == s[pos + len - 1]) {
          if (pos + 1 >= pos + len - 2 || matrix[pos + 1][pos + len - 2]) {
            matrix[pos][pos + len - 1] = true;
          }
        }
      }
    }
  }
  
  vector<vector<string> > partition(string s) 
  {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> v;
    ans.clear();
    vector<vector<bool> > matrix(s.length(), vector<bool>(s.length(), false));
    initMatrix(s, matrix);
    recursive(s, 0, v, matrix);
    return ans;
  }
};