#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 17;
const int LCM = 4 * 3 * 5;

int opidx[MAXN][MAXN];
string act[100], act2[100];
string op[MAXN][MAXN];

void gao(int r, int c, int x, int y, int z, vector<pair<int, int> >& path, int& begin, int& end) {
    static int d[MAXN][MAXN][LCM];
    memset(d, 0xff, sizeof(d));
    path.clear();
    while (d[x][y][z] == -1) {
        d[x][y][z] = path.size();
        path.push_back(make_pair(x, y));
        switch (op[x][y][z]) {
        case 'N': --x; break;
        case 'W': --y; break;
        case 'S': ++x; break;
        case 'E': ++y; break;
        case 'D':
                  begin = path.size();
                  path.push_back(make_pair(-1, -1));
                  end = path.size();
                  return;
        }
        if (x < 0 || y < 0 || x >= r || y >= c) {
            begin = path.size();
            path.push_back(make_pair(-1, -1));
            end = path.size();
            return;
        }
        ++z;
        if (z == LCM) {
            z = 0;
        }
    }
    begin = d[x][y][z];
    end = path.size();
}

int begin[MAXN][MAXN][LCM], end[MAXN][MAXN][LCM];
vector<pair<int, int> > path[MAXN][MAXN][LCM];

inline pair<int, int> whereis(int x, int y, int z, long long t) {
    if (t < end[x][y][z]) {
        return path[x][y][z][t];
    } else {
        return path[x][y][z][begin[x][y][z] + (t - begin[x][y][z]) % (end[x][y][z] - begin[x][y][z])];
    }
}

long long val[MAXN][MAXN];

int main() {
    int r, c, n;
    long long t, p, ans;
    pair<int, int> xy;
    static char buf[80];

    while (scanf("%d%d%lld%d", &r, &c, &t, &n) != EOF) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                scanf("%1d", &opidx[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            act[i] = buf;
            act2[i] = "";
            while ((int)act2[i].length() != LCM) {
                act2[i] += act[i];
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                op[i][j] = act2[opidx[i][j]];
            }
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (int k = 0; k < LCM; ++k) {
                    gao(r, c, i, j, k, path[i][j][k], begin[i][j][k], end[i][j][k]);
                }
            }
        }

        memset(val, 0, sizeof(val));
        p = max(0LL, (t - MAXN * MAXN * LCM) / LCM - 1);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (p > 0) {
                    for (int k = 0; k < LCM; ++k) {
                        if (!('1' <= op[i][j][k % LCM] && op[i][j][k % LCM] <= '9')) {
                            continue;
                        }
                        xy = whereis(i, j, k, t - k);
                    //  printf("[%d][%d][%d][%lld] (%d, %d)\n", i, j, k, t - k, xy.first, xy.second);
                        if (xy != make_pair(-1, -1)) {
                            val[xy.first][xy.second] += p * (op[i][j][k % LCM] - '0');
                        }
                    }
                }
                for (int k = p * LCM; k < t; ++k) {
                    if (!('1' <= op[i][j][k % LCM] && op[i][j][k % LCM] <= '9')) {
                        continue;
                    }
                    xy = whereis(i, j, k % LCM, t - k);
                    if (xy != make_pair(-1, -1)) {
                        val[xy.first][xy.second] += op[i][j][k % LCM] - '0';
                    }
                }
            }
        }

        ans = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
//              printf("%lld ", val[i][j]);
                ans = max(ans, val[i][j]);
            }
//          puts("");
        }
        printf("%lld\n", ans);
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1282  2010-08-01 18:48:53     Accepted    1155    C++     350     10856   anotherpeg  Source

// 2012-09-07 15:52:05 | Accepted | 3402 | C++ | 2280 | 18016 | watashi | Source
