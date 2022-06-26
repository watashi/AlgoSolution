class Solution {
public:
  static int gao(const vector<int>& a, const vector<int>& b) {
    int s = accumulate(a.begin(), a.end(), 0);
    int md = 0, d = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
      d = max(0, d + b[i] - a[i]);
      md = max(md, d);
    }
    return s + md;
  }

  int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
    return max(gao(nums1, nums2), gao(nums2, nums1));
  }
};
