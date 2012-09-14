// #include <set>
#include <cstdio>
#include <utility>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

const int MAXN = 3003;
int a[MAXN];
short dp[MAXN][MAXN];
// set<pair<int, int> > st; // TLE(0.62s)
// set<pair<int, int> >::const_iterator it;
hash_map<int, int> mp(MAXN);    // TLE(0.15s)
hash_map<int, int>::const_iterator it;
/*
struct Hash {
    static const int mask = 0x7fff;
    int p[32768], q[32768];

    void clear() {
        for (int i = 0; i <= mask; ++i) {
            q[i] = -1;
        }
    }

    int& operator[](int k) {
        int i = k & mask;
        for (int j = 0; q[i] != -1 && p[i] != k; i = (i + 1) & mask) {
            continue;
        }
        p[i] = k;
        return q[i];
    }
} hash;
*/
int main() {
    bool blank = false;
    int n, m;
    pair<int, int> p;

    while (scanf("%d", &n) != EOF) {
        if (blank) {
            puts("");
        } else {
            blank = true;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = 1;
            }
        }

        m = 0;
        p.first = a[0];
        mp.clear();
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                // int k = a[i] + a[j];
                // it = st.upper_bound(make_pair(k, j));
                it = mp.find(a[j] + a[i]);
                if (it != mp.end()) {
                    dp[j][i] = dp[i][it->second] + 1;
                }
                if (dp[j][i] > m) {
                    m = dp[j][i];
                    p = make_pair(a[j], a[i]);
                }
            }
            mp[a[i]] = i;
        }

        printf("%d\n", m + 1);
        printf("%d", p.first);
        for (int i = 0; i < m; ++i) {
            printf(" %d", p.second);
            p = make_pair(p.second, p.first + p.second);
        }
        puts("");
    }

    return 0;
}
/*
 * MyHash
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
2128941     2010-03-27 16:50:26     Accepted    2672    C++     1720    18056   watashi@Zodiac
*/
/*
 * hash_map
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
2128955     2010-03-27 16:54:15     Accepted    2672    C++     2610    17800   watashi@Zodiac
*/

// 2012-09-07 15:43:01 | Accepted | 2672 | C++ | 2580 | 17804 | watashi | Source
