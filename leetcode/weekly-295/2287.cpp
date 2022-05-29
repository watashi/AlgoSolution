class Solution {
public:
  int rearrangeCharacters(string s, string target) {
    map<int, int> a, b;
    for (char c : s) {
      ++a[c];
    }
    for (char c : target) {
      ++b[c];
    }
    int ret = s.size();
    for (const auto& i : b) {
      ret = min(ret, a[i.first] / i.second);
    }
    return ret;
  }
};
