#include <queue>
#include <cctype>
#include <cstdio>
#include <algorithm>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MAXN = 512;
char buf[MAXN][MAXN];
int tag[MAXN][MAXN];
double init[MAXN][MAXN];
double maxd[MAXN][MAXN];

int main() {
    int r, c, ts;
    double rate, ans;
    int sx = -1, sy = -1, tx = -1, ty = -1;
    vector<pair<pair<int, int>, double> > cur, pre;

    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; ++i) {
        scanf("%s", buf[i] + 1);
        for (int j = 1; j <= c; ++j) {
            if (buf[i][j] == 's') {
                sx = i;
                sy = j;
            } else if (isdigit(buf[i][j])) {
                init[i][j] = buf[i][j] - '0';
            }
        }
    }

    ts = 0;
    rate = 1.0;
    ans = 0.0;
    maxd[sx][sy] = 10.0;
    cur.push_back({{sx, sy}, maxd[sx][sy]});
    while (!cur.empty()) {
        ++ts;
        rate *= 0.99;
        pre.swap(cur);
        cur.clear();
        for (int i = 0; i < (int)pre.size(); ++i) {
            sx = pre[i].first.first;
            sy = pre[i].first.second;
            double sz = pre[i].second;
            // printf("[%d,%d,%d] %lf\n", sx, sy, ts, sz);
            for (int j = 0; j < 4; ++j) {
                tx = sx + dx[j];
                ty = sy + dy[j];
                if (buf[tx][ty] == 'g') {
                    ans = max(ans, sz);
                } else if (init[tx][ty] > 0) {
                    double tz = min(init[tx][ty] * rate, sz);
                    if (maxd[tx][ty] < tz) {
                        maxd[tx][ty] = tz;
                        if (tag[tx][ty] != ts) {
                            tag[tx][ty] = ts;
                            cur.push_back({{tx, ty}, 0.0});
                        }
                    }
                }
            }
        }
        for (int i = 0; i < (int)cur.size(); ++i) {
            cur[i].second = maxd[cur[i].first.first][cur[i].first.second];
        }
    }
    if (ans == 0.0) {
        puts("-1");
    } else {
        printf("%.10lf\n", ans);
    }

    return 0;
}

