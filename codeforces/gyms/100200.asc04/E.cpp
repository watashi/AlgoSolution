/*
#!/bin/bash
echo $#
while (($# > 0))
do
  echo
  echo $1
  for i in `seq $1`
  do
    ((y = 1870 + $RANDOM % 130))
    ((r = 1 + $RANDOM % 5))
    echo "\"$y$r\"" $y $r
  done
  shift
done
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int O = 1869;
const int N = 2009 - O;

int main() {
  int n, y, r;
  char name[2002][128];
  vector<int> p[5][5];
  vector<int> a[N][5];
  int dp[N][5][6];
  int pre[N][5][6];
  int xx, yy, zz;

  for (int k = 0; k < (1 << 5); ++k) {
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        if (i != j && ((1 << i) & k) != 0 && ((1 << j) & k) != 0) {
          p[i][j].push_back(k);
        }
      }
    }
  }
  for (int k = 0; k < 5; ++k) {
    p[k][k].push_back(1 << k);
  }

  freopen("dvd.in", "r", stdin);
  freopen("dvd.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 5; ++j) {
      a[i][j].clear();
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf(" \"%[^\"]\"%d%d", name[i], &y, &r);
    a[y - O][r - 1].push_back(i);
  }

  memset(dp, 0, sizeof(dp));
  xx = yy = zz = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < 5; ++j) {
      for (int k = 0; k < 5; ++k) {
        for (vector<int>::iterator mask = p[j][k].begin(); mask != p[j][k].end(); ++mask) {
          int s = 0, t = -1;
          for (int bit = 0; bit < 5; ++bit) {
            if (((1 << bit) & *mask) != 0) {
              s += a[i][bit].size();
              ++t;
            }
          }
          for (int l = 0; l + t <= 5; ++l) {
            if (dp[i][j][l + t] < dp[i - 1][k][l] + s) {
              dp[i][j][l + t] = dp[i - 1][k][l] + s;
              pre[i][j][l + t] = (k << 5) ^ *mask;
              if (dp[i][j][l + t] > dp[xx][yy][zz]) {
                xx = i;
                yy = j;
                zz = l + t;
              }
            }
          }
        }
      }
    }
  }

  vector<int> ans;
  fprintf(stderr, "%d\n", dp[xx][yy][zz]);
  while (dp[xx][yy][zz] != 0) {
    int mask = pre[xx][yy][zz] & 31;
    int yyy = pre[xx][yy][zz] >> 5;
    ans.insert(ans.end(), a[xx][yy].begin(), a[xx][yy].end());
    for (int i = 4; i >= 0; --i) {
      if (i != yy && i != yyy && ((1 << i) & mask) != 0) {
        ans.insert(ans.end(), a[xx][i].begin(), a[xx][i].end());
        --zz;
      }
    }
    if (yyy != yy) {
      ans.insert(ans.end(), a[xx][yyy].begin(), a[xx][yyy].end());
      --zz;
    }
    --xx;
    yy = yyy;
  }
  printf("%d\n", (int)ans.size());
  while (!ans.empty()) {
    printf("\"%s\"\n", name[ans.back()]);
    ans.pop_back();
  }

  return 0;
}

