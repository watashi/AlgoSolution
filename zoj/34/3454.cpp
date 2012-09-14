#include <algorithm> // auto fix CE
#include <map>
#include <algorithm> // auto fix CE
#include <stack>
#include <algorithm> // auto fix CE
#include <cstdio>

using namespace std;

const int MAXN = 1 << 17;

int p[MAXN];

void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (p[i] != 0) {
            continue;
        }
        for (int j = i; j < MAXN; j += i) {
            p[j] = i;
        }
    }
}

struct LCM {
    static const long long MOD = 1000000007LL;

    static long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }

    map<int, int> mp;

    void feed(int x) {
        while (x > 1) {
            int p = ::p[x];
            int c = 0;
            do {
                x /= p;
                ++c;
            } while (x % p == 0);
            mp[p] = max(mp[p], c);
        }
    }

    long long lcm() const {
        long long ret = 1;
        for (map<int, int>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
            for (int i = 0; i < it->second; ++i) {
                ret *= it->first;
            }
            ret %= MOD;
        }
        return ret;
    }
};

int a[MAXN], x[MAXN], y[MAXN];

int main() {
    int n, p, q;

    init();
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            x[i] = y[i] = -1;
        }
        for (int i = 0; i < n; ++i) {
            if (x[i] != -1) {
                continue;
            }

            stack<int> s;

            p = i;
            while (true) {
                x[p] = s.size();
                s.push(p);
                q = a[p];
                if (x[q] != -1) {
                    if (y[q] == -1) {   // circle
                        int loop = x[p] + 1 - x[q];
                        for (int i = 0; i < loop; ++i) {
                            x[s.top()] = 0;
                            y[s.top()] = loop;
                            s.pop();
                        }
                    } else {    // non-circle
                        break;
                    }
                    break;
                } else {
                    p = q;
                }
            }
            while (!s.empty()) {
                p = s.top();
                s.pop();
                x[p] = x[a[p]] + 1;
                y[p] = y[a[p]];
            }
        }

        int base = 0;
        LCM lcm;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p);
            base = max(base, x[p]);
            lcm.feed(y[p]);
        }
        printf("%lld\n", (base + lcm.lcm()) % LCM::MOD);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//609   2010-12-23 19:31:34     Accepted    J   C++     150     2624    watashi@Zodiac  Source

// 2012-09-07 15:57:42 | Accepted | 3454 | C++ | 120 | 2624 | watashi | Source
