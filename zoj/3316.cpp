// 一般图匹配
// [module] graph match
// [module] maxmium matching
// TAG: MODULE

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 365;
const int MAXM = MAXN * MAXN;

struct Matching {
    int n;  // in
    bool mark[MAXN];    // internal
    int match[MAXN];    // out
    vector<int> e[MAXN];    // in

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; ++i) {
            e[i].clear();
        }
    }

    void addEdge(int a, int b) {
        e[a].push_back(b);
        e[b].push_back(a);
    }

    bool augument(int v) {
        bool ret = false;
        mark[v] = true;

        for (size_t i = 0; !ret && i < e[v].size(); ++i) {
            int w = e[v][i];
            if (!mark[w]) {
                mark[w] = true;
                if (match[w] < 0 || augument(match[w])) {
                    match[v] = w;
                    match[w] = v;
                    ret = true;
                }
            }
        }

        mark[v] = false;
        return ret;
    }

    int gao() {
        int todo = 0, rest = n;

        fill(mark, mark + n, false);
        fill(match, match + n, -1);
        while (todo < n && rest >= 2) {
            if (match[todo] == -1 && augument(todo)) {
                fill(mark, mark + n, false);
                todo = 0;
                rest -= 2;
            } else {
                ++todo;
            }
        }
        return (n - rest) / 2;
    }
};

Matching m;

int main() {
    int n, d;
    int x[MAXN], y[MAXN];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        scanf("%d", &d);
        m.init(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= d) {
                    m.addEdge(i, j);
                }
            }
        }
        puts(m.gao() * 2 == n ? "YES" : "NO");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2159547   2010-04-13 20:22:11     Accepted    3316    C++     10  844     watashi@Zodiac

// 2012-09-07 02:07:14 | Accepted | 3316 | C++ | 10 | 844 | watashi | Source
