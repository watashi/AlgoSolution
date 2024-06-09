class Solution {
public:
  int maxTotalReward(vector<int>& rewardValues) {
    auto v = rewardValues;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    bitset<50005> ok, mask;
    int end = 0;
    ok[0] = true;
    for (int i : v) {
      while (end < i) {
        mask[end++] = true;
      }
      ok |= (ok & mask) << i;
    }
    int k = v.back() - 1;
    while (k >= 0 && !ok[k]) {
      --k;
    }
    return v.back() + k;
  }
};
