#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAXN = 1 << 20;

int a[MAXN], b[MAXN];
long long c[MAXN + MAXN];

unordered_map<int, int> mp(MAXN);

int main() {
    int n, m, ans = 0;

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        mp[b[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        c[i] = mp.count(a[i]) > 0 ? mp[a[i]] : -1;
    }
    copy(c, c + n, c + n);
    for (int i = 1; i < n + n; ++i) {
        if (c[i] != -1 && c[i - 1] != -1 && c[i] <= c[i - 1]) {
            c[i] += ((c[i - 1] - c[i]) / m + 1) * m;
        }
    }
    for (int i = 0, j = 0; i < n; ++i) {
        j = max(i, j);
        while (c[j] != -1 && c[j] - c[i] < m) {
            ++j;
            ans = max(ans, j - i);
        }
        if (c[j] == -1) {
            i = j;
        }
    }
    printf("%d\n", ans);

    return 0;
}

