static constexpr int DX[] = { 0, 1, 0, -1 };
static constexpr int DY[] = { 1, 0, -1, 0 };

struct DisjointSet {
  vector<int> p;

  void init(int n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return i == p[i] ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    p[i] = j;
    return i != j;
  }
};

class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<vector<int>> d(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == 1) {
          d[i][j] = 0;
          q.emplace(i, j);
        }
      }
    }
    vector<pair<int, pair<int, int>>> v;
    while (!q.empty()) {
      auto xy = q.front();
      int x0, y0;
      tie(x0, y0) = xy;
      int dd = d[xy.first][xy.second];
      v.emplace_back(dd, xy);
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int x = x0 + DX[k], y = y0 + DY[k];
        if (0 <= x && x < n && 0 <= y && y < n && d[x][y] == -1) {
          d[x][y] = dd + 1;
          q.emplace(x, y);
        }
      }
    }

    DisjointSet ds;
    ds.init(n * n);
    const int t = n * n - 1;
    while (!v.empty()) {
      int dd = v.back().first, x0, y0;
      tie(x0, y0) = v.back().second;
      v.pop_back();
      d[x0][y0] = -1;
      for (int k = 0; k < 4; ++k) {
        int x = x0 + DX[k], y = y0 + DY[k];
        if (0 <= x && x < n && 0 <= y && y < n && d[x][y] == -1) {
          ds.setp(x * n + y, x0 * n + y0);
        }
      }
      if (ds.getp(0) == ds.getp(t)) {
        return dd;
      }
    }
    return 0;
  }
};
