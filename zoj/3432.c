#include <unistd.h>

long long buf[1 << 21];

int main(void) {
    char ch;
    int n, m, i;
    long long xor[2] = {0LL, 0LL};

    while (read(0, &ch, 1) > 0) {
        n = 0;
        do {
            n = n * 10 + (ch - '0');
            read(0, &ch, 1);
        } while (ch != '\n');
        m = n + n - 1;
        read(0, buf, 8 * m);
        *xor = 0;
        for (i = 0; i < m; ++i) {
            *xor ^= buf[i];
        }
        write(1, xor, 8);
    }

    return 0;
}

/*
Run ID  Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
370     2010-11-10 00:01:08     Accepted    F   C   30  16536   watashi@Zodiac  Source
*/

// 2012-09-07 15:54:31 | Accepted | 3432 | C | 10 | 16536 | watashi | Source
