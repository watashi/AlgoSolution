#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const int HEIHGT = 100;
const int WIDTH = 2 * 100000;

struct Mirror {
  int a, b, c;

  Mirror(int a, int b, int c): a(a), b(b), c(c) {
  }

  bool operator<(const Mirror& o) const {
    return a < o.a;
  }
};

int getId(const vector<Mirror>& v, int x) {
  int i = upper_bound(v.begin(), v.end(), Mirror(x, x, x)) - v.begin();
  --i;
  if (i < 0 || x > v[i].b) {
    i = -1;
  }
  /*
  printf("getId(%p, %d) = (%d, %d, %d)\n", &v, x,
    i == -1 ? -1 : v[i].a,
    i == -1 ? -1 : v[i].b,
    i == -1 ? -1 : v[i].c);
  */
  return i;
}

int intdiv(int num, int den) {
  if (num % den == 0) {
    return num / den;
  } else {
    int ret = num / den;
    if (ret % 2 == 0) {
      ++ret;
    }
    return ret;
  }
}

int main() {
  char type;
  int h1, h2, n, a, b, c;
  vector<Mirror> up, down;

  scanf("%d%d%d", &h1, &h2, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %c%d%d", &c, &type, &a, &b);
    if (type == 'T') {
      up.push_back(Mirror(2 * a, 2 * b, c));
    } else {
      down.push_back(Mirror(2 * a, 2 * b, c));
    }
  }
  sort(up.begin(), up.end());
  sort(down.begin(), down.end());

  int ans = 0;
  for (int dir = 0; dir < 2; ++dir) {
    int h3 = h2;
    for (int i = 1; i <= n; ++i) {
      h3 = 2 * i * HEIHGT - h3;
      // printf("{%d => %d}\n", h1, h3);
      set<pair<int, int> > st;
      int sum = 0;
      for (int j = 1; j <= i; ++j) {
        vector<Mirror>& v = j % 2 != 0 ? up : down;
        int k = getId(v, intdiv((j * HEIHGT - h1) * WIDTH, h3 - h1));
        if (k == -1 || !st.insert(make_pair(j % 2, k)).second) {
          sum = 0;
          break;
        } else {
          sum += v[k].c;
        }
      }
      ans = max(ans, sum);
    }
    h1 = HEIHGT - h1;
    h2 = HEIHGT - h2;
    swap(up, down);
    // puts("\n=================\n\n");
  }
  printf("%d\n", ans);

  return 0;
}

