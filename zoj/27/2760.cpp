#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 128;
const int inf = (1 << 30) - 1;

template<class T>
T FordFulkerson(int n, int src, int tar, T mp[MAXN][MAXN], T f[MAXN][MAXN])
{
    static int pre[MAXN], q[MAXN];
    static T d[MAXN];
    int v, p, t;
    T e;

    if (src == tar) {
        return inf;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f[i][j] = 0;
        }
    }
    while (true) {
        for (int i = 0; i < n; i++) {
            pre[i] = -1;
        }
        pre[src] = src;
        d[src] = inf;
        q[p = 0] = src;
        t = 1;
        while (p < t && pre[tar] == -1) {
            v = q[p++];
            for (int i = 0; i < n; i++) {
                if (pre[i] != -1) {
                    continue;
                }
                if ((e = mp[v][i] - f[v][i]) > 0) {
                    q[t++] = i;
                    pre[i] = v;
                    d[i] = d[v] < e ? d[v] : e;
                }
                else if ((e = f[i][v]) > 0) {
                    q[t++] = i;
                    pre[i] = n + v;
                    d[i] = d[v] < e ? d[v] : e;
                }
            }
        }
        if (pre[tar] == -1) {
            break;
        }
        v = tar;
        while (v != src) {
            if (pre[v] >= n) {
                f[v][pre[v] - n] -= d[tar];
                v = pre[v] - n;
            }
            else {
                f[pre[v]][v] += d[tar];
                v = pre[v];
            }
        }
    }
    e = 0;
    for (int i = 0; i < n; i++) {
        e += f[src][i];
    }

    return e;
}

int Dijkstra(int n, int src, int tar, const int mp[MAXN][MAXN], vector<int> pre[MAXN])
{
    static bool mark[MAXN];
    static int d[MAXN], dd;

    for (int i = 0; i < n; i++) {
        pre[i].clear();
        mark[i] = false;
        d[i] = inf;
    }
    d[src] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (!mark[j] && (k == -1 || d[j] < d[k])) {
                k = j;
            }
        }
        mark[k] = true;
        for (int j = 0; j < n; j++) {
            if (mp[k][j] != -1) { // if !mark[j] WA, there are zero length road
                                // after correcting this, i got AC
                dd = d[k] + mp[k][j];
                if (dd < d[j]) {
                    pre[j].clear();
                    d[j] = dd;
                    pre[j].push_back(k);
                }
                else if (dd == d[j]) {
                    pre[j].push_back(k);
                }
            }
        }
    }

    return d[tar];
}

void gao(int p, bool mark[MAXN], int mp[MAXN][MAXN], const vector<int> pre[MAXN])
{
    mark[p] = true;
    for (size_t i = 0; i < pre[p].size(); i++) {
        mp[pre[p][i]][p] = 1;
        if (!mark[pre[p][i]]) {
            gao(pre[p][i], mark, mp, pre);
        }
    }
}

int main(void)
{
    static bool mark[MAXN];
    static int mp[MAXN][MAXN], f[MAXN][MAXN];
    static vector<int> pre[MAXN];
    int n, src, tar;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &mp[i][j]);
            }
        }
        scanf("%d%d", &src, &tar);
        if (src == tar) {
            puts("inf");
            continue;
        }
        if (Dijkstra(n, src, tar, mp, pre) >= inf) {
            puts("0");
            continue;
        }
        for (int i = 0; i < n; i++) {
            mark[i] = false;
            for (int j = 0; j < n; j++) {
                mp[i][j] = 0;
            }
        }
        gao(tar, mark, mp, pre);
/*      for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                putchar('0' + mp[i][j]);
            }
            putchar('\n');
        }
*/      printf("%d\n", FordFulkerson<int>(n, src, tar, mp, f));
    }

    return 0;
}


//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3021645 2008-08-04 20:10:05 Accepted 2760 C++ 00:00.07 1036K Re:ReJudge
//

// 2012-09-07 01:38:25 | Accepted | 2760 | C++ | 30 | 312 | watashi | Source
