class Solution {
public:
  vector<int> topsort(int k, const vector<vector<int>>& v) {
    vector<int> d(k, 0);
    vector<vector<int>> e(k);
    for (const auto& i : v) {
      int a = i[0] - 1, b = i[1] - 1;
      e[a].push_back(b);
      ++d[b];
    }

    vector<int> ret;
    queue<int> q;
    for (int i = 0; i < k; ++i) {
      if (d[i] == 0) {
        ret.push_back(i);
        q.push(i);
      }
    }

    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (int i : e[a]) {
        if (--d[i] == 0) {
          ret.push_back(i);
          q.push(i);
        }
      }
    }

    if (ret.size() != k) {
      ret.clear();
    }
    return ret;
  }

  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<int> r = topsort(k, rowConditions), c = topsort(k, colConditions);
    if (r.empty() || c.empty()) {
      return {};
    }
    vector<vector<int>> ret(k, vector<int>(k));
    vector<pair<int, int>> pos(k);
    for (int i = 0; i < k; ++i) {
      pos[r[i]].first = i;
      pos[c[i]].second = i;
    }
    for (int i = 0; i < k; ++i) {
      ret[pos[i].first][pos[i].second] = i + 1;
    }
    return ret;
  }
};
