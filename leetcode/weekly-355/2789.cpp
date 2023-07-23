
class Solution {
public:
  long long maxArrayValue(vector<int>& nums) {
    vector<int> v = nums;
    long long ret = 0;
    reverse(v.begin(), v.end());
    for (int i : v) {
      if (i <= ret) {
        ret += i;
      }
      else {
        ret = i;
      }
    }
    return ret;
  }
};
