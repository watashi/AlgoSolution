class Solution {
public:
  bool canAliceWin(vector<int>& nums) {
    int d = 0;
    for (int i : nums) {
      if (i < 10) {
        d -= i;
      }
      else {
        d += i;
      }
    }
    return d != 0;
  }
};
