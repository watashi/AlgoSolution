#include <algorithm> // auto fix CE
#include <map>
#include <algorithm> // auto fix CE
#include <bitset>
#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <vector>
#include <algorithm> // auto fix CE
#include <string>
#include <algorithm> // auto fix CE
#include <cassert>
#include <algorithm> // auto fix CE
#include <cstring>

using namespace std;

int main() {
    int n, m;
    long long ans;
    char buf[65536], *p, *q;
    bitset<1024> mask;
    vector<long long> sz;
    map<string, bitset<1024> > mp;
    map<string, bitset<1024> >::const_iterator it;

    while (scanf("%d", &n) != EOF) {
        mp.clear();
        sz.resize(n);
        for (int i = 0; i < n; ++i) {
            assert(scanf("%s%lld", buf, &sz[i]) == 2);
            p = buf;
            while ((p = strchr(p, '[')) != NULL) {
                q = strchr(p, ']');
                // printf("\t[%s]\n", string(p + 1, q).c_str());
                mp[string(p + 1, q)].set(i);
                p = q;
            }
        }

        assert(scanf("%d", &m) == 1);
        for (int i = 0; i < m; ++i) {
            assert(scanf("%s", buf) == 1);

            mask.reset();
            for (int j = 0; j < n; ++j) {
                mask.set(j);
            }

            p = buf;
            while ((p = strchr(p, '[')) != NULL) {
                q = strchr(p, ']');
                // printf("[%s]\n", string(p + 1, q).c_str());
                it = mp.find(string(p + 1, q));
                if (it == mp.end()) {
                    mask.reset();
                    break;
                } else {
                    mask &= it->second;
                }
                p = q;
            }

            ans = 0;
            for (int j = 0; j < n; ++j) {
                if (mask[j]) {
                    ans += sz[j];
                }
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//902   2010-07-21 21:19:41     Accepted    1106    C++     360     320     anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//694   2011-01-30 15:42:33     Accepted    F   C++     270     320     watashi@ArcOfDream  Source

// 2012-09-07 15:58:32 | Accepted | 3462 | C++ | 260 | 320 | watashi | Source
