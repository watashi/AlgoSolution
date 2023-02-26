class Solution {
public:
  vector<int> leftRigthDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> ls(n + 1, 0), rs(n + 1, 0);
    partial_sum(nums.begin(), nums.end(), ls.data() + 1);
    partial_sum(nums.rbegin(), nums.rend(), rs.data() + 1);
    ls.pop_back();
    rs.pop_back();
    reverse(rs.begin(), rs.end());
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
      ret.push_back(abs(ls[i] - rs[i]));
    }
    return ret;
  }
};
