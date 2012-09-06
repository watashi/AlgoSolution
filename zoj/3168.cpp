#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char buf[1024];

struct cmpChar {
    char ch;

    cmpChar(char c) : ch(c) {
    }

    bool operator()(char c) const {
        return c == ch;
    }
};

int main() {
    int len, pos;

    while (scanf("%s", buf) != EOF) {
        len = strlen(buf);
        pos = 0;
        pos = stable_partition(buf + pos, buf + len, cmpChar('Z')) - buf;
        pos = stable_partition(buf + pos, buf + len, cmpChar('O')) - buf;
        pos = stable_partition(buf + pos, buf + len, cmpChar('J')) - buf;
        pos = stable_partition(buf + pos, buf + len, cmpChar('7')) - buf;
        printf("%s\n", buf);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801330   2009-03-23 23:26:51     Accepted    3168    C++     10  176     watashi@Zodiac

// 2012-09-07 02:05:30 | Accepted | 3168 | C++ | 10 | 180 | watashi | Source
