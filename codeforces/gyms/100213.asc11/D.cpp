#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

bool cmp(const PII& lhs, const PII& rhs) {
  return lhs.second < rhs.second;
}

int main() {
  int n, a;
  map<int, int> mp;
  map<int, int>::const_iterator it;

#ifndef __WATASHI__
  freopen("integer.in", "r", stdin);
  freopen("integer.out", "w", stdout);
#endif
  scanf("%d", &n);
  mp.clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    ++mp[a - i];
  }
  it = max_element(mp.begin(), mp.end(), cmp);

  printf("%d\n%d", n - it->second, it->first);
  for (int i = 1; i < n; ++i) {
    printf(" %d", it->first + i);
  }
  puts("");

  return 0;
}

