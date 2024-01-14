class Solution {
public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    int n = s.length(), na = a.length(), nb = b.length();
    vector<int> okb;
    for (int i = 0; i + nb <= n; ++i) {
      if (string_view(&s[i], nb) == b) {
        okb.push_back(i);
      }
    }
    reverse(okb.begin(), okb.end());

    vector<int> ret;
    for (int i = 0; i + na <= n; ++i) {
      if (string_view(&s[i], na) == a) {
        while (!okb.empty() && okb.back() < i - k) {
          okb.pop_back();
        }
        if (!okb.empty() && okb.back() <= i + k) {
          ret.push_back(i);
        }
      }
    }
    return ret;
  }
};
