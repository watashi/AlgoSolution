class Solution {
public:
  int maximumSum(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    for (int i : nums) {
      int k = 0;
      for (int j = i; j > 0; j /= 10) {
        k += j % 10;
      }
      mp[k].push_back(i);
    }
    int ret = -1;
    for (auto& i : mp) {
      auto& v = i.second;
      if (v.size() > 1) {
        sort(v.rbegin(), v.rend());
        ret = max(ret, v[0] + v[1]);
      }
    }
    return ret;
  }
};
