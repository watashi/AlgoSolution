#include <set>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int id[MAXN][MAXN];
set<int> e[MAXN * 10];
char color[MAXN * 10];

bool valid(int r, int c, int i, int j) {
  return 0 <= i && i < r && 0 <= j && j < c;
}

void addEdge(int a, int b) {
  e[max(a, b)].insert(min(a, b));
}

int main() {
  int r, c;
  vector<pair<int, int> > v;

  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      v.push_back({i, j});
    }
    if (i % 2 != 0) {
      reverse(v.end() - c, v.end());
    }
  }

  int m = 0;

  for (int i = 0, k = 1; i < (int)v.size(); ++k) {
    if (i + k + k + 1 > (int)v.size()) {
      k = (int)v.size() - i;
    }
    for (int j = 0; j < k; ++j) {
      id[v[i + j].first][v[i + j].second] = m;
    }
    i += k;
    ++m;
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i > 0 && id[i][j] != id[i - 1][j]) {
        addEdge(id[i][j], id[i - 1][j]);
      }
      if (j > 0 && id[i][j] != id[i][j - 1]) {
        addEdge(id[i][j], id[i][j - 1]);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    set<char> st;
    for (int j: e[i]) {
      st.insert(color[j]);
    }
    for (char c = 'A'; ; ++c) {
      if (st.count(c) == 0) {
        color[i] = c;
        break;
      }
    }
  }

  printf("%d\n", m);
  // printf("> %c <\n", *max_element(color, color + m));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      putchar(color[id[i][j]]);
    }
    puts("");
  }

  return 0;
}

