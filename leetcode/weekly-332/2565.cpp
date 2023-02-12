class Solution {
public:
  vector<int> minPrefix(const string& s, const string& t) {
    vector<int> ret;
    ret.push_back(0);
    for (int i = 0, j = 0; i < (int)t.size() && j < (int)s.size(); ++i) {
      auto k = s.find(t[i], j);
      if (k == string::npos) {
        break;
      }
      else {
        j = k + 1;
        ret.push_back(j);
      }
    }
    return ret;
  }

  int minimumScore(string s, string t) {
    auto prefix = minPrefix(s, t);
    auto suffix = minPrefix({ s.rbegin(), s.rend() }, { t.rbegin(), t.rend() });
    int n = s.size(), m = t.size();
    int ret = 0;
    for (int i = 0; i < (int)suffix.size(); ++i) {
      while (prefix.back() + suffix[i] > n) {
        prefix.pop_back();
      }
      ret = max(ret, (int)prefix.size() - 1 + i);
    }
    return max(0, m - ret);
  }
};
