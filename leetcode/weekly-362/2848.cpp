class Solution {
public:
  int numberOfPoints(vector<vector<int>>& nums) {
    vector<bool> v(128, false);
    for (const auto& i : nums) {
      fill(v.begin() + i[0], v.begin() + i[1] + 1, true);
    }
    return count(v.begin(), v.end(), true);
  }
};
