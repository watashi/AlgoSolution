#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <vector>
#include <cstdlib> // auto fix CE
#include <utility>
#include <cstdlib> // auto fix CE
#include <algorithm>
#include <cstdlib> // auto fix CE
#include <functional>

using namespace std;

typedef pair<int, int> PII;
typedef vector<PII> LIST;

#define ALL(l) l.begin(), l.end()

bool read(LIST& v) {
    static int ch;
    if ((ch = getchar()) == EOF) {
        return false;
    }
    v.clear();
    while (ch != '\n') {
        ungetc(ch, stdin);
        scanf("%d", &ch);
        v.push_back(make_pair(ch, (int)v.size()));
        ch = getchar();
    }
    return true;
}

void write(const LIST& v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        printf("%s%d", i == 0 ? "" : " ", v[i].first);
    }
    puts("");
}

inline PII pabs(const PII& p) {
    return PII(abs(p.first), p.second);
}

inline bool byfst(const PII& lhs, const PII& rhs) {
    return lhs.first < rhs.first;
}

inline bool bysnd(const PII& lhs, const PII& rhs) {
    return lhs.second < rhs.second;
}

int main() {
    const PII ZERO = make_pair(0, 0);
    LIST a, b;

    while (read(a) && read(b)) {
        a.erase(remove_if(ALL(a), bind2nd(less<PII >(), ZERO)), a.end());
        transform(ALL(b), b.begin(), pabs);
        sort(ALL(a));
        sort(ALL(b));
        a.erase(set_difference(ALL(a), ALL(b), a.begin(), byfst), a.end());
        sort(ALL(a), bysnd);
        write(a);
    }

    return 0;
}

// 2012-09-07 15:55:44 | Accepted | 3441 | C++ | 260 | 2752 | watashi | Source
