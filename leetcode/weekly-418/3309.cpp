class Solution {
public:
  int maxGoodNumber(vector<int>& nums) {
    vector<int> v(nums.begin(), nums.end());
    sort(v.begin(), v.end());

    int ret = 0;
    do {
      int tmp = 0;
      for (int i : v) {
        int bin = 1;
        while (bin <= i) {
          bin <<= 1;
        }
        tmp = tmp * bin + i;
      }
      ret = max(ret, tmp);
    } while (next_permutation(v.begin(), v.end()));
    return ret;
  }
};
