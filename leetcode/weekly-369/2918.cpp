class Solution {
public:
  long long sum(const vector<int>& v) {
    long long ret = 0;
    for (int i : v) {
      ret += max(1, i);
    }
    return ret;
  }

  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    auto s1 = sum(nums1);
    auto s2 = sum(nums2);
    if (s1 == s2) {
      return s1;
    } else if (s1 < s2 && count(nums1.begin(), nums1.end(), 0) > 0) {
      return s2;
    }
    else if (s2 < s1 && count(nums2.begin(), nums2.end(), 0) > 0) {
      return s1;
    }
    else {
      return -1;
    }
  }
};
