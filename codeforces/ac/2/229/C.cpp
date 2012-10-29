#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

int d[MAXN];

int main() {
    int n, m, a, b, c;
    long long ans;

    scanf("%d%d", &n, &m);
    ans = 1LL * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a;
        --b;
        ++d[a];
        ++d[b];
        ans -= n;
        ans += d[a] + d[b];
    }
    printf("%I64d\n", ans);

    return 0;
}

