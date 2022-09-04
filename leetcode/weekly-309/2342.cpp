class Solution {
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<pair<int64_t, int64_t>> v;
    for (const auto& i : meetings) {
      v.emplace_back(i[0], i[1] - i[0]);
    }
    sort(v.begin(), v.end());

    vector<int> cnt(n, 0);
    set<int> free;
    set<pair<int64_t, int>> pending;
    for (int i = 0; i < n; ++i) {
      free.emplace(i);
    }

    int64_t ts = 0;
    for (const auto& i : v) {
      ts = max(ts, i.first);
      while (!pending.empty() && pending.begin()->first <= ts) {
        free.insert(pending.begin()->second);
        pending.erase(pending.begin());
      }
      if (free.empty()) {
        ts = pending.begin()->first;
      }
      while (!pending.empty() && pending.begin()->first <= ts) {
        free.insert(pending.begin()->second);
        pending.erase(pending.begin());
      }
      auto k = *free.begin();
      free.erase(free.begin());
      ++cnt[k];
      pending.emplace(ts + i.second, k);
    }
    return max_element(cnt.begin(), cnt.end()) - cnt.begin();
  }
};
