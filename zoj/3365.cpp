#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

bool cmp(const PII& lhs, const PII& rhs) {
    return lhs.second < rhs.second;
}

int main() {
    int n, a;
    map<int, int> mp;
    map<int, int>::const_iterator it;

    while (scanf("%d", &n) != EOF) {
        mp.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            ++mp[a - i];
        }
        it = max_element(mp.begin(), mp.end(), cmp);

        printf("%d\n%d", n - it->second, it->first);
        for (int i = 1; i < n; ++i) {
            printf(" %d", it->first + i);
        }
        puts("");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//174   2010-07-08 14:38:38     Accepted    asc11d  C++     380     1628    watashi@Zodiac  Source

// 2012-09-07 15:49:10 | Accepted | 3365 | C++ | 340 | 1632 | watashi | Source
