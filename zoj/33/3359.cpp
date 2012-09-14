#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cstring>

int main() {
    int re;
    char buf[80];
    int a[80], b[80], x, y;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        for (int i = 0; i < 11; ++i) {
            for (int j = 0; j < 3; ++j) {
                scanf("%s", buf);
                a[j * 11 + i] = (buf[0] == 'y' ? 1 : 0);
            }
        }
        for (int i = 0; i < 11; ++i) {
            for (int j = 0; j < 3; ++j) {
                scanf("%s", buf);
                b[j * 11 + i] = (buf[0] == 'y' ? 1 : 0);
            }
        }
        x = y = 0;
        for (int i = 0; i < 11 * 3; ++i) {
            if (i >= 5 && x != y) {
                break;
            }
            x += a[i];
            if (i < 5 && (x > y + 5 - i || y > x + 4 - i)) {
                break;
            }
            y += b[i];
            if (i < 5 && (y > x + 4 - i || x > y + 4 - i)) {
                break;
            }
        }
        printf("Match %d:\nWinner: %s\nScore: %d:%d\n", ri, (x > y) ? "home" : "away", x, y);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//594   2010-07-16 19:57:42     Accepted    1084    C++     20  180     anotherpeg  Source

// 2012-09-07 15:48:33 | Accepted | 3359 | C++ | 10 | 180 | watashi | Source
