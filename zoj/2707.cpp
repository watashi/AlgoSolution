#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

struct BPolynomial : vector<bool> {
    bool read(FILE* fp) {
        int n;
        if (fscanf(fp, "%d", &n) == EOF) {
            return false;
        }
        resize(n + 1);
        for (BPolynomial::reverse_iterator i = rbegin(); i != rend(); ++i) {
            fscanf(fp, "%d", &n);
            *i = (n != 0);
        }
        return true;
    }

    void write(FILE* fp) const {
        fprintf(fp, "%d", (int)size() - 1);
        for (BPolynomial::const_reverse_iterator i = rbegin(); i != rend(); ++i) {
            fputs(*i ? " 1" : " 0", fp);
        }
        fputc('\n', fp);
    }

    void trim() {
        while (!(empty() || back())) {
            pop_back();
        }
    }
};

BPolynomial operator+(const BPolynomial& lhs, const BPolynomial& rhs) {
    if (lhs.size() < rhs.size()) {
        return rhs + lhs;
    }
    BPolynomial ret(lhs);
    for (int i = 0; i < (int)rhs.size(); ++i) {
        ret[i] = ret[i] ^ rhs[i];
    }
    ret.trim();
    return ret;
}

BPolynomial operator-(const BPolynomial& lhs, const BPolynomial& rhs) {
    return lhs + rhs;
}

BPolynomial operator*(const BPolynomial& lhs, const BPolynomial& rhs) {
    BPolynomial ret;
    if (lhs.size() > 0 && rhs.size() > 0) {
        ret.resize(lhs.size() + rhs.size() - 1);
        for (int i = 0; i < (int)lhs.size(); ++i) {
            if (lhs[i]) {
                for (int j = 0; j < (int)rhs.size(); ++j) {
                    ret[i + j] = ret[i + j] ^ rhs[j];
                }
            }
        }
    }
    return ret;
}

void divmod(BPolynomial& lhs, BPolynomial& rhs) {
    BPolynomial ret;
    for (int i = (int)lhs.size() - 1; i >= (int)rhs.size() - 1; --i) {
        if (lhs[i]) {
            for (int j = 0; j < (int)rhs.size(); ++j) {
                lhs[i - j] = lhs[i - j] ^ rhs[(int)rhs.size() - 1 - j];
            }
            ret.push_back(true);
        } else {
            ret.push_back(false);
        }
    }
    reverse(ret.begin(), ret.end());
    lhs.trim();
    lhs.swap(ret);
    rhs.swap(ret);
}

BPolynomial extGcd(BPolynomial a, BPolynomial b, BPolynomial& x, BPolynomial& y) {
    BPolynomial g;
    if (b.size() == 0) {
        g = a;
        x.resize(1);
        x[0] = true;
        y.clear();
    } else {
        g = b;
        divmod(a, b);
        g = extGcd(g, b, y, x);
        y = y - a * x;
    }
    return g;
}

BPolynomial a[2][3], d, t, x, y;

int main() {
    bool flag;

    while (true) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!a[i][j].read(stdin)) {
                    return 0;
                }
            }
        }

        flag = false;
        d = a[0][0] * a[1][1] - a[1][0] * a[0][1];
        x = a[0][2] * a[1][1] - a[1][2] * a[0][1];
        y = a[0][0] * a[1][2] - a[1][0] * a[0][2];
        if (!d.empty()) {
            t = d;
            divmod(x, t);
            divmod(y, d);
            if (!(t.empty() && d.empty())) {
                flag = true;
            }
        } else if (!(x.empty() && y.empty())) {
            flag = true;
        } else if (a[0][2].empty() && a[1][2].empty()) {
            x.clear();
            y.clear();
        } else {
            for (int i = 0; i < 2; ++i) {
                if (a[i][0].empty() && a[i][1].empty()) {
                    if (a[i][2].empty()) {
                        continue;
                    } else {
                        flag = true;
                    }
                } else {
                    d = extGcd(a[i][0], a[i][1], x, y);
                    t = a[i][2];
                    divmod(t, d);
                    if (d.empty()) {
                        x = x * t;
                        y = y * t;
                    } else {
                        flag = true;
                    }
                }
                break;
            }
        }

        if (flag) {
            puts("No solution");
        } else {
            assert((a[0][0] * x + a[0][1] * y - a[0][2]).empty());
            assert((a[1][0] * x + a[1][1] * y - a[1][2]).empty());
            x.write(stdout);
            y.write(stdout);
        }
        puts("");
    }
}

// SF WA*3
/*
Run ID      Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
2114473     2010-03-17 12:52:48     Accepted    2707    C++     0   176     watashi@Zodiac
*/

// 2012-09-07 15:44:53 | Accepted | 2707 | C++ | 0 | 180 | watashi | Source
