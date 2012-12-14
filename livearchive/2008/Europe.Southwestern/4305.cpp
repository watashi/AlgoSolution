#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXA = 6;
const int MAXB = 32;

struct Poly {
    int d;
    long long a[12];
    
    Poly(int n, int c[]) {
        d = n;
        for (int i = 0; i <= n; ++i) {
            a[i] = c[i];
        }
        while (d > 0 && a[d] == 0) {
            --d;
        }
    }
};

Poly operator*(const Poly& lhs, const Poly& rhs) {
    Poly ret(-1, NULL);
    fill(ret.a, ret.a + 12, 0LL);
    for (int i = 0; i <= lhs.d; ++i) {
        for (int j = 0; j <= rhs.d; ++j) {
            ret.a[i + j] += lhs.a[i] * rhs.a[j];
        }
    }
    ret.d = lhs.d + rhs.d;
    while (ret.d >= 0 && ret.a[ret.d] == 0) {
        --ret.d;
    }
    return ret;
}

// p % q == 0 ?
bool check(Poly p, const Poly& q) {
    if (p.d < q.d && p.d != -1) {
        return false;
    }
    for (int i = p.d; i >= q.d; --i) {
        if (p.a[i] % q.a[q.d] != 0) {
            return false;
        }
        long long c = p.a[i] / q.a[q.d];
        for (int j = 0; j <= q.d; ++j) {
            p.a[i - j] -= q.a[q.d - j] * c;
        }
    }
    for (int i = q.d - 1; i >= 0; --i) {
        if (p.a[i] != 0) {
            return false;
        }
    }
    return true;
}

vector<Poly> chk;

void init() {
    int a[3];
    for (int i = 1; i <= MAXA; ++i) {
        a[1] = i;
        for (int j = -MAXA; j <= MAXA; ++j) {
            a[0] = j;
            Poly p(1, a);
            chk.push_back(p * p);
        }
    }
    for (int i = 1; i <= MAXA; ++i) {
        a[2] = i;
        for (int j = -MAXB / i; j <= MAXB / i; ++j) {
            a[1] = j;
            for (int k = -MAXA; k <= MAXA; ++k) {
                a[0] = k;
                Poly p(2, a);
                chk.push_back(p * p);
            }
        }
    }
}

int main() {
    int re, n;
    int a[100];

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0;  i <= n; ++i) {
            scanf("%d", &a[n - i]);
        }
        Poly p(n, a);
        bool flag = false;
        for (vector<Poly>::const_iterator it = chk.begin(); it != chk.end(); ++it) {
            if (check(p, *it)) {
                flag = true;
                break;
            }
        }
        puts(flag ? "No!" : "Yes!");
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723956  	2011-01-22 17:25:04 	Accepted	0.029	Minimum	26909	C++	4305 - Wizards
/*
id => 1174118
pid => 4305
pname => Wizards
status => Accepted
lang => C++
time => 0.018
date => 2012-12-14 17:25:33
*/
