#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 4096;

int main() {
  int n;
  int a[MAXN], c[MAXN], v;

#ifndef __WATASHI__
  freopen("rhymes.in", "r", stdin);
  freopen("rhymes.out", "w", stdout);
#endif
  scanf("%d", &n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v);
    a[i] = -1;
    if (mp.count(v) > 0) {
      a[mp[v]] = i;
      c[i] = mp[v];
    } else {
      c[i] = -1;
    }
    mp[v] = i;
  }

  vector<int> ans;
  for (int i = 0; i < n; ) {
    int j = i + 1;
    while (j < n && c[j] == -1) {
      ++j;
    }
    if (j == n) {
      break;
    } else if (a[j] != -1) {
      c[a[j]] = -1;
    }

    int k = j + 1;
    while (k < n && c[k] == -1) {
      ++k;
    }
    if (k == n) {
      break;
    } else if (a[k] != -1) {
      c[a[k]] = -1;
    }

    ans.push_back(c[j]);
    ans.push_back(j);
    ans.push_back(c[k]);
    ans.push_back(k);

    for (; i <= k; ++i) {
      if (a[i] != -1) {
        c[a[i]] = -1;
      }
    }
  }

  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size() / 4);
  for (int i = 0; i < (int)ans.size(); i += 4) {
    printf("%d %d %d %d\n", ans[i] + 1, ans[i + 1] + 1, ans[i + 2] + 1, ans[i + 3] + 1);
  }

  return 0;
}


