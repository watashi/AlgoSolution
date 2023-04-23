class Solution {
public:
  vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    vector<int> c_(101, 0);
    int* const c = c_.data() + 50;
    c[0] = x + 1;
    for (int i = 0; i < k - 1; ++i) {
      ++c[nums[i]];
    }
    vector<int> ret;
    for (int i = k - 1; i < (int)nums.size(); ++i) {
      ++c[nums[i]];
      int y = x;
      for (int j = -50; j <= 0; ++j) {
        y -= c[j];
        if (y <= 0) {
          ret.push_back(j);
          break;
        }
      }
      --c[nums[i - (k - 1)]];
    }
    return ret;
  }
};
