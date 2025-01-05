class Solution {
public:
  vector<int> maximumWeight(vector<vector<int>>& intervals) {
    vector<int> todo;
    todo.resize(intervals.size());
    iota(todo.begin(), todo.end(), 0);
    sort(todo.begin(), todo.end(), [&intervals](int i, int j) {
      return intervals[i][1] < intervals[j][1];
    });

    using Value = pair<int64_t, vector<int>>;
    const Value INF(1, {});
    vector<pair<int, Value>> dp[5];
    for (int i : todo) {
      const int l = intervals[i][0], r = intervals[i][1], w = -intervals[i][2];
      for (int k = 1; k <= 4; ++k) {
        auto it = lower_bound(dp[k - 1].begin(), dp[k - 1].end(), make_pair(l - 1, INF));
        Value value;
        if (it == dp[k - 1].begin()) {
          value = make_pair(w, vector<int>{i});
        }
        else {
          --it;
          value = it->second;
          value.first += w;
          value.second.push_back(i);
          sort(value.second.begin(), value.second.end());
        }
        while (!dp[k].empty() && dp[k].back().first == r && dp[k].back().second > value) {
          dp[k].pop_back();
        }
        if (dp[k].empty() || (dp[k].back().second > value)) {
          dp[k].emplace_back(r, value);
        }
      }
    }
    return dp[4].back().second.second;
  }
};
