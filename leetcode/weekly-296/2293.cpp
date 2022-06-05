class Solution {
public:
  int gao(int n, const int a[], bool left) {
    if (n == 1) {
      return a[0];
    }
    else {
      int m = n / 2;
      int l = gao(m, a, true);
      int r = gao(m, a + m, false);
      if (left) {
        return min(l, r);
      }
      else {
        return max(l, r);
      }
    }
  }

  int minMaxGame(vector<int>& nums) {
    return gao(nums.size(), nums.data(), true);
  }
};
