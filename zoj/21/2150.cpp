#include <cstdio>

int power(int x, int y, int m)
{
    if(y == 0) return 1 % m;
    int res = power(x, y >> 1, m);
    res = res * res % m;
    if(y & 1) res = res * x % m;
    return res;
}

int main(void)
{
    int z, m, h, x, y, ans;
    scanf("%d", &z);
    while(z--) {
        scanf("%d%d", &m, &h);
        ans = 0;
        while(h--) {
            scanf("%d%d", &x, &y);
            if(x != 0) ans += power(x % m, y, m);
        }
        printf("%d\n", ans % m);
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746292 2008-02-07 23:07:50 Accepted 2150 C++ 00:00.15 440K ¤ï¤¿¤·

// 2012-09-07 01:14:18 | Accepted | 2150 | C++ | 70 | 180 | watashi | Source
