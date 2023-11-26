class Solution {
public:
  long long beautifulSubstrings(string s, int k) {
    int kk = 1;
    for (int p = 2; k > 1; ++p) {
      int r = 0;
      while (k % p == 0) {
        k /= p;
        ++r;
      }
      r = (r + 1) / 2;
      while (r > 0) {
        kk *= p;
        --r;
      }
    }

    static const string vowels = "aeiou";
    const int n = s.size();
    vector<unordered_map<int, int>> v(kk);
    int c = 0, d = 0;
    long long ret = 0;
    ++v[c][d];
    for (int i = 0; i < n; ++i) {
      if (vowels.find(s[i]) != string::npos) {
        c = (c + 1) % kk;
        ++d;
      }
      else {
        --d;
      }
      auto& w = v[c][d];
      ret += w++;
    }
    return ret;
  }
};
