class Solution {
public:
  int valueAfterKSeconds(int n, int k) {
    static constexpr int MOD = 1000000007;
    vector<int> v(n, 1);
    for (int i = 0; i < k; ++i) {
      for (int j = 1; j < n; ++j) {
        v[j] += v[j - 1];
        if (v[j] >= MOD) {
          v[j] -= MOD;
        }
      }
    }
    return v.back();
  }
};
