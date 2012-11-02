#include <map>
#include <queue>
#include <cctype>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 128;
const int INF = 1000000007;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

char buf[MAXN][MAXN];
int mind[MAXN][MAXN];
PII pre[MAXN][MAXN];

void dijkstra(const pair<int, int>& s) {
  priority_queue<
    pair<int, PII>,
    vector<pair<int, PII> >,
    greater<pair<int, PII> > > pq;
  fill(mind[0], mind[MAXN], INF);
  mind[s.first][s.second] = 0;
  pq.push(make_pair(mind[s.first][s.second], s));
  while (!pq.empty()) {
    int d = pq.top().first;
    int x = pq.top().second.first;
    int y = pq.top().second.second;
    pq.pop();
    if (mind[x][y] < d) {
      continue;
    }
    if (isdigit(buf[x][y])) {
      d += buf[x][y] - '0';
    } else if (make_pair(x, y) == s) {
      ++d;
    } else {
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      x += dx[i];
      y += dy[i];
      if ((isdigit(buf[x][y]) || islower(buf[x][y])) && mind[x][y] > d) {
        mind[x][y] = d;
        pre[x][y] = make_pair(x - dx[i], y - dy[i]);
        pq.push(make_pair(d, make_pair(x, y)));
      }
      x -= dx[i];
      y -= dy[i];
    }
  }
}

void show(const PII& s, PII t, int m) {
  dijkstra(s);
  while (mind[t.first][t.second] > m) {
    t = pre[t.first][t.second];
  }
  printf("%d %d\n", t.first, t.second);
}

int main() {
  int r, c, m, n, x, y;
  char s[4096];
  PII from, to;
  map<char, pair<int, int> > pos;
  map<pair<char, char>, int > dist;

  scanf("%d%d%d", &r, &c, &m);
  for (int i = 1; i <= r; ++i) {
    scanf("%s", buf[i] + 1);
    for (int j = 1; j <= c; ++j) {
      if (islower(buf[i][j])) {
        pos[buf[i][j]] = make_pair(i, j);
      }
    }
  }
  scanf("%d%d", &from.first, &from.second);
  scanf("%s", s);
  n = strlen(s);
  scanf("%d%d", &to.first, &to.second);

  // (1)
  dijkstra(from);
  tie(x, y) = pos[s[0]];
  if (m <= mind[x][y]) {
    show(from, make_pair(x, y), m);
    return 0;
  } else {
    m -= mind[x][y];
  }

  // (2)
  for (auto& s: pos) {
    dijkstra(s.second);
    for (auto& t: pos) {
      tie(x, y) = t.second;
      dist[make_pair(s.first, t.first)] = mind[x][y];
    }
  }
  for (int i = 1; i < n; ++i) {
    if (m <= dist[make_pair(s[i - 1], s[i])]) {
      show(pos[s[i - 1]], pos[s[i]], m);
      return 0;
    } else {
      m -= dist[make_pair(s[i - 1], s[i])];
    }
  }

  // (3)
  dijkstra(pos[s[n - 1]]);
  tie(x, y) = to;
  if (m <= mind[x][y]) {
    show(pos[s[n - 1]], to, m);
    return 0;
  } else {
    printf("%d %d\n", to.first, to.second);
  }

  return 0;
}

