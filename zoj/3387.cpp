#include <cstdio>

int main() {
    bool blank = false;
    int n, m, a, b;
    char op[80];

    while (scanf("%d", &n) != EOF && n > 0) {
        if (blank) {
            puts("");
        } else {
            blank = true;
        }
        a = b = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s%d", op, &m);
            if (op[0] == 'D') {
                b += m;
                printf("DROP 2 %d\n", m);
            } else if (a >= m) {
                a -= m;
                printf("TAKE 1 %d\n", m);
            } else {
                if (a > 0) {
                    m -= a;
                    printf("TAKE 1 %d\n", a);
                }
                a = b;
                b = 0;
                printf("MOVE 2->1 %d\n", a);
                a -= m;
                printf("TAKE 1 %d\n", m);
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2377784   2010-12-25 21:19:51     Accepted    3387    C++     0   180     watashi@Zodiac  Source

// 2012-09-07 02:08:52 | Accepted | 3387 | C++ | 0 | 180 | watashi | Source
