#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

char buf[MAXN];
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main() {
    int re, n, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%s", buf);
        n = strlen(buf);

        a[0] = 0;
        b[0] = 0;
        for (int i = 0; i < n; ++i) {
            a[i + 1] = a[i];
            b[i + 1] = b[i];
            if (buf[i] == '4') {
                ++a[i + 1];
            } else {
                ++b[i + 1];
            }
        }

        c[0] = m = 0;
        for (int i = 0; i < n; ++i) {
            if (buf[i] == '7') {
                ++m;
            } else {
                --m;
            }
            m = max(m, 0);
            c[i + 1] = max(c[i], m);
        }

        d[n] = m = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (buf[i] == '4') {
                ++m;
            } else {
                --m;
            }
            m = max(m, 0);
            d[i] = max(d[i + 1], m);
        }

        m = 0;
        for (int i = 0; i <= n; ++i) {
            // printf("%d + %d + (%d, %d)\n", a[i], b[n] - b[i], c[i], d[i]);
            m = max(m, a[i] + (b[n] - b[i]) + max(c[i], d[i]));
        }
        printf("%d\n", m);
    }

    return 0;
}

