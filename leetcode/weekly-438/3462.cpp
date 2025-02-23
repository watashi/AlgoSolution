class Solution {
public:
  long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    vector<int> v;
    for (int i = 0; i < (int)grid.size(); ++i) {
      auto row = grid[i];
      sort(row.rbegin(), row.rend());
      row.resize(limits[i]);
      copy(row.begin(), row.end(), back_inserter(v));
    }
    sort(v.rbegin(), v.rend());
    v.resize(k);
    return accumulate(v.begin(), v.end(), 0LL);
  }
};
