class Solution {
public:
  string digitSum(string s, int k) {
    while (s.length() > k) {
      string t;
      for (int i = 0; i < s.length(); i += k) {
        int x = 0;
        for (int j = 0; j < k && i + j < s.length(); ++j) {
          x += s[i + j] - '0';
        }
        t += std::to_string(x);
      }
      s = t;
    }
    return s;
  }
};
