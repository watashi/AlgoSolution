#include <ctime>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 80;
const int TIME_LIMIT = CLOCKS_PER_SEC * 3 / 4;

int time_limit = 0;

bool timeout() {
    return clock() > time_limit;
}

bool a[MAXN][MAXN], b[MAXN][MAXN];
int p[MAXN], q[MAXN], ans;

int main() {
    int re, n, t;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &t);
                a[i][j] = t == 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &t);
                b[i][j] = t == 1;
            }
        }

        ans = -1;
        for (int i = 0; i < n; ++i) {
            p[i] = q[i] = i;
        }

        ++time_limit += TIME_LIMIT;
        while (!timeout()) {
            t = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (a[i][j] && b[p[i]][p[j]]) {
                        ++t;
                    }
                }
            }
            if (ans <= t) {
                ans = t;
                copy(p, p + n, q);
            }
            random_shuffle(p, p + n);
        }

        for (int i = 0; i < n; ++i) {
            printf("%d%c", i + 1, i == n - 1 ? '\n' : ' ');
        }
        for (int i = 0; i < n; ++i) {
            p[q[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            printf("%d%c", p[i] + 1, i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}

