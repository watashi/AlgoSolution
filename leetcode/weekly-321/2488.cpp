class Solution {
public:
  int countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int pos = find(nums.begin(), nums.end(), k) - nums.begin();

    map<int, int> mp;
    int tmp = 0;
    ++mp[tmp];
    for (int i = pos + 1; i < n; ++i) {
      if (nums[i] > k) {
        ++tmp;
      }
      else {
        --tmp;
      }
      ++mp[tmp];
    }

    int ans = 0;
    tmp = 0;
    ans += mp[tmp] + mp[tmp + 1];
    for (int i = pos - 1; i >= 0; --i) {
      if (nums[i] > k) {
        --tmp;
      }
      else {
        ++tmp;
      }
      ans += mp[tmp] + mp[tmp + 1];
    }

    return ans;
  }
};
