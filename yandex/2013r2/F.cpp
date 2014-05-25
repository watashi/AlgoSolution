#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10;

set<string> dp[MAXN][MAXN][MAXN];

int gao(int i) {
  return i < 2 ? i : 2 + i % 2;
}

set<string> gao(int p, int q, int r) {
  vector<int> v = {p, q, r};
  sort(v.begin(), v.end());
  if (v[0] > 0 || v[1] > 1) {
    if ((p + q + r) % 2 == 0) {
      return {"RGB", "GBR", "BRG"};
    } else {
      return {"GRB", "BGR", "RBG"};
    }
  } else {
    return dp[gao(p)][gao(q)][gao(r)];
  }
}

int main() {
  dp[0][0][0].insert("RGB");
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      for (int k = 0; k < MAXN; ++k) {
        if (i > 0) {
          for (string s: dp[i - 1][j][k]) {
            swap(s[0], s[1]);
            dp[i][j][k].insert(s);
          }
        }
        if (j > 0) {
          for (string s: dp[i][j - 1][k]) {
            swap(s[0], s[2]);
            dp[i][j][k].insert(s);
          }
        }
        if (k > 0) {
          for (string s: dp[i][j][k - 1]) {
            swap(s[1], s[2]);
            dp[i][j][k].insert(s);
          }
        }
      }
    }
  }
  /*
  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      for (int k = 0; k < MAXN; ++k) {
        if (dp[i][j][k] != gao(i, j, k)) {
          printf("[%d][%d][%d] =", i, j, k);
          for (string s: dp[i][j][k]) {
            printf(" %s", s.c_str());
          }
          puts("");
        }
      }
    }
  }
  */

  int p, q, r;
  string s;

  cin >> p >> q >> r >> s;
  cout << (gao(p, q, r).count(s) > 0 ? "Yes" : "No") << endl;

  return 0;
}

