class Solution {
public:
  static constexpr int64_t MOD = 1000000007;

  static unordered_set<int> dists(int n, const vector<int>& v) {
    vector<int> w = v;
    w.push_back(1);
    w.push_back(n);
    sort(w.begin(), w.end());
    unordered_set<int> st;
    for (int i = 0; i < (int)w.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        st.insert(w[i] - w[j]);
      }
    }
    return st;
  }

  int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    int ret = -1;
    auto x = dists(m, hFences), y = dists(n, vFences);
    for (auto i : x) {
      if (y.count(i) > 0) {
        ret = max(ret, i);
      }
    }
    if (ret < 0) {
      return ret;
    }
    return (int)(1LL * ret * ret % MOD);
  }
};
