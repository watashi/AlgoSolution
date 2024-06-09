class Solution {
public:
  int maxTotalReward(vector<int>& rewardValues) {
    auto v = rewardValues;
    sort(v.begin(), v.end());
    const int m = v.back();
    vector<bool> ok(m, false);
    ok[0] = true;
    int maxok = 0;
    int ret = 0;
    for (int i: v) {
      for (int j = 0; j < i; ++j) {
        if (ok[j]) {
          int k = i + j;
          ret = max(ret, k);
          if (k < m) {
            ok[k] = true;
          }
        }
      }
    }
    return ret;
  }
};
