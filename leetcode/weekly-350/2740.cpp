class Solution {
public:
  int findValueOfPartition(vector<int>& nums) {
    auto a = nums;
    sort(a.begin(), a.end());
    int ret = a[1] - a[0];
    for (int i = 2; i < (int)a.size(); ++i) {
      ret = min(ret, a[i] - a[i - 1]);
    }
    return ret;
  }
};
