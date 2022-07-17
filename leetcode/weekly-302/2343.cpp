class Solution {
public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int m = nums[0].size();
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    vector<vector<int>> ranks;
    ranks.push_back(v);
    for (int i = 1; i <= m; ++i) {
      vector<vector<int>> vv(10);
      for (int j : v) {
        vv[nums[j][m - i] - '0'].push_back(j);
      }
      v.clear();
      for (const auto& j : vv) {
        v.insert(v.end(), j.begin(), j.end());
      }
      ranks.push_back(v);
    }

    vector<int> ret;
    for (const auto& i : queries) {
      ret.push_back(ranks[i[1]][i[0] - 1]);
    }
    return ret;
  }
};
