class Solution {
public:
  int minSwaps(string s) {
    int n = s.size(), d = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '[') {
        ++d;
      } else if (d == 0) {
        ++ans;
        ++d;
      } else {
        --d;
      }
    }
    return ans;
  }
};
