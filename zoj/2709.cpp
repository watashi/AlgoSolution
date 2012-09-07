#include <utility> // auto fix CE
#include <map>
#include <utility> // auto fix CE
#include <queue>
#include <utility> // auto fix CE
#include <cstdio>
#include <utility> // auto fix CE
#include <vector>
#include <utility> // auto fix CE
#include <numeric>
#include <utility> // auto fix CE
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    long long num, den;

    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {
        long long g = gcd(num, den);
        num /= g;
        den /= g;
    }
};

bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return lhs.num * rhs.den < lhs.den * rhs.num;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}

const int MAXN = 64;

long long c[MAXN][MAXN];

int main() {
    int n, m;
    char buf[1024];
    Fraction frac;

    for (int i = 0; i < MAXN; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    while (scanf("%d%s", &n, buf) != EOF) {
        map<char, int> mp;
        for (int i = 0; buf[i] != '\0'; ++i) {
            ++mp[buf[i]];
        }

        vector<int> v;
        for (map<char, int>::const_iterator i = mp.begin(); i != mp.end(); ++i) {
            v.push_back(i->second);
        }
        sort(v.begin(), v.end());
        m = accumulate(v.begin(), v.end(), 0);

        Fraction fmin(1, c[n][m]);
        for (int i = 1; i <= n - m; ++i) {
            fmin = fmin * Fraction(v.front() + i, i);
        }

        Fraction fmax(1, c[n][m]);
        priority_queue<pair<Fraction, int> > q;
        for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
            q.push(make_pair(Fraction(*i + 1, 1), *i));
        }
        for (int i = 1; i <= n - m; ++i) {
            pair<Fraction, int> p = q.top();
            q.pop();
            fmax = fmax * p.first;
            int t = p.second / (p.first.num - p.first.den);
            p.first = Fraction(p.first.num * t + 1, p.first.den * t + 1);
            q.push(p);
        }

        printf("%lld/%lld\n%lld/%lld\n\n", fmax.num, fmax.den, fmin.num, fmin.den);
    }

    return 0;
}

/*
        Submit     Judge    Problem          Run  Run
Run ID  Time       Status   ID      Language Time Memory User Name
                                             (ms) (KB)
2113179 2010-03-16 Accepted 2709    C++      0    208    watashi@Zodiac
        14:00:59
*/

// 2012-09-07 15:45:23 | Accepted | 2709 | C++ | 0 | 212 | watashi | Source
