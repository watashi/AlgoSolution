#include <map>
#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

long long a[MAXN];
map<int, long long> cache;

int main() {
    int n, m, k;
    long long ans;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        a[i] = k;
    }
    sort(a, a + n);
    reverse(a, a + n);
    partial_sum(a, a + n, a);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &k);
        if (cache.count(k) == 0) {
            ans = 0;
            for (long long s = 1, t = k; s < n; s += t, t *= k) {
                ans += a[n - 1] - a[s - 1];
            }
            cache[k] = ans;
        } else {
            ans = cache[k];
        }
        printf("%I64d\n", ans);
    }

    return 0;
}

