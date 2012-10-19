#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, m, k, t;
  set<int> fav;
  vector<pair<int, int> > v;

  scanf("%d%d", &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &t);
    fav.insert(t);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%*s%d", &k);
    int a = 0, b = 0, c = 0;
    for (int j = 0; j < k; ++j) {
      scanf("%d", &t);
      if (t == 0) {
        ++c;
      } else if (fav.count(t) > 0) {
        ++a;
      } else {
        ++b;
      }
    }
    v.push_back({min(a + c, (int)fav.size()), max(a, k - (m - (int)fav.size()))});
    // fprintf(stderr, "%d %d %d\n", a, b, c);
    // fprintf(stderr, "%d %d\n", v[i].first, v[i].second);
  }

  for (int i = 0; i < n; ++i) {
    bool top = true, notop = false;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        if (v[j].second > v[i].first) {
          top = false;
        }
        if (v[j].first > v[i].second) {
          notop = true;
        }
      }
    }
    if (top && !notop) {
      puts("0");
    } else if (!top && notop) {
      puts("1");
    } else if (top && notop) {
      puts("2");
    }
  }

  return 0;
}
