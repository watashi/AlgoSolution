class Solution {
public:
  vector<bool> mark;
  vector<int> v, d;
  vector<vector<int>> e;

  int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int n = coins.size();
    v = coins;
    d = vector<int>(n, 0);
    e = vector<vector<int>>(n);
    for (const auto& i : edges) {
      int a = i[0], b = i[1];
      e[a].push_back(b);
      e[b].push_back(a);
      ++d[a];
      ++d[b];
    }

    vector<bool> mark(n, false);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (d[i] == 1 && v[i] == 0) {
        mark[i] = true;
        q.push(i);
      }
    }
    while (!q.empty()) {
      int a = q.front();
      // errf("X %d\n", a);
      q.pop();
      for (int b : e[a]) {
        if (mark[b]) {
          continue;
        }
        --d[b];
        if (d[b] == 1 && v[b] == 0) {
          mark[b] = true;
          q.push(b);
        }
      }
    }

    for (int k = 0; k < 2; ++k) {
      vector<int> w;
      for (int i = 0; i < n; ++i) {
        if (!mark[i] && d[i] == 1) {
          mark[i] = true;
          w.push_back(i);
        }
      }
      for (int a : w) {
        // errf("%d %d\n", k, a);
        for (int b : e[a]) {
          if (!mark[b]) {
            --d[b];
          }
        }
      }
    }

    int ret = count(mark.begin(), mark.end(), false);
    return max(2 * (ret - 1), 0);
  }
};
