class Solution {
public:
  int minimumSum(int n, int k) {
    set<int> used;
    int ret = 0;
    for (int i = 1; n > 0; ++i) {
      if (used.count(k - i) == 0) {
        used.insert(i);
        ret += i;
        --n;
      }
    }
    return ret;
  }
};
