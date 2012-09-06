// 差分约束

#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 50005;

bool m[MAXN];
int d[MAXN];
vector<PII> e[MAXN];

int main()
{
    int n, a, b, c;

    while (scanf("%d", &n) != EOF) {
        fill(m, m + MAXN, false);
        fill(d, d + MAXN, 0);
        fill(e, e + MAXN, vector<PII>());

        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            e[b + 1].push_back(PII(a, -c));
        }

        queue<int> q;

        for (int i = 0; i < MAXN; i++) {
            q.push(i);
            if (i != 0) {
                e[i].push_back(PII(i - 1, 0));
            }
            if (i != MAXN - 1) {
                e[i].push_back(PII(i + 1, 1));
            }
        }
        while (!q.empty()) {
            a = q.front();
            m[a] = true;
            q.pop();
            for (size_t i = 0; i < e[a].size(); i++) {
                b = e[a][i].first;
                c = e[a][i].second + d[a];
                if (d[b] > c) {
                    d[b] = c;
                    if (m[b]) {
                        m[b] = false;
                        q.push(b);
                    }
                }
            }
        }

        printf("%d\n", d[MAXN - 1] - d[0]);
    }

    return 0;
}

// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
// 1715431  2008-12-01 01:46:08     Accepted    1508    C++     610     4176    watashi@Zodiac

// 2012-09-07 00:51:41 | Accepted | 1508 | C++ | 570 | 4176 | watashi | Source
