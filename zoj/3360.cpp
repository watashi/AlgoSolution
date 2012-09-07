#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <vector>

using namespace std;

const int LIMIT = 10000;

template<typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    int num, den;
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        int g = gcd(n, d);
        num /= g;
        den /= g;
    }
};

vector<int> ans, tmp;

void gao(const Fraction& f) {
    if (f.num == 0) {
        ans = tmp;
    } else if (tmp.size() + 1 < ans.size()) {
        int l = (f.den + f.num + f.num - 1) / (f.num + f.num), r = f.den / f.num;
        // printf("%d/%d => [%d,%d]\n", f.num, f.den, l, r);
        for (int i = l; i <= r; ++i) {
            tmp.push_back(i);
            gao(Fraction(f.den - f.num * i, f.den));
            tmp.pop_back();
        }
    }
}

int main() {
    int re;
    int a, b;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &a, &b);
        ans.resize(6);
        tmp.clear();
        gao(Fraction(min(a, b - a), b));
        if (ans.size() <= 5) {
            for (int i = 0; i < (int)ans.size(); ++i) {
                printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
            }
        } else {
            puts("Too complex");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//623   2010-07-17 08:48:49     Accepted    1072    C++     930     180     anotherpeg  Source

// 2012-09-07 15:48:39 | Accepted | 3360 | C++ | 750 | 180 | watashi | Source
