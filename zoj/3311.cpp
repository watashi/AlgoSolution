#include <cstdio>
#include <cstring>

int main() {
    int a, b, c;
    char buf[1024];

    while (gets(buf) != NULL) {
        if (strchr(buf, 'Z') == NULL || strchr(buf, 'J') == NULL) {
            puts("Wrong Answer");
            continue;
        }
        a = strchr(buf, 'Z') - buf;
        b = strchr(buf, 'J') - buf;
        c = strlen(buf);
        if (strchr(buf + a + 1, 'Z') == NULL &&
            strchr(buf + b + 1, 'J') == NULL &&
            c == b + b &&
            a < b - 1&&
            c >= 4) {
            puts("Accepted");
        } else {
            puts("Wrong Answer");
        }
    }

    return 0;
}

/*
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
3792    2010-03-14 14:54:57     Accepted    G   C++     0   176     watashi@Zodiac
*/

// 2012-09-07 15:46:43 | Accepted | 3311 | C++ | 0 | 180 | watashi | Source
