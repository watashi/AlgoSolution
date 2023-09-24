class Solution {
public:
  string maximumOddBinaryNumber(string s) {
    int one = count(s.begin(), s.end(), '1');
    int zero = (int)s.size() - one;
    return string(one - 1, '1') + string(zero, '0') + "1";
  }
};
