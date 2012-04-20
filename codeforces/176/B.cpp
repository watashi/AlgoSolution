#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const long long MOD = 1000000007;

typedef vector<long long> OP;

OP compose(int n, const OP& a, const OP& b) {
    OP c(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[(i + j) % n] += a[i] * b[j] % MOD;
        }
    }
    for (long long& i: c) {
        i %= MOD;
    }
    return c;
}

int main() {
    int n, m;
    string s, t;
    vector<int> p;
    OP a, b;
    long long ans;

    cin >> s >> t >> m;
    n = s.length();
    s = s + s;
    for (int i = 0; i < n; ++i) {
        if (s.substr(i, n) == t) {
            p.push_back(i);
        }
    }

    a = OP(n, 1);
    b = OP(n, 0);
    a[0] = 0;
    b[0] = 1;
    while (m > 0) {
        if (m & 1) {
            b = compose(n, a, b);
        }
        a = compose(n, a, a);
        m >>= 1;
    }

    ans = 0;
    for (int i: p) {
        ans += b[i];
    }

    cout << ans % MOD << endl;

    return 0;
}

