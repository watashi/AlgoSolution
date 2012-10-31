#include <cstdio>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007LL;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int w, h;
  long long s = 0;

  scanf("%d%d", &w, &h);
  ++w;
  ++h;
  for (int x0 = 0; x0 < 2; ++x0) {
    for (int y0 = 0; y0 < 2; ++y0) {
      int z0 = ((w + 1 - x0) / 2) * ((h + 1 - y0) / 2);
      for (int x1 = 0; x1 < 2; ++x1) {
        for (int y1 = 0; y1 < 2; ++y1) {
          int z1 = ((w + 1 - x1) / 2) * ((h + 1 - y1) / 2);
          for (int x2 = 0; x2 < 2; ++x2) {
            for (int y2 = 0; y2 < 2; ++y2) {
              int z2 = ((w + 1 - x2) / 2) * ((h + 1 - y2) / 2);
              if (((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)) % 2 == 0) {
                s += 1LL * z0 * z1 % MOD * z2 % MOD;
              }
            }
          }
        }
      }
    }
  }
  for (int i = 1; i < w; ++i) {
    for (int j = 1; j < h; ++j) {
      s -= 12LL * (w - i) * (h - j) * gcd(i, j) % MOD;
    }
  }
  s -= 1LL * w * w * w % MOD * h % MOD;
  s -= 1LL * h * h * h % MOD * w % MOD;
  s += 1LL * w * h % MOD;
  s = (s % MOD + MOD) % MOD;
  printf("%d\n", (int)s);

  return 0;
}

