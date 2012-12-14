#include <cstdio>

const int MOD = 10001;

int extGcd(int a, int b, int& x, int& y) {
    int t, ret;
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ret = extGcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return ret;
}

int modularLinear(int a, int b, int n, int& s) {
    int d, x, y;
    d = extGcd(a, n, x, y);
    if (d == 0) {
        s = 1;
        return 1;
    } else if (b % d) {
        return 0;
    }
    s = (x * (b / d) % n + n) % n;
    return 1;
}

int main() {
    bool flag;
    int n, a, b, c;
    int x[10086];
    
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x[i]);
        }
        if (n == 1) {
            a = 1;
            b = 0;
            flag = true;
        } else {
            flag = false;
            for (a = 0; !flag && a < MOD; ++a) {
                c = (x[1] - (a * a) % MOD * x[0]) % MOD;
                if (c < 0) {
                    c += MOD;
                }
                flag = true;
                for (int i = 2; flag && i < n; ++i) {
                    if (x[i] != ((a * a) % MOD * x[i - 1] + c) % MOD) {
                        flag = false;
                    }
                }
                if (flag && modularLinear((a + 1) % MOD, c, MOD, b) == 0) {
                    flag = false;
                }
                if (flag) {
                    break;
                }
            }
        }
        if (!flag) {
            puts("@");
        }
        for (int i = 0; i < n; ++i) {
            printf("%d\n", (a * x[i] + b) % MOD);
        }
    }

    return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727339  	2011-01-29 09:32:41 	Accepted	0.002	Minimum	26909	C++	4289 - Disgruntled Judge
/*
id => 1174316
pid => 4289
pname => Disgruntled Judge
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:53:27
*/
