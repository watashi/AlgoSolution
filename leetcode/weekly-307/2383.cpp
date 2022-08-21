class Solution {
public:
  int minNumberOfHours(int a, int b, vector<int>& as, vector<int>& bs) {
    int ret = max(0, accumulate(as.begin(), as.end(), 1) - a);
    for (int i : bs) {
      if (b <= i) {
        ret += i + 1 - b;
        b = i + 1;
      }
      b += i;
    }
    return ret;
  }
};
