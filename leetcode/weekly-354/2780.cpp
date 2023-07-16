class Solution {
public:
  int minimumIndex(vector<int>& nums) {
    int dom = -1, cnt = 0;
    for (int i : nums) {
      if (i == dom) {
        ++cnt;
      }
      else if (--cnt < 0) {
        dom = i;
        cnt = 1;
      }
    }
    cnt = count(nums.begin(), nums.end(), dom);
    int tmp = 0;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      tmp += nums[i - 1] == dom ? 1 : 0;
      if (tmp * 2 > i && (cnt - tmp) * 2 > (n - i)) {
        return i - 1;
      }
    }
    return -1;
  }
};
