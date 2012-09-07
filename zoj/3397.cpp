#include <cstdio>
#include <algorithm>

using namespace std;

struct S {
    int f, t;
    double gpa;
} s[80];

bool operator<(const S& lhs, const S& rhs) {
    return lhs.gpa < rhs.gpa;
}

int s2i(const char *p) {
    if (*p == 'M') {
        return 1;
    } else if (*(p + 1) == 'h') {
        return 0;   // Chinese
    } else {
        return 2;
    }
}

// long long hanoi[80];
long long jmp[80];

void init() {
    // hanoi[0] = 0;
    jmp[0] = 0;
    for (int i = 1; i < 80; ++i) {
        // hanoi[i] = hanoi[i - 1] + hanoi[i - 1] + 1;
        jmp[i] = 3 * jmp[i - 1] + 1;
        // printf("%d: %lld %lld\n", i, jmp[i], jmp[i] * 2);
    }
}

#define RETURN(retval) return (retval)
/*
#define RETURN(retval) \
    fprintf(stderr, "retrun %lld @ (%d, %d, %d)\n", retval, k, f, t);\
    return retval;
*/
long long gao(int k, int f, int t) {
    if (k == -1) {
        RETURN(0LL);
    }

    if (f != -1 && t != -1) {
    //  RETURN(f == 0 || t == 0 ? jmp[k] : 2 * jmp[k]); // WHAT A PITYYYYYYYYYYYYYY!!!!!!!!!
        RETURN(f == 0 || t == 0 ? jmp[k + 1] : 2 * jmp[k + 1]);
    }

    int ff = (f == -1 ? s[k].f : f);
    int tt = (t == -1 ? s[k].t : t);
    // printf("=> %d %d %d [%d %d]\n", k, f, t, ff, tt);

    if (ff == tt) {
        RETURN(gao(k - 1, f, t));
    }

    if (ff != 0 && tt != 0) {
        RETURN(gao(k - 1, f, tt) + 1 + gao(k - 1, tt, ff) + 1 + gao(k - 1, ff, t));
    } else {
        RETURN(gao(k - 1, f, 3 - ff - tt) + 1 + gao(k - 1, 3 - ff - tt, t));
    }
}

int main() {
    int n;
    char sa[80], sb[80];

    init();
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s%s%lf", sa, sb, &s[i].gpa);
            s[i].f = s2i(sa);
            s[i].t = s2i(sb);
        }
        sort(s, s + n);
        reverse(s, s + n);
        printf("%lld\n", gao(n - 1, -1, -1));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//276   2010-08-30 17:43:16     Accepted    B   C++     0   180     watashi@Zodiac  Source

// 2012-09-07 15:51:34 | Accepted | 3397 | C++ | 0 | 180 | watashi | Source
