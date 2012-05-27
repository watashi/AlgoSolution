#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 32;
const int MAXM = 1 << 20;

int a[MAXN], b[MAXN];

int main() {
    int n, m, k, c;
    int p[MAXN];

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }

    c = 0;
    for (int i = 0; i < MAXM; ++i) {
        for (int j = 0; j < n; ++j) {
            p[j] = j;
        }
        for (int j = 0; j < k; ++j) {
            int x = rand() % n;
            int y = rand() % (n - 1);
            if (y >= x) {
                ++y;
            }
            swap(p[x], p[y]);
        }
        bool flag = true;
        for (int j = 0; j < m; ++j) {
            int d = abs(p[a[j]] - p[b[j]]);
            flag &= d != 1 && d != n - 1;
        }
        if (flag) {
            ++c;
        }
    }

    printf("%lf\n", 1.0 * c / MAXM);

    return 0;
}

