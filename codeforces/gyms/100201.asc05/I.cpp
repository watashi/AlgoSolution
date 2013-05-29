#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n, m;
  vector<int> a;

#ifndef __WATASHI__
  freopen("railsort.in", "r", stdin);
  freopen("railsort.out", "w", stdout);
#endif
  scanf("%d", &n);
  m = 1 << n;
  a.resize(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }

  vector<int> v;
  for (int k = 0; k < n; ++k) {
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < m; ++i) {
      v.push_back(a[i]);
      if ((a[i] >> k) % 4 == 0 || (a[i] >> k) % 4 == 3) {
        b.push_back(a[i]);
        v.push_back(a[i]);
      } else {
        c.push_back(a[i]);
      }
    }
    a.clear();
    a.insert(a.end(), b.begin(), b.end());
    a.insert(a.end(), c.rbegin(), c.rend());
    v.insert(v.end(), c.rbegin(), c.rend());
  }

  for (size_t i = 0; i < v.size(); ++i) {
    printf("%d%c", v[i] + 1, i == v.size() - 1 ? '\n' : ' ');
  }

  return 0;
}


