#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2048;

char s[MAXN], t[MAXN];

int main() {
    int n, m, tmp, ans;

    scanf("%s%s", s, t);
    n = strlen(s);
    m = strlen(t);
    ans = 1000000007;
    for (int i = -m; i < n; ++i) {
        tmp = 0;
        for (int j = 0; j < m; ++j) {
            if (i + j < 0 || i + j >= n || s[i + j] != t[j]) {
                ++tmp;
            }
        }
        ans = min(ans, tmp);
    }
    printf("%d\n", ans);

    return 0;
}

