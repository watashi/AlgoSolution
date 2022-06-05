class Solution {
public:
  int partitionArray(vector<int>& nums, int k) {
    auto v = nums;
    auto ret = 0;
    sort(v.begin(), v.end());
    while (!v.empty()) {
      ++ret;
      auto x = v.back() - k;
      do {
        v.pop_back();
      } while (!v.empty() && v.back() >= x);
    }
    return ret;
  }
};
