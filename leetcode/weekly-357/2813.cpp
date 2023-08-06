class Solution {
public:
  long long findMaximumElegance(vector<vector<int>>& items, int k) {
    auto v = items;
    sort(v.begin(), v.end());
    set<int> used;
    long long profit = 0;
    vector<int> extra;
    for (int i = 0; i < k; ++i) {
      int p = v.back()[0], c = v.back()[1];
      v.pop_back();
      profit += p;
      if (!used.insert(c).second) {
        extra.push_back(p);
      }
    }
    long long ret = profit + (long long)used.size() * (long long)used.size();
    while (!extra.empty() && !v.empty()) {
      int p = v.back()[0], c = v.back()[1];
      v.pop_back();
      if (used.insert(c).second) {
        profit -= extra.back();
        extra.pop_back();
        profit += p;
        ret = max(ret, profit + (long long)used.size() * (long long)used.size());
      }
    }
    return ret;
  }
};
