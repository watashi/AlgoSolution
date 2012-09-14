#include <map>
#include <cctype>
#include <cstdio>

using namespace std;

bool nextInt(int& i) {
    static int ch = '\0';

    if (ch == EOF) {
        return false;
    }
    while ((ch = getchar()) != EOF && !isdigit(ch)) {
        continue;
    }
    if (ch == EOF) {
        return false;
    }
    i = 0;
    do {
        i *= 10;
        i += ch - '0';
    } while ((ch = getchar()) != EOF && isdigit(ch));

    return true;
}

int main() {
    int i, k, p;
    multimap<int, int> mp;
    multimap<int, int>::iterator itr;

    while (nextInt(i)) {
        switch (i) {
        case 0:
            mp.clear();
            break;
        case 1:
            nextInt(k);
            nextInt(p);
            mp.insert(make_pair(p, k));
            break;
        case 2:
        case 3:
            if (mp.empty()) {
                puts("0");
            } else {
                itr = i == 3 ? mp.begin() : --mp.end();
                printf("%d\n", itr->second);
                mp.erase(itr);
            }
            break;
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1749930   2009-01-28 02:17:43     Accepted    3114    C++     60  176     watashi@Zodiac

// 2012-09-07 02:02:02 | Accepted | 3114 | C++ | 60 | 180 | watashi | Source
