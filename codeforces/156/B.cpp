#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int a[MAXN], c[MAXN], d;

int main() {
    int n, m, t;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > 0) {
            ++c[a[i]];
        } else {
            --c[-a[i]];
            ++d;
        }
    }
    t = count(c + 1, c + n + 1, m - d);
    fprintf(stderr, "t = %d\n", t);
    for (int i = 1; i <= n; ++i) {
        if (c[abs(a[i])] != m - d) {
            puts(a[i] > 0 ? "Lie" : "Truth");
        } else if (t == 1) {
            puts(a[i] > 0 ? "Truth" : "Lie");
        } else {
            puts("Not defined");
        }
    }

    return 0;
}

