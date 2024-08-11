class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> next(n);
    iota(next.begin(), next.end(), 1);
    int d = n - 1;
    vector<int> ret;
    for (const auto& q : queries) {
      int a = q[0], b = q[1];
      while (next[a] < b) {
        int c = next[a];
        next[a] = next[c];
        next[c] = n + 1;
        --d;
      }
      ret.push_back(d);
    }
    return ret;
  }
};
