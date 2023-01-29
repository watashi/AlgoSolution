class Solution {
public:
  long long putMarbles(vector<int>& w, int k) {
    vector<int64_t> cost;
    for (int i = 1; i < (int)w.size(); ++i) {
      cost.push_back(w[i - 1] + w[i]);
    }
    sort(cost.begin(), cost.end());
    // note: when k == 1:
    // * `cost.data() + (k - 1)` is fine
    // * `cost.data() + k - 1` can result in error:
    //   UndefinedBehaviorSanitizer: applying non-zero offset to null pointer
    k -= 1;
    int64_t x = accumulate(cost.begin(), cost.begin() + k, 0LL);
    int64_t y = accumulate(cost.rbegin(), cost.rbegin() + k, 0LL);
    return y - x;
  }
};
