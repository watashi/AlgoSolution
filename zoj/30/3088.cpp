#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1024;

void SPFA(int n, int s, const vector<PII> e[], int d[], int p[]) {
    vector<bool> m(n, false);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        d[i] = 0;
        p[i] = -1;
    }
    m[s] = true;
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        m[s] = false;
        q.pop();
        for (vector<PII>::const_iterator i = e[s].begin(); i != e[s].end(); ++i) {
            if (p[i->first] == -1 || d[i->first] > d[s] + i->second) {
                d[i->first] = d[s] + i->second;
                p[i->first] = s;
                if (!m[i->first]) {
                    m[i->first] = true;
                    q.push(i->first);
                }
            }
        }
    }
}

int main() {
    int re;
    int n, m, k, a, b, c;
    double r;
    vector<int> path;
    int du[MAXN], dd[MAXN], pu[MAXN], pd[MAXN];
    vector<PII> eu[MAXN], ed[MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < n; ++i) {
            eu[i].clear();
            ed[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            ed[b - 1].push_back(make_pair(a - 1, -c));
        }
        for (int i = 0; i < k; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            eu[a - 1].push_back(make_pair(b - 1, c));
        }

        r = 0;
        a = b = -1;
        for (int i = 0; i < n; ++i) {
            SPFA(n, i, eu, du, pu);
            SPFA(n, i, ed, dd, pd);
            for (int j = 0; j < n; ++j) {
                if (du[j] != 0 && dd[j] != 0 && r * du[j] < -dd[j]) {
                    r = 1. * -dd[j] / du[j];
                    a = i;
                    b = j;
                }
            }
            if (a == i) {
                path.clear();
                c = b;
                while ((c = pu[c]) != -1) {
                    path.push_back(c);
                }
                reverse(path.begin(), path.end());
                c = b;
                do {
                    path.push_back(c);
                } while ((c = pd[c]) != -1);
            }
        }
        printf("%d", path[0] + 1);
        for (int i = 1; i < path.size(); ++i) {
            printf(" %d", path[i] + 1);
        }
        printf("\n%.3lf\n", r);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1746045   2009-01-21 00:46:42     Accepted    3088    C++     0   176     watashi@Zodiac

// 2012-09-07 02:01:13 | Accepted | 3088 | C++ | 10 | 180 | watashi | Source
