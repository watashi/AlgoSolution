#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char buf[1 << 20];

int main() {
    int n, c0, c1, cc;
    bool ok[4];

    scanf("%s", buf);
    n = (int)strlen(buf);
    c0 = count(buf, buf + n, '0');
    c1 = count(buf, buf + n, '1');
    cc = count(buf, buf + n, '?');
    // printf("%d %d %d\n", c0, c1, cc);

    fill(ok, ok + 4, false);
    if (c0 + cc > c1) {
        ok[0] = true;
    }
    if (c0 < c1 + cc - 1) {
        ok[3] = true;
    }
    if (c0 <= n / 2 && c1 <= (n + 1) / 2) {
        if (buf[n - 1] == '1' || (buf[n - 1] == '?' && c1 < (n + 1) / 2)) {
            ok[1] = true;
        }
        if (buf[n - 1] == '0' || (buf[n - 1] == '?' && c0 < n / 2)) {
            ok[2] = true;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (ok[i]) {
            printf("%d%d\n", i >> 1, i & 1);
        }
    }

    return 0;
}
