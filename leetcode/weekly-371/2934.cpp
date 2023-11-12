class Solution {
public:
  static int go(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    int ret = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] <= a.back() && b[i] <= b.back()) {
        continue;
      }
      else if (a[i] <= b.back() && b[i] <= a.back()) {
        ++ret;
      }
      else {
        return n + 1;
      }
    }
    return ret;
  }

  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int ret = go(nums1, nums2);
    swap(nums1.back(), nums2.back());
    ret = min(ret, 1 + go(nums1, nums2));
    if (ret > (int)nums1.size()) {
      ret = -1;
    }
    return ret;
  }
};
