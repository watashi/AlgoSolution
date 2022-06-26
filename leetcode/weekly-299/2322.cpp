class Solution {
public:
  vector<vector<int>> e;
  vector<int> val, par, x;

  void dfs(int v, int p) {
    par[v] = p;
    x[v] = val[v];
    for (int w : e[v]) {
      if (w != p) {
        dfs(w, v);
        x[v] ^= x[w];
      }
    }
  }

  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    val = nums;
    par = vector<int>(n);
    x = vector<int>(n, 0);
    e = vector<vector<int>>(n);
    for (const auto& i : edges) {
      e[i[0]].push_back(i[1]);
      e[i[1]].push_back(i[0]);
    }
    dfs(0, 0);

    vector<vector<bool>> ancestor(n, vector<bool>(n, false));
    for (int i = 1; i < n; ++i) {
      for (int j = par[i]; j != 0; j = par[j]) {
        ancestor[i][j] = true;
      }
      ancestor[i][0] = true;
    }

    int ans = numeric_limits<int>::max();
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < i; ++j) {
        int xa, xb;
        if (ancestor[i][j]) {
          xa = x[i];
          xb = x[i] ^ x[j];
        }
        else if (ancestor[j][i]) {
          xa = x[j];
          xb = x[i] ^ x[j];
        }
        else {
          xa = x[i];
          xb = x[j];
        }
        int xc = x[0] ^ xa ^ xb;
        ans = min(ans, max({ xa, xb, xc }) - min({ xa, xb, xc }));
      }
    }
    return ans;
  }
};
