class Solution {
public:
  int maxFrequency(vector<int>& nums, int k) {
    unordered_set<int> froms(nums.begin(), nums.end());
    int ck = count(nums.begin(), nums.end(), k);
    int ret = ck;
    for (int from : froms) {
      if (from == k) {
        continue;
      }
      int diff = 0, mindiff = 0, maxdiff = 0;
      for (int i : nums) {
        if (i == from) {
          ++diff;
        }
        else if (i == k) {
          --diff;
        }
        diff = max(diff, 0);
        maxdiff = max(maxdiff, diff);
      }
      ret = max(ret, ck + maxdiff);
    }
    return ret;
  }
};
