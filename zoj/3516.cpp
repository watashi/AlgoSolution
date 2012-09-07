#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 10086;

vector<int> e[MAXN];
int v[MAXN][3];

void gao(int p) {
    static int w[MAXN];
    for (vector<int>::const_iterator i = e[p].begin(); i != e[p].end(); ++i) {
        gao(*i);
        merge(v[p], v[p] + 3, v[*i], v[*i] + 3, w, greater<int>());
        copy(w, w + 3, v[p]);
    }
}

int main() {
    int n, p, q;

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            e[i].clear();
            fill(v[i], v[i] + 3, -1);
        }
        scanf("%d", &v[0][0]);
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &p, &v[i][0]);
            e[p].push_back(i);
        }
        gao(0);
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            scanf("%d", &p);
            if (v[p][2] == -1) {
                puts("-1");
            } else {
                printf("%d %d %d\n", v[p][0], v[p][1], v[p][2]);
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//900   2010-07-21 21:17:50     Accepted    1103    C++     310     720     anotherpeg  Source

// 2012-09-07 16:04:20 | Accepted | 3516 | C++ | 180 | 720 | watashi | Source
