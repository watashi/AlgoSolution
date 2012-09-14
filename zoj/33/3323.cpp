#include <cctype>
#include <cstdio>

int main() {
    int ch;

    while (getchar() != '\n') {
        continue;
    }
    while ((ch = getchar()) != EOF) {
        if (!isdigit(ch)) {
            putchar(ch);
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2168612   2010-04-19 00:52:27     Accepted    3323    C++     0   176     watashi@Zodiac

// 2012-09-07 02:07:57 | Accepted | 3323 | C++ | 0 | 180 | watashi | Source
