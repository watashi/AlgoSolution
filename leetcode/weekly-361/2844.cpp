class Solution {
public:
  int gao(string s, char a, char b) {
    int n = (int)s.size();
    int p = n - 1;
    while (p >= 0 && s[p] != b) {
      --p;
    }
    --p;
    while (p >= 0 && s[p] != a) {
      --p;
    }
    return p >= 0 ? n - p - 2 : n;
  }

  int minimumOperations(string num) {
    int ret = num.size() - count(num.begin(), num.end(), '0');
    ret = min(ret, gao(num, '0', '0'));
    ret = min(ret, gao(num, '2', '5'));
    ret = min(ret, gao(num, '5', '0'));
    ret = min(ret, gao(num, '7', '5'));
    return ret;
  }
};
