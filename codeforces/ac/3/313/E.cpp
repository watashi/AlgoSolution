#include <set>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int m;
map<int, int> a, b;
set<pair<int, pair<int, int> > > pq;

void dec(map<int, int>& mp, int k, int v) {
  mp[k] -= v;
  if (mp[k] == 0) {
    mp.erase(k);
  }
}

pair<int, int> next(const map<int, int>& mp, int k) {
  map<int, int>::const_iterator it = mp.lower_bound(k);
  if (it == mp.end()) {
    it = mp.begin();
  }
  return *it;
}

void insert(pair<int, int> i) {
  auto j = next(b, i.first);
  int k = j.first - i.first;
  if (k < 0) {
    k += m;
  }
  pq.insert({k, {i.first, j.first}});
}

int main() {
  int n, x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    ++a[x];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    x = m - 1 - x;
    ++b[x];
  }
  for (auto i: a) {
    insert(i);
  }

  while (!pq.empty()) {
    int d, i, j;
    d = m - 1 - pq.begin()->first;
    tie(i, j) = pq.begin()->second;
    pq.erase(pq.begin());
    if (a.count(i) > 0 && b.count(j) > 0) {
      int k = min(a[i], b[j]);
      dec(a, i, k);
      dec(b, j, k);
      for (int kk = 0; kk < k; ++kk) {
        printf("%d ", d);
      }
    }
    if (a.count(i) > 0) {
      insert(*a.find(i));
    }
  }

  return 0;
}

