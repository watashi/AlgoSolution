class Solution {
  // a * x + b * y = gcd(a, b) >= 0
  long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
      x = a >= 0 ? 1 : -1;
      y = 0;
      return abs(a);
    }
    else {
      int g = extGcd(b, a % b, y, x);
      y -= a / b * x;
      return g;
    }
  }

  // ASSUME: gcd(a, m) == 1
  long long modInv(long long a, long long m) {
    long long x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
  }

public:
  bool hasSameDigits(string s) {
    int r = 1;
    vector<int> r2 = { 1 }, r5 = { 1 };
    vector<int> v;
    const int n = s.length() - 2;
    v.push_back(r);
    for (int i = 1; i <= n; ++i) {
      // * n + 1 - i
      int x = n + 1 - i;
      while (x % 2 == 0) {
        x /= 2;
        r2.push_back(r2.back() * 2 % 10);
      }
      while (x % 5 == 0) {
        x /= 5;
        r5.push_back(r5.back() * 5 % 10);
      }
      r = r * x % 10;
      // / i
      x = i;
      while (x % 2 == 0) {
        x /= 2;
        r2.pop_back();
      }
      while (x % 5 == 0) {
        x /= 5;
        r5.pop_back();
      }
      r = r * modInv(x, 10) % 10;
      // c(n, i)
      if (r2.size() > 1 && r5.size() > 1) {
        v.push_back(0);
      }
      else {
        v.push_back(r2.back() * r5.back() * r % 10);
      }
    }

    vector<int> w;
    for (int z = 0; z < 2; ++z) {
      int y = 0;
      for (int i = 0; i <= n; ++i) {
        y += v[i] * (s[z + i] - '0');
      }
      w.push_back(y % 10);
    }
    cout << w[0] << " " << w[1] << endl;
    return w[0] == w[1];
  }
};
