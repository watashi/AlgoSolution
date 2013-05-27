#include <set>
#include <cstdio>
#include <vector>

using namespace std;

int bitLength(int m) {
  int ret = 0;
  while (m > 0) {
    m >>= 1;
    ++ret;
  }
  return ret;
}

#define CHANGE(p, d) \
  do {\
    if (v[p] == 0) {\
      zero.erase(p);\
    } else if (v[p] == 2) {\
      two.erase(p);\
    }\
    v[p] += d;\
    printf(" %d %d", p, v[p]);\
    if (v[p] == 0) {\
      zero.insert(p);\
    } else if (v[p] == 2) {\
      two.insert(p);\
    }\
  } while(false)

int main() {
  int n, m, p;

  freopen("counter.in", "r", stdin);
  freopen("counter.out", "w", stdout);
  scanf("%d%d", &n, &m);
  vector<int> v(n + bitLength(m), 0);
  set<int> zero;
  set<int> two;
  set<int>::iterator iz, it;
  for (int i = 0; i < (int)v.size(); ++i) {
    zero.insert(i);
  }
  two.insert((int)v.size());
  for (int i = 0; i < m; ++i) {
    scanf("%d", &p);
    it = two.upper_bound(p);
    iz = zero.upper_bound(*it);
    --iz;
    if (p >= *iz) {
      putchar('3');
      CHANGE(p, +1);
      CHANGE(*it, -2);
      CHANGE(*it + 1, +1);
    } else if (v[p] > 0) {
      putchar('2');
      CHANGE(p, -1);
      CHANGE(p + 1, +1);
    } else {
      putchar('1');
      CHANGE(p, +1);
    }
    putchar('\n');
  }

  return 0;
}

