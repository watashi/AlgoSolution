// #include <map>
#include <ext/hash_map>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

typedef vector<char> VI;

namespace __gnu_cxx {
    template<>
    struct hash<VI> {
        size_t operator()(const VI& v) const {
            size_t ret = 0;
            for (VI::const_iterator i = v.begin(); i != v.end(); ++i) {
                ret = ret * 37 + *i;
            }
            return ret;
        }
    };
};

typedef hash_map<VI, string> MVI;

int main() {
    int n, q, p, x;
    int m[12], l[12];
    VI vs, vt;

    while (scanf("%d%d%d", &n, &q, &p) != EOF) {
        vs.resize(n);
        vt.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            vs[i] = x - 1;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            vt[i] = x - 1;
        }
        for (int i = 0; i < p; ++i) {
            scanf("%d%d", &l[i], &m[i]);
            l[i] = n - l[i];
            m[i] = l[i] - m[i];
        }

        // forward
        MVI s;
        s[vs] = "";
        for (int i = 0; i < q / 2; ++i) {
            MVI tmp;
            for (MVI::const_iterator j = s.begin(); j != s.end(); ++j) {
                for (int k = 0; k < p; ++k) {
                    VI v(j->first);
                    rotate(v.begin(), v.begin() + m[k], v.begin() + l[k]);
                    tmp[v] = j->second + (char)('1' + k);
                }
            }
            s.swap(tmp);
        }
        fprintf(stderr, "%d ", (int)s.size());

        // backward
        MVI t;
        t[vt] = "";
        for (int i = 0; i < p; ++i) {
            m[i] = l[i] - m[i];
        }
        for (int i = 0; i < (q + 1) / 2; ++i) {
            MVI tmp;
            for (MVI::const_iterator j = t.begin(); j != t.end(); ++j) {
                for (int k = 0; k < p; ++k) {
                    VI v(j->first);
                    rotate(v.begin(), v.begin() + m[k], v.begin() + l[k]);
                    tmp[v] = j->second + (char)('1' + k);
                }
            }
            t.swap(tmp);
        }
        fprintf(stderr, "%d\n", (int)t.size());

        //
        string ans = "";
        for (MVI::const_iterator i = s.begin(); i != s.end(); ++i) {
            if (t.count(i->first) > 0) {
                ans = i->second + string(t[i->first].rbegin(), t[i->first].rend());
            }
        }
        if (ans == "") {
            puts("Impossible");
        } else {
            for (int i = 0; i < q; ++i) {
                printf("%c%c", ans[i], i == q - 1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}

//real  0m11.372s
//user  0m10.909s
//sys   0m0.412s

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//182   2010-07-08 14:43:57     Accepted    asc11j  C++     17860   53732   watashi@Zodiac  Source

// 2012-09-07 16:58:20 | Accepted | 3371 | C++ | 17760 | 53736 | watashi | Source
