#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <vector>
#include <algorithm> // auto fix CE
#include <cstring>

using namespace std;

const int MAXN = 52;
const int INF = 65536;

int d[MAXN];
vector<int> e[MAXN];

int b[MAXN][MAXN][MAXN * 4];
int c[MAXN][MAXN][MAXN * 4];

int gao(int x, int y, int z) {
    if (c[x][y][100 + z] != -1) {
        return b[x][y][100 + z];
    }
    int tmp;
    int &ret = b[x][y][100 + z], &cnt = c[x][y][100 + z];
    ret = (e[x].empty() && e[y].empty()) ? -z : -INF;
    cnt = 1;
    for (vector<int>::const_iterator i = e[x].begin(); i != e[x].end(); ++i) {
        tmp = -gao(*i, y, z + d[*i]);
        if (tmp > ret) {
            ret = tmp;
            cnt = 1;
        } else if (tmp == ret) {
            ++cnt;
        }
    }
    for (vector<int>::const_iterator i = e[y].begin(); i != e[y].end(); ++i) {
        tmp = -gao(x, *i, z - d[*i]);
        if (tmp > ret) {
            ret = tmp;
            cnt = 1;
        } else if (tmp == ret) {
            ++cnt;
        }
    }
    return ret;
}

int main() {
    int n, m, x, y, s, t;

    while (scanf("%d%d%d%d", &n, &m, &x, &y) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &d[i]);
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &s, &t);
            e[s].push_back(t);
        }
        memset(c, 0xff, sizeof(c));
        gao(x, y, 1);
        printf("%d %d\n", b[x][y][101], c[x][y][101]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//584   2010-07-16 19:50:54     Accepted    1074    C++     860     4572    anotherpeg  Source

// 2012-09-07 15:47:44 | Accepted | 3352 | C++ | 650 | 4576 | watashi | Source
