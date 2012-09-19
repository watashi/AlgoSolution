#include <map>
#include <queue>
#include <cctype>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> triple;

const int MAXN = 17;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

char buf[MAXN][MAXN];
pair<int, int> p[MAXN];
map<int, int> d[MAXN][MAXN];

int main() {
    int r, c, n, m, x, y;
    queue<triple> q;

    n = 0;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
        scanf("%s", buf[i]);
        for (int j = 0; j < c; ++j) {
            if (isdigit(buf[i][j])) {
                n = max(n, buf[i][j] - '0');
                p[buf[i][j] - '1'] = {i, j};
            }
        }
    }

    m = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (p[i].first - p[i - 1].first == dx[j] && p[i].second - p[i - 1].second == dy[j]) {
                m ^= j << (2 * (i - 1));
                break;
            }
        }
    }

    d[p[0].first][p[0].second][m] = 0;
    q.push(triple(p[0].first, p[0].second, m));
    while (!q.empty()) {
        tie(x, y, m) = q.front();
        p[0] = {x, y};
        for (int i = 1; i < n; ++i) {
            int j = (m >> (2 * (i - 1))) & 3;
            p[i] = {p[i - 1].first + dx[j], p[i - 1].second + dy[j]};
        }
        // printf("[%d|%o] ", d[x][y][m], m);
        for (int i = 0; i < n - 1; ++i) {
            // printf("(%d,%d)-", p[i].first, p[i].second);
            buf[p[i].first][p[i].second] = '#';
        }
        // puts("");

        int t = d[x][y][m];
        for (int k = 0; k < 4; ++k) {
            x -= dx[k];
            y -= dy[k];
            int mm = ((m << 2) ^ k) & ((1 << (2 * (n - 1))) - 1);
            if (0 <= x && x < r
                    && 0 <= y && y < c
                    && buf[x][y] != '#'
                    && d[x][y].count(mm) == 0) {
                // printf("[%d][%d] = %c\n", x, y, buf[x][y]);
                d[x][y][mm] = t + 1;
                q.push(triple(x, y, mm));
                if (buf[x][y] == '@') {
                    printf("%d\n", t + 1);
                    return 0;
                }
            }
            x += dx[k];
            y += dy[k];
        }

        for (int i = 0; i < n - 1; ++i) {
            buf[p[i].first][p[i].second] = '.';
        }
        q.pop();
    }
    puts("-1");
    return 0;
}

