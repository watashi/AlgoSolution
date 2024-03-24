class Solution {
public:
  int minOperations(int k) {
    int ret = k - 1;
    for (int i = 0; i < k; ++i) {
      int j = (k + i) / (i + 1);
      ret = min(ret, i + j - 1);
    }
    return ret;
  }
};
