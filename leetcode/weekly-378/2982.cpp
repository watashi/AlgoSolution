class Solution {
public:
  struct Rec {
    int fst = -1;
    int snd = -1;
    int cnt = 3;
  };

  int maximumLength(string s) {
    int n = s.length();
    vector<Rec> v(26);
    for (int i = 1, c = 1; i <= n; ++i) {
      if (i < n && s[i] == s[i - 1]) {
        ++c;
        continue;
      }
      auto& r = v[s[i - 1] - 'a'];
      if (c > r.fst) {
        r.cnt = 1;
        r.snd = r.fst;
        r.fst = c;
      }
      else if (c == r.fst) {
        ++r.cnt;
      }
      else if (c > r.snd) {
        r.snd = c;
      }
      c = 1;
    }
    int ret = -1;
    for (const auto& r : v) {
      if (r.cnt >= 3) {
        ret = max(ret, r.fst);
      }
      else if (r.cnt >= 2) {
        ret = max(ret, r.fst - 1);
      }
      else {
        ret = max({ ret, r.fst - 2, r.snd });
      }
    }
    if (ret <= 0) {
      return -1;
    }
    return ret;
  }
};
