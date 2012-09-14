#include <algorithm> // auto fix CE
#include <list>
#include <algorithm> // auto fix CE
#include <cstdio>

using namespace std;

char buf[65536], *pbuf;

int main() {
    int x, y, z, nbuf;
    list<int> a, b;
    list<int>::iterator it;

    while (scanf(" [ %d : %d ]%[^\n]", &x, &y, buf) != EOF) {
        pbuf = buf;
        while (sscanf(pbuf, "%*[^-0-9]%d%n", &z, &nbuf) > 0) {
            pbuf += nbuf;
            b.push_back(z);
        }

        it = a.begin();
        advance(it, x);
        for (int i = x; i < y; ++i) {
            printf("%s%d", i == x ? "" : ", ", *it);
            it = a.erase(it);
        }
        puts("");
        a.splice(it, b);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//420   2010-11-13 03:42:47     Accepted    A   C++     0   244     watashi@Zodiac  Source

// 2012-09-07 15:53:45 | Accepted | 3427 | C++ | 0 | 244 | watashi | Source
