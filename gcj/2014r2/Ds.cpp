#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;

vector<vector<int>> v;
vector<string> vs;
int len[MAXN], lcp[MAXN][MAXN];

pair<int, int> gao(int n, int m) {
  if (n == 0) {
    int ret = m;
    for (int i = 0; i < m; ++i) {
      if (v[i].empty()) {
        return make_pair(-1, 0);
      }
      for (int j = 0; j < (int)v[i].size(); ++j) {
        ret += len[v[i][j]];
        if (j > 0) {
          ret -= lcp[v[i][j - 1]][v[i][j]];
        }
      }
    }
    return make_pair(ret, 1);
  } else {
    pair<int, int> ret(-1, 0);
    --n;
    for (int i = 0; i < m; ++i) {
      v[i].push_back(n);
      auto tmp = gao(n, m);
      v[i].pop_back();
      if (tmp.first > ret.first) {
        ret = tmp;
      } else if (tmp.first == ret.first) {
        ret.second += tmp.second;
      }
    }
    return ret;
  }
}

int main() {
  int re, n, m;
  char s[80];

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d", &n, &m);
    vs.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      vs.push_back(s);
    }
    sort(vs.begin(), vs.end());

    for (int i = 0; i < n; ++i) {
      len[i] = vs[i].size();
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int& k = lcp[i][j];
        k = 0;
        while (k < len[i] && k < len[j] && vs[i][k] == vs[j][k]) {
          ++k;
        }
      }
    }

    v = vector<vector<int>>(m);
    auto ans = gao(n, m);
    printf("Case #%d: %d %d\n", ri, ans.first, ans.second);
  }

  return 0;
}

