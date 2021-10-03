class Solution {
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    int m = (int)rolls.size();
    int sum = (m + n) * mean - accumulate(rolls.begin(), rolls.end(), 0);
    int div = sum / n, rem = sum % n;
    if (div >= 1 && (div <= 5 || div == 6 && rem == 0)) {
      vector<int> ret(n, div);
      fill(ret.begin(), ret.begin() + rem, div + 1);
      return ret;
    } else {
      return vector<int>();
    }
  }
};
