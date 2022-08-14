class Solution {
public:
  int gao(const int d[], int n, int used) {
    if (n == 0) {
      return 1;
    }
    else {
      int ret = 0;
      int used_count = __builtin_popcount(used);
      for (int i = used == 0 ? 1 : 0; i < *d; ++i) {
        if ((used >> i) & 1) {
          continue;
        }
        int tmp = 1;
        for (int j = 1; j < n; ++j) {
          tmp *= 10 - used_count - j;
        }
        ret += tmp;
      }
      if (((used >> *d) & 1) == 0) {
        ret += gao(d + 1, n - 1, used | (1 << *d));
      }
      return ret;
    }
  }

  int countSpecialNumbers(int n) {
    vector<int> ds;
    while (n > 0) {
      ds.push_back(n % 10);
      n /= 10;
    }
    reverse(ds.begin(), ds.end());
    int ans = 0;
    for (int i = 1; i < (int)ds.size(); ++i) {
      int tmp = 9;
      for (int j = 1; j < i; ++j) {
        tmp *= 10 - j;
      }
      ans += tmp;
    }
    ans += gao(ds.data(), ds.size(), 0);
    return ans;
  }
};
