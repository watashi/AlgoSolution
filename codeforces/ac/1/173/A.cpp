#include <cstdio>
#include <cstring>

const int MAXN = 1024;
const char *RPS = "RPS";

char s[MAXN], t[MAXN];

int main() {
    int n, x = 0, y = 0;
    int ls, lt;

    scanf("%d%s%s", &n, s, t);
    ls = strlen(s);
    lt = strlen(t);
    for (int i = 0; i < n && i < ls * lt; ++i) {
        int a = strchr(RPS, s[i % ls]) - RPS;
        int b = strchr(RPS, t[i % lt]) - RPS;
        if (b == (a + 1) % 3) {
            x += (n - i - 1) / (ls * lt) + 1;
        } else if (a == (b + 1) % 3) {
            y += (n - i - 1) / (ls * lt) + 1;
        }
    }
    printf("%d %d\n", x, y);

    return 0;
}

