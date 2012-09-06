#include <cstdio>

int main()
{
    int n, x, y;
    static char buf[128];

    while (scanf("%d", &n) != EOF && n >= 0) {
        x = y = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", buf);
            x += i / 2;
            y += i / 2;
            if (i % 2 == 0) {
                continue;
            }
            for (int j = 0; j <= i; j++) {
                if (buf[j] == '?') {
                    continue;
                }
                else if (buf[j] == '\0') {
                    ++x;
                }
                else if (!((buf[j] == '@') ^ (j % 2 == 0))) {
                    ++x;
                    ++y;
                }
                break;
            }
        }
        printf("%d %d\n", x, y);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1689794   2008-11-05 09:06:30     Accepted    2058    C++     0   176     watashi@Zodiac

// 2012-09-07 01:11:34 | Accepted | 2058 | C++ | 0 | 180 | watashi | Source
