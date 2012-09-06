/* //ø…“‘”√struct Real{double a; long long e;}; */
#include <stdio.h>
#include <math.h>
typedef struct{
    double a;
    int e;
}Real;
Real One = {1.0, 0};

void format(Real *it)
{
    if(it->a >= 1e10) {
        it->a /= 1e10;
        it->e += 10;
    }
    else if(it->a <= 1e-10) {
        it->a *= 1e10;
        it->e -= 10;
    }
}

double todouble(Real it)
{
    return it.a * pow(10.0, it.e);
}

char mk[10001];

int main()
{
    int i, j, p, q, r, s;
    Real ans;

    while(scanf("%d%d%d%d", &p, &q, &r, &s) != EOF) {
        for (i = 1; i <= 10000; i++)
            mk[i] = 0;
        if (p >= r) {
            for (i = r + 1; i <= p; i++)
                mk[i]++;
        } else {
            for (i = p + 1; i <= r; i++)
                mk[i]--;
        }
        if (q >= s) {
            for (i = s + 1; i <= q; i++)
                mk[i]--;
        } else {
            for (i = q + 1; i <= s; i++)
                mk[i]++;
        }
        q = p - q;
        s = r - s;
        if (q >= s) {
            for (i = s + 1; i <= q; i++)
                mk[i]--;
        } else {
            for (i = q + 1; i <= s; i++)
                mk[i]++;
        }
        /*
        ans = 1;
        for (i = 1; i <= 10000; i++) {
            if (mk[i] > 0) {
                for (j = 0; j < mk[i]; j++)
                    ans *= i;
            } else if (mk[i] < 0) {
                for (j = 0; j > mk[i]; j--)
                    ans /= i;
            }
        }
        //WA
        */
        ans = One;
        for (i = 1; i <= 10000; i++) {
            if (mk[i] > 0) {
                for (j = 0; j < mk[i]; j++)
                    ans.a *= i;
            } else if (mk[i] < 0) {
                for (j = 0; j > mk[i]; j--)
                    ans.a /= i;
            }
            format(&ans);
        }
        printf("%.5lf\n", todouble(ans));
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2712569 2007-12-25 13:34:02 Accepted 1863 C 00:00.03 416K §Ô§ø§∑ */

// 2012-09-07 03:05:56 | Accepted | 1863 | C | 10 | 168 | watashi | Source
