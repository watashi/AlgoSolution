class Solution {
public:
  bool makeStringsEqual(string s, string target) {
    bool x = s.find('1') == string::npos;
    bool y = target.find('1') == string::npos;
    return x == y;
  }
};
