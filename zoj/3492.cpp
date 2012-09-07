#include <set>
#include <cctype>
#include <cstdio>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

int main() {
    int re, n;
    char str[80];
    string a[128];
    set<string> s;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d", &n) == 1);
        assert(n % 2 == 0 && 2 <= n && n <= 100);
        s.clear();
        for (int i = 0; i <= n; ++i) {
            assert(scanf("%s", str) == 1);
            a[i] = str;
            assert(a[i].length() <= 20);
            for (int j = 0; j < (int)a[i].length(); ++j) {
                assert(isalnum(a[i][j]));
            }
            if (i > 0) {
                s.insert(a[i]);
            }
        }
        int k = find(a + 1, a + 1 + n, a[0]) - a;
        assert(1 <= k && k <= n && (int)s.size() == n);
        puts(a[(k - 1 + n / 2) % n + 1].c_str());
    }
    assert(scanf("%d", &n) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//471   2011-04-15 01:46:59     Accepted    F   C++     30  180     watashi     Source

// 2012-09-07 16:01:41 | Accepted | 3492 | C++ | 10 | 180 | watashi | Source
