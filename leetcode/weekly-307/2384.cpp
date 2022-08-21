class Solution {
public:
  string largestPalindromic(string num) {
    map<char, int> m;
    for (char c : num) {
      ++m[c];
    }
    string pre, mid;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
      for (int i = 2; i <= it->second; i += 2) {
        pre.push_back(it->first);
      }
      if (mid.empty() && it->second % 2 != 0) {
        mid.push_back(it->first);
      }
    }
    if (!pre.empty() && pre[0] == '0') {
      if (mid.empty()) {
        mid.push_back('0');
      }
      return mid;
    }
    else {
      string ret = pre;
      ret += mid;
      reverse(pre.begin(), pre.end());
      ret += pre;
      return ret;
    }
  }
};
