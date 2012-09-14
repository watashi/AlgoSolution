// GCJ R1B ^^

#include <cmath>
#include <cstdio>
//#include <cassert>

int a[1000001];

struct PrimeList
{
    static const size_t maxn = 48400, sqrtmaxn = 220;
    unsigned int pn, *pl;
    PrimeList()
    {
        pl = new unsigned int[5000];
        for (size_t i = 1; i <= maxn; i++) {
            a[i] = (i & 1);
        }
        pn = 0;
        pl[pn++] = 2;
        for (size_t i = 3; i <= sqrtmaxn; i++) {
            if (a[i]) {
                pl[pn++] = i;
                for (size_t j = i + i; j <= maxn; j += i) {
                    a[j] = 0;
                }
            }
        }
        for (size_t i = sqrtmaxn + 1; i <= maxn; i++) {
            if (a[i]) {
                pl[pn++] = i;
            }
        }
        //assert(pn <= 5000);
    }
    ~PrimeList()
    {
        delete[] pl;
    }
    size_t size() const
    {
        return pn;
    }
    unsigned int operator[](size_t i) const
    {
        return pl[i];
    }
};

PrimeList p;

int main(void)
{
    unsigned int l, u, c/*, s*/;
    size_t pre, mind, maxd, minl, maxl, minr, maxr;

    while (scanf("%u%u", &l, &u) != EOF) {
        if (l == 1) {
            ++l;
        }   // 1 is not prime   WA 555
        c = u - l;
        //s = (unsigned int)sqrt(u);
        for (size_t i = 0; i <= c; i++) {
            a[i] = 1;
        }
        for (size_t i = 0; i < p.size()/* && p[i] <= s*/; i++) {
            for (unsigned int j = (l <= p[i]) ? (2 * p[i]) : (l + p[i] - 1) / p[i] * p[i]; j <= u; j += p[i]) {
                a[j - l] = 0;
            }
        }
        pre = 0xFFFFFFFFU;
        mind = u - l + 1;
        maxd = 0;
        for (size_t i = 0; i <= c; i++) {
            if (a[i]) {
                if (pre != 0xFFFFFFFFU) {
                    if (i - pre > maxd) {
                        maxd = i - pre;
                        maxl = pre;
                        maxr = i;
                    }
                    if (i - pre < mind) {
                        mind = i - pre;
                        minl = pre;
                        minr = i;
                    }
                }
                pre = i;
            }
        }
        if (mind == u - l + 1 || maxd == 0) {
            puts("There are no adjacent primes.");
        }
        else {
            printf("%u,%u are closest, %u,%u are most distant.\n", l + minl, l + minr, l + maxl, l + maxr);
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3024615 2008-08-06 15:23:18 Accepted 1842 C++ 00:00.22 4364K Re:ReJudge
//

// 2012-09-07 01:02:34 | Accepted | 1842 | C++ | 70 | 4084 | watashi | Source
