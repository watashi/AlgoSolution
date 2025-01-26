class Solution {
public:
  int countPartitions(vector<int>& nums) {
    int s = accumulate(nums.begin(), nums.end(), 0);
    if (s % 2 == 0) {
      return (int)nums.size() - 1;
    }
    else {
      return 0;
    }
  }
};
