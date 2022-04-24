class Solution {
public:
  vector<int> intersection(vector<vector<int>>& nums) {
    int c = nums.size();
    map<int, int> m;
    for (const auto& i : nums) {
      for (auto j : i) {
        ++m[j];
      }
    }
    vector<int> v;
    for (const auto& i : m) {
      if (i.second == c) {
        v.push_back(i.first);
      }
    }
    return v;
  }
};
