#include <cstdio>

// c * a + b * d = gcd
int ext_gcd(int a, int b, int& c, int& d)
{
    if (b == 0) {
        c = 1;
        d = 0;
        return a;
    }
    else {
        int ret = ext_gcd(b, a % b, c, d);
        int tmp = d;
        d = c - a / b * d;
        c = tmp;
        return ret;
    }
}

// x = b0 (mod m0)
// ...
// x = bn-1 (mod mn-1)
// gcd(mi, mj) = 1
int solve(int n, const int b[], const int m[])
{
    int ret = 0, mm = 1, mi, pi, qi;

    for (int i = 0; i < n; i++) {
        mm *= m[i];
    }
    for (int i = 0; i < n; i++) {
        mi = mm / m[i];
        ext_gcd(mi, m[i], pi, qi);
        ret += mi * pi * b[i];
        ret %= mm;
    }
    if (ret < 0) {
        ret += mm;
    }

    return ret;
}

char* decode(int code, const int m[4], char* p)
{
    static int b[4];

    for (int i = 3; i >= 0; i--) {
        b[i] = code % 100;
        code /= 100;
    }
    code = solve(4, b, m);
    //printf("%d\n", code);
    for (int i = 2; i >= 0; i--) {
        *(p + i) = (code % 100 == 27) ? ' ' : ('A' + code % 100 - 1);
        code /= 100;
    }

    return p + 3;
}

int main(void)
{
    char *p;
    int re, n, code, m[4];
    static char buf[256];

    scanf("%d", &re);
    while (re--) {
        scanf("%d", &n);
        for (int i = 0; i < 4; i++) {
            scanf("%d", &m[i]);
        }
        p = buf;
        for (int i = 0; i < n; i++) {
            scanf("%d", &code);
            p = decode(code, m, p);
        }
        while (p != buf && *(p - 1) == ' ') {
            --p;
        }
        *p = '\0';
        puts(buf);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3016941 2008-08-01 17:23:01 Accepted 2945 C++ 00:00.00 436K Re:ReJudge
//

// 2012-09-07 01:49:13 | Accepted | 2945 | C++ | 0 | 180 | watashi | Source
