#include <algorithm> // auto fix CE
#include <cstdio>

int main() {
    int ch;

    while ((ch = getchar()) != -1) {
        switch (ch) {
            case '.':
                putchar('[');
                putchar('.');
                putchar(']');
                break;
            case '?':
                putchar('.');
                break;
            case '*':
                putchar('.');
                putchar('*');
                break;
            case '[':
                putchar('[');
                ch = getchar();
                if (ch == '!') {
                    putchar('^');
                    ch = getchar();
                }
                do {
                    putchar(ch);
                    ch = getchar();
                } while (ch != ']');
                putchar(']');
                break;
            default:
                putchar(ch);
                break;
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//213   2010-08-12 14:57:34     Accepted    akyu    C++     350     176     watashi@Zodiac  Source

// 2012-09-07 15:50:00 | Accepted | 3373 | C++ | 350 | 180 | watashi | Source
