/*******************************************/
// CONCRETE MATHEMATICS
// 4.5 Relative Primality
// Stern-Brocot tree  and  Farey series
/*******************************************/

// there are "dead-do" method, too

// 1.
// M(SL) = M(s)MatL{{1, 1},{0, 1}}
// M(SR) = M(S)MatR{{1, 0},{1, 1}}

// 2.
// m / n = f(RS) <=> m - n / n = f(S) when m > n
// m / n = f(LS) <=> m / n - m = f(S) when m < n

#include <cstdio>
typedef long long ll;
int main(void)
{
    int re;
    scanf("%d", &re);
    while(re--) {
        int num, den;
        scanf("%d/%d", &num, &den);
        int lim;
        scanf("%d", &lim);
        int ln = 0, ld = 1, rn = 1, rd = 0, n = num, d = den;
        while(1) {
            if(n == d) {
                printf("%d/%d\n", ln + rn, ld + rd);
                break;
            }
            else if(n > d) {
                n -= d;
                ln += rn;
                ld += rd;
            }
            else {
                d -= n;
                rn += ln;
                rd += ld;
            }
            if(ld + rd > lim) {
                long long flag = 2ll * ((ll)ld * (ll)rd) * (ll)num - ((ll)ln * (ll)rd + (ll)rn * (ll)ld) * (ll)den;
                if(flag == 0) {
                    if(ld <= rd) printf("%d/%d\n", ln, ld);
                    else printf("%d/%d\n", rn, rd);
                }
                else if(flag < 0) printf("%d/%d\n", ln, ld);
                else printf("%d/%d\n", rn, rd);
                break;
            }
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2741938 2008-02-02 16:32:42 Accepted 2506 C++ 00:00.24 396K わたし

/*
Rank Submit time Run time Run memory Language User
1 2007-11-07 02:34:41 00:00.08 2740K C++ Prinse
2 2008-02-02 16:32:42 00:00.24 396K C++ わたし
3 2007-12-27 19:00:26 00:00.29 392K C++ kfc
4 2006-06-07 13:00:09 00:00.31 840K C++ cqf
5 2006-06-04 19:35:42 00:00.34 392K C++ Output Limit Exceeded
6 2006-05-22 23:24:50 00:00.34 396K C++ 心心
7 2005-09-29 09:48:39 00:00.35 440K C++ Achilles
8 2006-11-12 18:16:22 00:00.38 392K C++ tle
9 2006-11-12 18:16:44 00:00.39 392K C++ SHOIT
10 2007-02-08 17:15:08 00:00.39 392K C++ 龙龙
11 2007-02-08 17:11:58 00:00.40 392K C++ 这个GMT+8准了...
12 2006-11-18 00:09:04 00:00.41 840K C++ zhangliao
13 2006-10-20 10:33:34 00:00.42 396K C++ henry_four
14 2007-09-10 19:02:57 00:00.42 832K C++ 海蓝星
15 2005-09-17 00:42:31 00:00.43 392K C++ Huang WenHao
16 2006-10-17 19:49:13 00:00.44 396K C++ Savior
17 2005-11-16 17:30:58 00:00.45 836K C++ wizardblue
18 2006-01-17 11:26:38 00:00.46 836K C++ anyone
19 2007-07-15 23:36:15 00:00.47 2984K C++ nahnhnahk
20 2007-02-05 19:20:36 00:00.48 396K C++ pencil
*/

#ifndef NONCOMP
#define NONCOMP
#endif
#ifndef NONCOMP
#include <cstdio>

typedef long long ll;

char buf[108];

void getfrac(int& num, int& den)
{
    gets(buf);
    char *p = buf;
    num = 0;
    while(*p != '/') {
        num *= 10;
        num += *p++ - '0';
    }
    den = 0;
    while(*++p) {
        den *= 10;
        den += *p - '0';
    }
}

void getlim(int& lim)
{
    gets(buf);
    char *p = buf;
    lim = 0;
    while(*p) {
        lim *= 10;
        lim += *p++ - '0';
    }
}

int main(void)
{
    int re;
    scanf("%d ", &re);
    while(re--) {
        int num, den;
        getfrac(num, den);
        int lim;
        getlim(lim);
        int ln = 0, ld = 1, rn = 1, rd = 0, n = num, d = den;
        while(1) {
            if(n == d) {
                printf("%d/%d\n", ln + rn, ld + rd);
                break;
            }
            else if(n > d) {
                n -= d;
                ln += rn;
                ld += rd;
            }
            else {
                d -= n;
                rn += ln;
                rd += ld;
            }
            if(ld + rd > lim) {
                long long flag = 2ll * ((ll)ld * (ll)rd) * (ll)num - ((ll)ln * (ll)rd + (ll)rn * (ll)ld) * (ll)den;
                if(flag == 0) {
                    if(ld <= rd) printf("%d/%d\n", ln, ld);
                    else printf("%d/%d\n", rn, rd);
                }
                else if(flag < 0) printf("%d/%d\n", ln, ld);
                else printf("%d/%d\n", rn, rd);
                break;
            }
        }
    }
    return 0;
}
#endif

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2741947 2008-02-02 16:41:14 Accepted 2506 C++ 00:00.15 388K わたし


// Others' Code
// "dead-do" is not so easy, the other way around, it's very hard

// 2012-09-07 01:25:31 | Accepted | 2506 | C++ | 80 | 180 | watashi | Source
