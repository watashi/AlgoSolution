#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const long long INF = 4001002003004LL;

int main() {
  int re;
  long long n, k, p, w;
  vector<long long> v;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%lld%lld%lld", &n, &k, &p);
    w = n % k == 0 ? k : n % k;
    while (true) {
      long long l = 1, r = INF / k;
      while (l < r) {
        long long m = (l + r) / 2;
        if (k * m * 100 < (k * m + w) * p) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      if (n >= k * r + w) {
        w = k * r + w;
      } else {
        break;
      }
    }

    printf("Case #%d: ", ri);
    printf("%lld\n", (n - w) / k + 1);
    fflush(stdout);
  }

  return 0;
}
