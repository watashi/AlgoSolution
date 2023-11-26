class Solution {
public:
  int beautifulSubstrings(string s, int k) {
    static const string vowels = "aeiou";
    const int n = s.size();
    vector<int> v;
    v.reserve(n + 1);
    v.push_back(0);
    for (char c : s) {
      v.push_back(v.back());
      if (vowels.find(c) != string::npos) {
        ++v.back();
      }
    }
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        int x = v[j] - v[i];
        int y = j - i - x;
        if (x == y && (x * y) % k == 0) {
          ++ret;
        }
      }
    }
    return ret;
  }
};
