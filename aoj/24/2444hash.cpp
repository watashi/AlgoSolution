#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 300300;

template<int BASE, int MOD>
struct Hash {
    int n, a[MAXN], b[MAXN];

    void init(int n, const char s[]) {
        this->n = n;
        a[0] = 0;
        b[0] = 1;
        for (int i = 0; i < n; ++i) {
            a[i + 1] = (1LL * b[i] * s[i] + a[i]) % MOD;
            b[i + 1] = 1LL * b[i] * BASE % MOD;
        }
    }

    int operator()(int l, int r) {
        return 1LL * (a[r] - a[l] + MOD) * b[n - l] % MOD;
    }
};

Hash<29, 1000000007> h1;
Hash<31, 1000000009> h2;

char buf[MAXN], op[80];

int main() {
    int n, m, l, r;
    set<pair<int, pair<int, int> > > st;

    scanf("%d%d", &n, &m);
    scanf("%s", buf);
    h1.init(n, buf);
    h2.init(n, buf);

    l = 0;
    r = 1;
    for (int i = 0; i < m; ++i) {
        scanf("%s", op);
        int& t = op[0] == 'L' ? l : r;
        t += op[1] == '+' ? 1 : -1;
        st.insert(make_pair(r - l, make_pair(h1(l, r), h2(l, r))));
    }
    printf("%d\n", (int)st.size());

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#489423 	watashi 	2444 	: Accepted 	C++ 	00:11 sec 	24760 KB 	1119 Bytes 	Wed Sep 19 17:04:06

