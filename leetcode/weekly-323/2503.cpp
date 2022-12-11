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

static constexpr int DX[] = { 0, 1, 0, -1 };
static constexpr int DY[] = { 1, 0, -1, 0 };

class Solution {
public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, pair<int, int>>> v;
    vector<int64_t> s(m * n, 1);
    vector<bool> mark(m * n, false);
    DisjointSet ds;
    ds.init(m * n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        v.emplace_back(grid[i][j], make_pair(i, j));
      }
    }
    sort(v.begin(), v.end());

    map<int, int64_t> ans;
    for (const auto& i : v) {
      int x = i.second.first;
      int y = i.second.second;
      int z = x * n + y;
      mark[z] = true;
      for (int d = 0; d < 4; ++d) {
        int xx = x + DX[d];
        int yy = y + DY[d];
        int zz = xx * n + yy;
        if (xx < 0 || xx >= m || yy < 0 || yy >= n || !mark[zz]) {
          continue;
        }
        int p = ds.getp(z);
        int pp = ds.getp(zz);
        if (p != pp) {
          ds.setp(pp, p);
          s[p] += s[pp];
        }
      }
      if (mark[0]) {
        ans[i.first] = max(ans[i.first], s[ds.getp(0)]);
      }
    }

    vector<int> ret;
    for (auto q : queries) {
      auto it = ans.lower_bound(q);
      if (it == ans.begin()) {
        ret.push_back(0);
      }
      else {
        --it;
        ret.push_back(it->second);
      }
    }
    return ret;
  }
};
