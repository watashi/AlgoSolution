class Solution {
public:
  long long gao(const vector<int>& a, int minK, int maxK) {
    long long ret = 0;
    int n = a.size(), k1 = n, k2 = n;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] == minK) {
        k1 = i;
      }
      if (a[i] == maxK) {
        k2 = i;
      }
      ret += n - max(k1, k2);
    }
    return ret;
  }

  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long ret = 0;
    vector<int> v;
    for (int i : nums) {
      if (i < minK || i > maxK) {
        ret += gao(v, minK, maxK);
        v.clear();
      }
      else {
        v.push_back(i);
      }
    }
    ret += gao(v, minK, maxK);
    return ret;
  }
};
