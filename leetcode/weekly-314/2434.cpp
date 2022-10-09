class Solution {
public:
  string robotWithString(string s) {
    string m, t, ret;
    m = s;
    for (int i = (int)s.size() - 1; i > 0; --i) {
      m[i - 1] = min(m[i - 1], m[i]);
    }
    for (int i = 0; i < (int)s.size(); ++i) {
      while (!t.empty() && t.back() <= m[i]) {
        ret += t.back();
        t.pop_back();
      }
      t.push_back(s[i]);
    }
    while (!t.empty()) {
      ret += t.back();
      t.pop_back();
    }
    return ret;
  }
};
