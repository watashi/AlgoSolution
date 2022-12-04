class Solution {
public:
  int magnificentSets(int n, vector<vector<int>>& edges) {
    vector<vector<int>> e(n);
    for (const auto& i : edges) {
      int a = i[0] - 1, b = i[1] - 1;
      e[a].push_back(b);
      e[b].push_back(a);
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      vector<int> d(n, -1);
      queue<int> q;
      int w = i, dd = 0;
      d[i] = 0;
      q.push(i);
      while (!q.empty()) {
        int a = q.front();
        w = min(w, a);
        dd = max(dd, d[a]);
        q.pop();
        for (int b : e[a]) {
          if (d[b] == -1) {
            d[b] = d[a] + 1;
            q.push(b);
          }
          else if (abs(d[a] - d[b]) != 1) {
            return -1;
          }
        }
      }
      mp[w] = max(mp[w], dd + 1);
    }
    int ret = 0;
    for (const auto& i : mp) {
      ret += i.second;
    }
    return ret;
  }
};
