#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

struct DisjointSet {
    int p[MAXN], s[MAXN];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            s[i] = 1;
        }
    }

    int getp(int i) {
        return p[i] == i ? i : (p[i] = getp(p[i]));
    }

    void setp(int i, int j) {
        i = getp(i);
        j = getp(j);
        if (i != j) {
            p[i] = j;
            s[j] += s[i];
        }
    }
} st;

long long pow(long long a, long long b, long long m) {
    long long c = 1 % m;
    while (b > 0) {
        if (b & 1) {
            c = c * a % m;
        }
        b >>= 1;
        a = a * a % m;
    }
    return c;
}

int main() {
    int n, m, mod, a, b;
    long long ans;
    vector<int> v;

    scanf("%d%d%d", &n, &m, &mod);
    st.init(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        st.setp(a - 1, b - 1);
    }
    for (int i = 0; i < n; ++i) {
        if (st.getp(i) == i) {
            v.push_back(st.s[i]);
        }
    }

    ans = 0;
    ans += pow(n, (int)v.size() - 1, mod);
    ans -= (n - v.back()) * pow(n, (int)v.size() - 2, mod);
    ans = (ans % mod + mod) % mod;
    v.pop_back();
    for (int i: v) {
        ans = ans * i % mod;
    }
    printf("%d\n", (int)ans);

    return 0;
}

