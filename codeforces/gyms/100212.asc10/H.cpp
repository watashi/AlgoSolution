#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> Point;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int dz[] = {2, 3, 0, 1};
const int x1[] = {1, 1, 0, 0};
const int y1[] = {0, 1, 1, 0};
const int x2[] = {1, 0, 0, 1};
const int y2[] = {1, 1, 0, 0};

char buf[64][64];
vector<Point> vp;
vector<int> vd;

bool checkPolyomino(int n, int m, int x, int y) {
  queue<Point> q;
  buf[x][y] = ' ';
  q.push(Point(x, y));
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (0 <= xx && xx < n && 0 <= yy && yy < m && buf[xx][yy] == '.') {
        buf[xx][yy] = ' ';
        q.push(Point(xx, yy));
      }
    }
    q.pop();
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (buf[i][j] == '.') {
        return false;
      }
    }
  }
  return true;
}

void nextPolyomino() {
  int n = 0, m = 60;

  memset(buf[0], '.', sizeof(buf[0]));
  while (scanf("%s", buf[n + 1] + 1) != EOF) {
    ++n;
    buf[n][0] = '.';
    memset(buf[n] + strlen(buf[n]), '.', sizeof(buf[0]) - strlen(buf[n]));
  }
  memset(buf[n + 1], '.', sizeof(buf[0]));

  vp.clear();
  vd.clear();
  if (!checkPolyomino(n + 2, m, 0, 0)) {
    return;
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if ((buf[i + 1][j + 1] == '*') ^ (buf[i + 1][j] == '*')) {
        vp.push_back(Point(i, j));
        vp.push_back(Point(i + 1, j));
        vd.push_back(0);
        goto GOTO;
      } else if ((buf[i + 1][j + 1] == '*') ^ (buf[i][j + 1] == '*')) {
        vp.push_back(Point(i, j));
        vp.push_back(Point(i, j + 1));
        vd.push_back(1);
        goto GOTO;
      }
    }
  }
  return; // no '*'

GOTO:
  do {
    int x = vp.back().first;
    int y = vp.back().second;
    for (int i = 0; i < 4; ++i) {
      if (i == dz[vd.back()]) {
        continue;
      }
      if ((buf[x + x1[i]][y + y1[i]] == '*') ^ (buf[x + x2[i]][y + y2[i]] == '*')) {
        vp.push_back(Point(x + dx[i], y + dy[i]));
        vd.push_back(i);
        break;
      }
    }
  } while (vp.back() != vp.front());
  vp.pop_back();
}

int w[64][64];

int main() {

#ifndef __WATASHI__
  freopen("tilings.in", "r", stdin);
  freopen("tilings.out", "w", stdout);
#endif

  nextPolyomino();
  // C <= 2 * S + 2
  int n = vd.size();  // n \subset [4, 62]
  int m = n / 2;

  memset(w, 0x0f, sizeof(w));
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < m; ++j) {
      bool flag = true;
      int l = i, r = i + m + (j - 1);
      for (int k = 0; k < j; ++k) {
        if (vd[l + k] != dz[vd[(r - k) % n]]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        w[i][i + j] = 1;
      }
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (w[i][j] > w[i][k] + w[k][j]) {
          w[i][j] = w[i][k] + w[k][j];
        }
      }
    }
  }

  bool flag = false;
  for (int k = 0; k < m; ++k) {
    if (w[k][k + m] <= 3) {
      flag = true;
      break;
    }
  }
  puts(flag ? "YES" : "NO");

  return 0;
}

