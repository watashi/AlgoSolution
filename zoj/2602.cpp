#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 128;
typedef pair<int, int> PII;

int main() {
    int re, u, s, x, y;
    int r[MAXN][MAXN], d[MAXN][MAXN], a[MAXN][MAXN];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &u, &s);
        for (int i = 1; i < u; ++i) {
            for (int j = 1; j <= s; ++j) {
                scanf("%d%d%d", &r[i][j], &d[i][j], &a[i][j]);
            }
        }

        for (int i = 1; i < u; ++i) {
            for (int j = 1; j <= s; ++j) {
                vector<PII> v;
                v.push_back(make_pair(x = i, y = j));
                while (r[x][y] != u && a[x][y] == 0) {  // !!r[x][y] != u!!
                    a[x][y] = 2;    // 2: inf-loop
                    v.push_back(make_pair(r[x][y], d[x][y]));
                    x = v.back().first;
                    y = v.back().second;
                }
                for (vector<PII>::const_iterator k = v.begin(); k != v.end(); ++k) {
                    r[k->first][k->second] = r[x][y];
                    d[k->first][k->second] = d[x][y];
                    a[k->first][k->second] = a[x][y];
                }
            }
        }

        try {
            set<int> st;
            queue<int> q;
            st.insert(1);
            q.push(1);
            while (!q.empty()) {
                x = q.front();
                q.pop();
                if (x < 0) {
                    x = -x;
                    y = s;
                } else {
                    y = 1;
                }
                for (int j = y; j <= s; ++j) {
                    // assert(r[x][s] == u || a[x][s] != 0);
                    if (a[x][j] == -1) {
                        throw 1;
                    } else if (r[x][j] != u && a[x][j] == 1) {
                        y = j < s ? r[x][j] : -r[x][j];
                        if (st.count(y) == 0) {
                            st.insert(y);
                            q.push(y);
                        }
                    }
                }
            }
            puts("YES");
        } catch (...) {
            puts("NO");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2175380   2010-04-24 17:15:13     Accepted    2602    C++     120     176     watashi@Zodiac

// 2012-09-07 01:31:29 | Accepted | 2602 | C++ | 120 | 180 | watashi | Source
