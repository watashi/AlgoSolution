class Solution {
public:
  bool hasTrailingZeros(vector<int>& nums) {
    return count_if(nums.begin(), nums.end(), [](int i) { return i % 2 == 0;  }) > 1;
  }
};
