class Solution {
public:
  int smallestNumber(int n) {
    int ret = 1;
    while (ret < n) {
      ret = ret * 2 + 1;
    }
    return ret;
  }
};

