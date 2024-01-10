class Solution {
public:
  int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> a(nums1.begin(), nums1.end());
    unordered_set<int> b(nums2.begin(), nums2.end());
    int c = 0;
    for (int i : a) {
      if (b.count(i) > 0) {
        ++c;
      }
    }
    int m = (int)nums1.size() / 2;
    int ca = (int)a.size() - c, cb = (int)b.size() - c;
    int ret = 0;
    ret += min(m, ca);
    ca = m - min(m, ca);
    ret += min(m, cb);
    cb = m - min(m, cb);
    ret += min(c, ca + cb);
    return ret;
  }
};
