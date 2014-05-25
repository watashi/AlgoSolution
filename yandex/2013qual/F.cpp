#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

int main() {
  int n;
  llint a;
  map<llint, int> mp;

  scanf("%d", &n);
  if (__builtin_popcount(n) != 1) {
    puts("NO");
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a);
    ++mp[a];
  }
  while (n > 1) {
    bool flag = false;
    n >>= 1;
    for (auto& i: mp) {
      if (i.second >= n) {
        i.second -= n;
        flag = true;
        break;
      }
    }
    if (!flag) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}

