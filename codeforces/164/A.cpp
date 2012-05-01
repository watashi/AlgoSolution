#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

bool x[MAXN], y[MAXN];
int f[MAXN];
vector<int> ab[MAXN], ba[MAXN];

int main() {
    int n, m, a, b;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &a, &b);
        ab[a].push_back(b);
        ba[b].push_back(a);
    }

    queue<int> qx;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 1) {
            x[i] = true;
            qx.push(i);
        }
    }
    while (!qx.empty()) {
        a = qx.front();
        qx.pop();
        for (int i: ab[a]) {
            if (!x[i] && f[i] != 1) {
                x[i] = true;
                qx.push(i);
            }
        }
    }

    queue<int> qy;
    for (int i = 1; i <= n; ++i) {
        if (f[i] == 2) {
            y[i] = true;
            qy.push(i);
        }
    }
    while (!qy.empty()) {
        b = qy.front();
        qy.pop();
        if (f[b] != 1) {
            for (int i: ba[b]) {
                if (!y[i]) {
                    y[i] = true;
                    qy.push(i);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        puts(x[i] && y[i] ? "1" : "0");
    }

    return 0;
}

