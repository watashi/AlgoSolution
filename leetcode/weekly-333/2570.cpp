class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int, int> m;
    for (const auto& i : nums1) {
      m[i[0]] += i[1];
    }
    for (const auto& i : nums2) {
      m[i[0]] += i[1];
    }
    vector<vector<int>> ret;
    for (const auto& i : m) {
      ret.push_back({ i.first, i.second });
    }
    return ret;
  }
};
