#include <algorithm> // auto fix CE
#include <cctype>
#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>
#include <algorithm> // auto fix CE
#include <cstring>

int main() {
    int len;
    char buf[1 << 20];

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        len = strlen(buf) - 1;
        assert(0 < len && len <= 4096);
        for (int off = 0; off < len; off += 16) {
            printf("%04x: ", off);
            for (int pos = off; pos < off + 16; ++pos) {
                if (pos < len) {
                    printf("%02x", buf[pos]);
                } else {
                    printf("  ");
                }
                if (pos % 2 != 0) {
                    putchar(' ');
                }
            }
            for (int pos = off; pos < off + 16 && pos < len; ++pos) {
                assert(isprint(buf[pos]));
                putchar(isupper(buf[pos]) ? tolower(buf[pos]) : toupper(buf[pos]));
            }
            putchar('\n');
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2675327   2011-10-02 20:09:15     Accepted    3542    C++     0   180     watashi     Source

// 2012-09-07 16:04:50 | Accepted | 3542 | C++ | 0 | 180 | watashi | Source
