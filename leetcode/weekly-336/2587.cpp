class Solution {
public:
  int maxScore(vector<int>& nums) {
    vector<int64_t> a(nums.begin(), nums.end());
    sort(a.rbegin(), a.rend());
    partial_sum(a.begin(), a.end(), a.begin());
    return find_if(a.begin(), a.end(), [](int64_t i) { return i <= 0;  }) - a.begin();
  }
};
