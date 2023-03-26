class Solution {
public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int x[] = {numOnes , numZeros , numNegOnes };
    int s = 0;
    for (int i = 0; i < 3; ++i) {
      int y = min(x[i], k);
      k -= y;
      s += y * (1 - i);
    }
    return s;
  }
};
