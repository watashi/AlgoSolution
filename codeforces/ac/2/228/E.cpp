#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

struct DisjointSet {
    int p[MAXN];

    static inline int RE(int i) { return -1 - i; }

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    int getp(int i) {
        if (i < 0) {
            return RE(getp(RE(i)));
        } else if (i == p[i]) {
            return i;
        } else {
            return p[i] = getp(p[i]);
        }
    }

    int setp(int i, int j) {
        i = getp(i);
        j = getp(j);
        if (i == j) {
            return 0;
        } else if (i == RE(j)) {
            return -1;
        } else {
            if (i < 0) {
                i = RE(i);
                j = RE(j);
            }
            p[i] = j;
            return 1;
        }
    }
} ds;

int main() {
    int n, m, a, b, c;

    scanf("%d%d", &n, &m);
    ds.init(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        --a;
        --b;
        if (ds.setp(a, c == 1 ? b : DisjointSet::RE(b)) == -1) {
            puts("Impossible");
            return 0;
        }
    }

    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        if (ds.getp(i) < 0) {
            ans.push_back(i);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i: ans) {
        printf("%d ", i + 1);
    }

    return 0;
}

