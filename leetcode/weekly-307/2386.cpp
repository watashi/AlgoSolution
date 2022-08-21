class Solution {
public:
  long long kSum(vector<int>& nums, int k) {
    int64_t best = 0;
    for (int& i : nums) {
      if (i < 0) {
        i = -i;
      }
      else {
        best += i;
      }
    }
    sort(nums.begin(), nums.end());
    if (nums.size() > k) {
      nums.resize(k);
    }

    vector<int64_t> s, a, b;
    a.reserve(k);
    b.reserve(k);
    a.push_back(0);
    s.resize(2 * k);
    for (int num : nums) {
      b = a;
      for (int64_t& i : b) {
        i += num;
      }
      int c = merge(a.begin(), a.end(), b.begin(), b.end(), s.begin()) - s.begin();
      c = min(c, k);
      a.resize(c);
      copy(s.begin(), s.begin() + c, a.begin());
    }
    return best - a[k - 1];
  }
};
