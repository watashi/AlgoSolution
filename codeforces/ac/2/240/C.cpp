#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
#ifndef __WATASHI__
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  vector<vector<int> > ans;

  scanf("%d", &n);
  for (int i = 0; (1 << i) < n; ++i) {
    vector<int> v;
    for (int j = 0; j < n; ++j) {
      if (j & (1 << i)) {
        v.push_back(j);
      }
    }
    ans.push_back(v);
  }

  printf("%d\n", (int)ans.size());
  for (auto& v: ans) {
    printf("%d", (int)v.size());
    for (int i: v) {
      printf(" %d", i + 1);
    }
    puts("");
  }

  return 0;
}
