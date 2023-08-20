class Solution {
public:
  int longestEqualSubarray(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < (int)nums.size(); ++i) {
      mp[nums[i]].push_back(i);
    }
    int ret = 0;
    for (const auto& g: mp) {
      const auto& v = g.second;
      for (int i = 0, j = 0; j < (int)v.size(); ++i) {
        while (j < (int)v.size() && v[j] - v[i] + 1 <= j - i + 1 + k) {
          ++j;
        }
        ret = max(ret, j - i);
      }
    }
    return ret;
  }
};
