class Solution {
public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    const int n = nums.size();
    unordered_map<int, vector<int>> idx;
    for (int i = 0; i < n; ++i) {
      idx[nums[i]].push_back(i);
    }

    vector<int> dist(n);
    for (const auto& kv : idx) {
      const int k = kv.first;
      const auto& v = kv.second;
      const int m = v.size();
      if (m == 1) {
        dist[v[0]] = -1;
      }
      else {
        for (int i = 0; i < m; ++i) {
          int dl = v[i] - (i == 0 ? v.back() - n : v[i - 1]);
          int dr = (i == m - 1 ? v.front() + n : v[i + 1]) - v[i];
          dist[v[i]] = min(dl, dr);
        }
      }
    }

    vector<int> ret;
    ret.reserve(queries.size());
    for (int q : queries) {
      ret.push_back(dist[q]);
    }
    return ret;
  }
};
