#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int re, n, s, t;
  map<int, int> mp;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &n, &t);
    mp.clear();
    s = 0;
    for (int i = 2; i * i <= n; ++i) {
      while (n % i == 0) {
        n /= i;
        ++mp[i];
        ++s;
      }
    }
    if (n > 1) {
      ++mp[n];
      ++s;
    }
    puts(s >= t && (mp.size() != 1 || s % 2 == t % 2) ? "YES" : "NO");
  }

  return 0;
}

