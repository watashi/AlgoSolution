#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
const int CHARSET = 10;
char buf[MAXN];
bool e[CHARSET][CHARSET];

vector<int> gao(const char s[]) {
  vector<int> p[CHARSET];
  for (int i = 0; s[i] != '\0'; ++i) {
    p[s[i] - 'a'].push_back(i);
  }

  vector<pair<int, int> > pq;
  for (int i = 0; i < CHARSET; ++i) {
    if (!p[i].empty()) {
      reverse(p[i].begin(), p[i].end());
      pq.emplace_back(i, p[i].back());
      p[i].pop_back();
    }
  }

  vector<int> ret;
  while (!pq.empty()) {
    for (auto& i: pq) {
      bool flag = true;
      for (auto j: pq) {
        if (!e[i.first][j.first] && i.second > j.second) {
          flag = false;
          break;
        }
      }
      if (flag) {
        ret.push_back(i.first);
        if (p[i.first].empty()) {
          pq.erase(find(pq.begin(), pq.end(), i));
        } else {
          i.second = p[i.first].back();
          p[i.first].pop_back();
        }
      }
    }
  }
  return ret;

  return ret;
}

int main() {
  int n, m, a, b;
  vector<int> x, y;

#ifndef __WATASHI__
  freopen("traces.in", "r", stdin);
  freopen("traces.out", "w", stdout);
#endif

  scanf("%d%d", &n, &m);
  fill(e[0], e[n], false);
  for (int i = 0; i < m; ++i) {
    scanf("%s", buf);
    a = buf[0] - 'a';
    b = buf[1] - 'a';
    e[a][b] = e[b][a] = true;
  }

  scanf("%s", buf);
  x = gao(buf);
  scanf("%s", buf);
  y = gao(buf);
  puts(x == y ? "YES" : "NO");

  return 0;
}

