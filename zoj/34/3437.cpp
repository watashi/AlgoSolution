#include <cerrno>       /* errno, perror */
#include <cstdio>       /* scanf, printf, puts */
#include <cassert>      /* assert */
#include <climits>      /* LLONG_MIN */
#include <cstdlib>      /* strtoll */

int main() {
    char op, str[80], *ptr;
    int base;
    long long val;

    while (scanf(" %c%d%s", &op, &base, str) != EOF) {
        errno = 0;
        val = strtoll(str, &ptr, base);
        if (errno != 0) {
            perror("strtoll: ");
        }
        assert(errno == 0);
        assert(*ptr == '\0');
        switch (op) {
        case '-':
            if (val == LLONG_MIN) {
                puts("9223372036854775808");    // a trick!
            } else {
                printf("%lld\n", -val);
            }
            break;
        case '!':
            printf("%lld\n", (long long)!val);
            break;
        case '~':
            printf("%lld\n", ~val);
            break;
        default:
            assert(0);
            break;
        }
    }

    return 0;
}

// 2012-09-07 15:55:02 | Accepted | 3437 | C++ | 0 | 180 | watashi | Source
