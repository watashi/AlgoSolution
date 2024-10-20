class Solution {
public:
  vector<string> stringSequence(string target) {
    vector<string> ret;
    string s = "";
    for (char c : target) {
      s.push_back('a');
      for (char i = 'a'; i <= c; ++i) {
        s.back() = i;
        ret.push_back(s);
      }
    }
    return ret;
  }
};
