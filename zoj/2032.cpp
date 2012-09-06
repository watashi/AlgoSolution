#include <cstdio>
#include <algorithm>
using namespace std;

class BigInteger
{
private:
    static const int LEN = 16;
    static const int MOD = 10000;
    int a[LEN];
public:
    BigInteger(int x = 0)
    {
        for (int i = 0; i < LEN; i++)
            a[i] = 0;
        a[0] = x;
    }
    bool zero() const
    {
        for (int i = 0; i < LEN; i++)
            if(a[i] != 0)
                return false;
        return true;
    }
    void mul(int x)
    {
        for (int i = 0; i < LEN; i++) {
            a[i] *= x;
            if(i > 0 && a[i - 1] >= MOD) {
                a[i] += a[i - 1] / MOD;
                a[i - 1] %= MOD;
            }
        }
    }
    void add(const BigInteger& b)
    {
        for (int i = 0; i < LEN; i++) {
            a[i] += b.a[i];
            if(a[i] >= MOD) {
                ++a[i + 1];
                a[i] -= MOD;
            }
        }
    }
    void sub(const BigInteger& b)
    {
        for (int i = 0; i < LEN; i++) {
            a[i] -= b.a[i];
            if(a[i] < 0) {
                --a[i + 1];
                a[i] += MOD;
            }
        }
    }
    void out() const
    {
        int p = LEN - 1;

        while(p > 0 && a[p] == 0)
            --p;
        printf("%d", a[p--]);
        while(p >= 0)
            printf("%04d", a[p--]);
        printf("\n");
    }
};

int m, n, p[3][12][2];

void gao(void)
{
    BigInteger a = 1;

    for (int i = 0; i < m; i++)
        a.mul(p[0][i][1] - p[0][i][0]);
    printf("1 ");
    a.out();
}

void zaigao(void)
{
    BigInteger a1 = 1, a2 = 1, b = 1;

    for (int i = 0; i < m; i++) {
        a1.mul(p[0][i][1] - p[0][i][0]);
        a2.mul(p[1][i][1] - p[1][i][0]);
        b.mul(max(0, min(p[0][i][1], p[1][i][1]) - max(p[0][i][0], p[1][i][0])));
    }
    a1.add(a2);
    a1.sub(b);
    a1.sub(b);
    if(!a1.zero()) {
        printf("1 ");
        a1.out();
    }
    if(!b.zero()) {
        printf("2 ");
        b.out();
    }
}

void jiezhegao(void)
{
    BigInteger a0(1), a1(1), a2(1), b01(1), b02(1), b12(1), c(1);

    for (int i = 0; i < m; i++) {
        a0.mul(p[0][i][1] - p[0][i][0]);
        a1.mul(p[1][i][1] - p[1][i][0]);
        a2.mul(p[2][i][1] - p[2][i][0]);
        b01.mul(max(0, min(p[0][i][1], p[1][i][1]) - max(p[0][i][0], p[1][i][0])));
        b02.mul(max(0, min(p[0][i][1], p[2][i][1]) - max(p[0][i][0], p[2][i][0])));
        b12.mul(max(0, min(p[1][i][1], p[2][i][1]) - max(p[1][i][0], p[2][i][0])));
        c.mul(max(0, min(p[0][i][1], min(p[1][i][1], p[2][i][1])) - max(p[0][i][0], max(p[1][i][0], p[2][i][0]))));
    }
    a0.add(a1);a0.add(a2);a0.add(c);a0.add(c);a0.add(c);
    a0.sub(b01);a0.sub(b01);a0.sub(b02);a0.sub(b02);a0.sub(b12);a0.sub(b12);
    if(!a0.zero()) {
        printf("1 ");
        a0.out();
    }
    b01.add(b02);
    b01.add(b12);
    b01.sub(c);b01.sub(c);b01.sub(c);
    if(!b01.zero()) {
        printf("2 ");
        b01.out();
    }
    if(!c.zero()) {
        printf("3 ");
        c.out();
    }
}

// 这个代码难看到一定境界了 -_-b

int main(void)
{
    while(scanf("%d%d", &m, &n) != EOF && m > 0 && n > 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d%d", &p[i][j][0], &p[i][j][1]);
        switch(n) {
            case 1: gao(); break;
            case 2: zaigao(); break;
            case 3: jiezhegao(); break;
        }
    }
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2947931   2008-06-11 23:24:23     Accepted    2032    C++     00:00.00    392K    Re:ReJudge

// 2012-09-07 01:11:03 | Accepted | 2032 | C++ | 0 | 180 | watashi | Source
