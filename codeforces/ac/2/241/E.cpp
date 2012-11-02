#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int MAXM = 5050;

typedef bitset<MAXN + MAXN> Bitset;

bool froms[MAXN], tot[MAXN];
int label[MAXN];
vector<pair<int, int> > e[MAXN], re[MAXN];
Bitset bs[MAXN];
int d[MAXM];

void bfs(int s, bool mark[MAXN], const vector<pair<int, int> > e[MAXN]) {
  queue<int> q;
  mark[s] = true;
  q.push(s);
  while (!q.empty()) {
    s = q.front();
    q.pop();
    for (auto& i: e[s]) {
      if (!mark[i.first]) {
        mark[i.first] = true;
        q.push(i.first);
      }
    }
  }
}

bool mark[MAXN];

int main() {
  int n, m, a, b;
  queue<int> q;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    bs[i].reset();
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    e[a].push_back(make_pair(b, i));
    re[b].push_back(make_pair(a, i));
  }
  for (int i = 0; i < n; ++i) {
    bs[i].reset();
    bs[i] = ~bs[i];
  }
  bs[0].reset();
  bs[0].set(0);

  bfs(0, froms, e);
  bfs(n - 1, tot, re);
  for (int i = 0; i < n; ++i) {
    froms[i] = froms[i] && tot[i];
    if (!froms[i]) {
      e[i].clear();
      re[i].clear();
    }
  }
  for (int i = 0; i < n; ++i) {
    e[i].erase(remove_if(e[i].begin(), e[i].end(),
        [&](pair<int, int> t) { return !froms[t.first]; }), e[i].end());
    re[i].erase(remove_if(re[i].begin(), re[i].end(),
        [&](pair<int, int> t) { return !froms[t.first]; }), re[i].end());
  }
  if (!froms[n - 1]) {
    puts("No");
    return 0;
  }

  fill(mark, mark + n, false);
  mark[0] = true;
  q.push(0);
  while (!q.empty() && bs[n - 1].any()) {
    int s = q.front();
    mark[s] = false;
    // cout << s << ": " << bs[s] << endl;
    q.pop();
    for (auto& i: e[s]) {
      int j = i.first;
      Bitset t = bs[j] & ((bs[s] << 1) | (bs[s] << 2));
      if (bs[j] != t) {
        bs[j] = t;
        if (!mark[j]) {
          mark[j] = true;
          q.push(j);
        }
      }
    }
    for (auto& i: re[s]) {
      int j = i.first;
      Bitset t = bs[j] & ((bs[s] >> 1) | (bs[s] >> 2));
      if (bs[j] != t) {
        bs[j] = t;
        if (!mark[j]) {
          mark[j] = true;
          q.push(j);
        }
      }
    }
  }
  if (bs[n - 1].none()) {
    puts("No");
    return 0;
  }

  fill(d, d + m, 1);
  for (int i = 0; i < n; ++i) {
    if (froms[i]) {
      for (int j = 0; j < (int)bs[i].size(); ++j) {
        if (bs[i].test(j)) {
          label[i] = j;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (auto& j: e[i]) {
      if (label[j.first] - label[i] > 1) {
        d[j.second] = 2;
      }
    }
  }
  puts("Yes");
  for (int i = 0; i < m; ++i) {
    printf("%d\n", d[i]);
  }

  return 0;
}

