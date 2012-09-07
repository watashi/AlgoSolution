#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m;
    int one[1 << 13];

    one[0] = 0;
    for (int i = 1; i < (1 << 13); ++i) {
        one[i] = one[i >> 1] + (i & 1);
    }
    while (scanf("%d", &n) != EOF && n > 0) {
        m = 1 << n;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &a[i]);
            --a[i];
        }

        vector<int> v;
        for (int k = 0; k < n; ++k) {
            vector<int> b;
            vector<int> c;
            for (int i = 0; i < m; ++i) {
                v.push_back(a[i]);
                if ((a[i] >> k) % 4 == 0 || (a[i] >> k) % 4 == 3) {
                    b.push_back(a[i]);
                    v.push_back(a[i]);
                } else {
                    c.push_back(a[i]);
                }
            }
            a.clear();
            a.insert(a.end(), b.begin(), b.end());
            a.insert(a.end(), c.rbegin(), c.rend());
            v.insert(v.end(), c.rbegin(), c.rend());
        }

        for (size_t i = 0; i < v.size(); ++i) {
            printf("%d%c", v[i] + 1, i == v.size() - 1 ? '\n' : ' ');
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2175487   2010-04-24 18:56:31     Accepted    2603    C++     160     1752    watashi@Zodiac

// 2012-09-07 15:42:43 | Accepted | 2603 | C++ | 150 | 1756 | watashi | Source
