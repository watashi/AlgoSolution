class Solution {
public:
  vector<string> split(const string& s, int k) {
    const int n = s.size();
    const int m = n / k;
    vector<string> ret;
    for (int i = 0; i < n; i += m) {
      ret.push_back(s.substr(i, m));
    }
    return ret;
  }

  bool isPossibleToRearrange(string s, string t, int k) {
    auto a = split(s, k);
    auto b = split(t, k);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
  }
};
