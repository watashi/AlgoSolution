class Solution {
public:
  static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    int g = 0;
    for (int i : numsDivide) {
      g = gcd(i, g);
    }
    vector<int> v = nums;
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
      if (g % v[i] == 0) {
        return i;
      }
    }
    return -1;
  }
};
