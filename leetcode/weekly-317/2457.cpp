class Solution {
public:
  long long TEN[18];
  long long ans;

  long long makeIntegerBeautiful(long long n, int target) {
    TEN[0] = 1;
    for (int i = 1; i < 18; ++i) {
      TEN[i] = TEN[i - 1] * 10;
    }

    int w = 0;
    for (auto i = n; i > 0; i /= 10) {
      ++w;
    }

    long long ans = TEN[w];
    for (int i = w - 1; i >= 0; --i) {
      auto d = n / TEN[i] % 10;
      if (d < 9 && target > d) {
        ans = min(ans, (n / TEN[i] + 1) * TEN[i]);
      }
      target -= d;
    }
    if (target >= 0) {
      ans = n;
    }
    return ans - n;
  }
};
