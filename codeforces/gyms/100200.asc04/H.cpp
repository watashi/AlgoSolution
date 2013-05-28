#include <queue>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dd[3][4] = {
  {0, 1, 2, 3},	// F
  {1, 2, 3, 0},	// L
  {3, 0, 1, 2}	// R
};
const char dc[3] = {'F', 'L', 'R'};

int main() {
  int m, n;
  char city[888][888];
  int mind[444][444];

  freopen("straight.in", "r", stdin);
  freopen("straight.out", "w", stdout);
  scanf("%d%d", &m, &n);
  while (getchar() != '\n') {
  }
  memset(city, ' ', sizeof(city));
  for (int i = 2; i <= 2 * m; ++i) {
    fgets(city[i] + 2, sizeof(city[i]) - 2, stdin);
  }
  queue<pair<int, int> > q;
  memset(mind, 0xff, sizeof(mind));
  mind[1][n] = 0;
  q.push(make_pair(1, n));
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    // fprintf(stderr, "%d %d\n", x, y);
    for (int i = 0; i < 4; ++i) {
      int xx = x * 2 + dx[i];
      int yy = y * 2 + dy[i];
      if (city[xx][yy] == '-' || city[xx][yy] == '|') {
        xx += dx[i];
        yy += dy[i];
        if (mind[xx / 2][yy / 2] == -1) {
          mind[xx / 2][yy / 2] = mind[x][y] + 1;
          q.push(make_pair(xx / 2, yy / 2));
        }
      }
    }
    q.pop();
  }

  pair<int, int> p;
  int d;
  if (city[2 * m - 1][2] == '|' && mind[m - 1][1] == mind[m][1] - 1) {
    puts("N");
    p = make_pair(m - 1, 1);
    d = 2;
  } else if (city[2 * m][3] == '-' && mind[m][2] == mind[m][1] - 1) {
    puts("E");
    p = make_pair(m, 2);
    d = 1;
  } else {
    throw 1;
  }
  while (true) {
    int x = p.first;
    int y = p.second;
    // fprintf(stderr, "%d %d\n", x, y);
    if (mind[x][y] == 0) {
      putchar('\n');
      break;
    }
    for (int k = 0; k < 3; ++k) {
      int xx = x * 2 + dx[dd[k][d]];
      int yy = y * 2 + dy[dd[k][d]];
      if (city[xx][yy] == '-' || city[xx][yy] == '|') {
        xx += dx[dd[k][d]];
        yy += dy[dd[k][d]];
        if (mind[xx / 2][yy / 2] == mind[x][y] - 1) {
          p = make_pair(xx / 2, yy / 2);
          d = dd[k][d];
          putchar(dc[k]);
          break;
        }
      }
    }
  }

  return 0;
}

