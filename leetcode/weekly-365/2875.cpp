class Solution {
public:
  int minSizeSubarray(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int64_t> a(nums.begin(), nums.end());
    int64_t s = accumulate(a.begin(), a.end(), 0LL);
    a.insert(a.end(), nums.begin(), nums.end());
    int64_t t = target % s;
    int ret = n;
    unordered_map<int64_t, int> m;
    int64_t tmp = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
      m[tmp] = i;
      if (m.count(tmp - t) != 0) {
        ret = min(ret, i - m[tmp - t]);
      }
      tmp += a[i];
    }
    if (ret < n) {
      return (target / s) * n + ret;
    }
    else {
      return -1;
    }
  }
};
