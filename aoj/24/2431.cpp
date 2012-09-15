#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;

struct SegTree {
    int n;
    long long a[MAXN + MAXN];

    static int L(int i) { return i << 1; }
    static int R(int i) { return L(i) ^ 1; }

    void init(int m) {
        n = 1;
        while (n < m) {
            n <<= 1;
        }
        fill(a, a + n + n, 0);
    }

    void set(int i, long long b) {
        i += n;
        while (i > 0) {
            a[i] = max(a[i], b);
            i >>= 1;
        }
    }

    long long get(int p, int pl, int pr, int l, int r) {
        if (pl == l && pr == r) {
            return a[p];
        } else {
            int pm = (pl + pr) / 2;
            if (r <= pm) {
                return get(L(p), pl, pm, l, r);
            } else if (pm <= l) {
                return get(R(p), pm, pr, l, r);
            } else {
                return max(get(L(p), pl, pm, l, pm), get(R(p), pm, pr, pm, r));
            }
        }
    }

    long long get(int i) {
        return get(1, 0, n, 0, i);
    }
} st;

int main() {
    int n, x;

    scanf("%d", &n);
    st.init(n + 1);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        st.set(x, st.get(x) + x);
    }
    printf("%lld\n", (1LL + n) * n / 2 - st.get(n + 1));

    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#485978 	watashi 	2431 	: Accepted 	C++ 	00:02 sec 	3076 KB 	1290 Bytes 	Sun Sep 16 02:06:13

