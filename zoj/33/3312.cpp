#include <cstdio> // auto fix CE
#include <map>
#include <cstdio> // auto fix CE
#include <string>
#include <cstdio> // auto fix CE
#include <utility>
#include <cstdio> // auto fix CE
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    int num, den;

    Fraction(int n = 0, int d = 1) {
        int g = gcd(n, d);
        n /= g;
        d /= g;
        if (d < 0) {
            n = -n;
            d = -d;
        }
        num = n;
        den = d;
    }
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den + lhs.den * rhs.num, lhs.den * rhs.den);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den - lhs.den * rhs.num, lhs.den * rhs.den);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return lhs.num == rhs.num ? lhs.den < rhs.den : lhs.num < rhs.num;
}

map<Fraction, string> mp[9];

#define GAO(op) \
    t = x->first op y->first;\
    if (mp[i].count(t) == 0) {\
        mp[i][t] = "(" + x->second + #op + y->second + ")";\
    }

int main() {
    Fraction t;
    string s = "";
    int f = 0;

    for (int i = 1; i <= 8; ++i) {
        f = f * 10 + 8;
        s += '8';
        mp[i][f] = s;
        for (int j = 1; j < i; ++j) {
            int k = i - j;
            for (map<Fraction, string>::const_iterator x = mp[j].begin(); x != mp[j].end(); ++x) {
                for (map<Fraction, string>::const_iterator y = mp[k].begin(); y != mp[k].end(); ++y) {
                    if (j <= k) {
                        GAO(+)
                        GAO(*)
                    }
                    if (y->first.num != 0) {
                        GAO(/)
                    }
                    GAO(-)
                }
            }
        }
    }

    while (scanf("%d", &f) != EOF) {
        t = Fraction(f);
        if (mp[8].count(t) == 0) {
            puts("Impossible");
        } else {
            s = mp[8][t];
            if (s[0] == '(') {
                s = s.substr(1, s.length() - 2);
            }
            puts(s.c_str());
        }
    }

    return 0;
}

/*
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
3395    2010-03-14 14:38:39     Accepted    H   C++     290     6380    watashi@Zodiac
*/

// 2012-09-07 15:46:49 | Accepted | 3312 | C++ | 260 | 6384 | watashi | Source
