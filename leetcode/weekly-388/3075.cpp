class Solution {
public:
  long long maximumHappinessSum(vector<int>& h, int k) {
    sort(h.rbegin(), h.rend());
    long long ret = 0;
    for (int i = 0; i < k; ++i) {
      ret += max(0, h[i] - i);
    }
    return ret;
  }
};
