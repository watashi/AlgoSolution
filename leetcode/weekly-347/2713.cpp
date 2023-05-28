class Solution {
public:
  int maxIncreasingCells(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size();
    vector<int> rmax(m, 0), cmax(n, 0);
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mp[a[i][j]].emplace_back(i, j);
      }
    }
    for (const auto& g : mp) {
      vector<pair<int, int>> rupd, cupd;
      for (const auto& ij : g.second) {
        int i = ij.first, j = ij.second;
        int k = max(rmax[i], cmax[j]) + 1;
        rupd.emplace_back(i, k);
        cupd.emplace_back(j, k);
      }
      for (const auto& ik : rupd) {
        int i = ik.first, k = ik.second;
        rmax[i] = max(rmax[i], k);
      }
      for (const auto& jk : cupd) {
        int j = jk.first, k = jk.second;
        cmax[j] = max(cmax[j], k);
      }
    }
    return *max_element(rmax.begin(), rmax.end());
  }
};
