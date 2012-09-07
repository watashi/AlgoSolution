#include <cstdio>
#include <algorithm>

using namespace std;

int ones[65536];

int mask;

int bst;

// 012
// 1
// 2

// .*.
// ***
// .*.
int gao1(int n, int x[]) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if ((ret += ones[x[i]]) > bst) {
            return ret;
        }
        x[i + 1] ^= ((x[i] >> 1) ^ x[i] ^ (x[i] << 1)) & mask;
        x[i + 2] ^= x[i];
    }
    return x[n] == 0 ? ret : bst + 1;
}

// rot + rev
// .*.
// **.
// ***
int gao2(int n, int x[]) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if ((ret += ones[x[i]]) > bst) {
            return ret;
        }
        x[i + 1] ^= (x[i] >> 1) ^ x[i];
        x[i + 2] ^= ((x[i] >> 1) ^ x[i] ^ (x[i] << 1)) & mask;
    }
    return x[n] == 0 ? ret : bst + 1;
}

// rot
// .*.
// ***
// **.
int gao3(int n, int x[]) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if ((ret += ones[x[i]]) > bst) {
            return ret;
        }
        x[i + 1] ^= ((x[i] >> 1) ^ x[i] ^ (x[i] << 1)) & mask;
        x[i + 2] ^= (x[i] >> 1) ^ x[i];
    }
    return x[n] == 0 ? ret : bst + 1;
}

// rot
// .*.
// ***
// *.*
int gao4(int n, int x[]) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if ((ret += ones[x[i]]) > bst) {
            return ret;
        }
        x[i + 1] ^= ((x[i] >> 1) ^ x[i] ^ (x[i] << 1)) & mask;
        x[i + 2] ^= ((x[i] >> 1) ^ (x[i] << 1)) & mask;
    }
    return x[n] == 0 ? ret : bst + 1;
}

void init() {
    ones[0] = 0;
    for (int i = 1; i < (int)(sizeof(ones) / sizeof(int)); ++i) {
        ones[i] = ones[i >> 1] + (i & 1);
    }
}

int main() {
    int n, m;
    char buf[20];
    int a[20], b[20], c[20], idx, tmp;

    init();
    while (scanf("%d%d", &n, &m) != EOF && n > 0) {
        fill(a, a + n, 0);
        fill(b, b + m, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf);
            for (int j = 0; j < m; ++j) {
                if (buf[j] == '1') {
                    a[i] |= 1 << j;
                    b[j] |= 1 << i;
                }
            }
        }
        /*
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        puts("<- a");
        for (int i = 0; i < m; ++i) {
            printf("%d ", b[i]);
        }
        puts("<- b");
        */
        bst = n * m + 1;
        idx = 5;

        mask = (1 << m) - 1;
        for (int i = 0; i < (1 << m); ++i) {
            c[0] = i;
            copy(a, a + n, c + 1);
            tmp = gao1(n, c);
            if (bst > tmp || (bst == tmp && idx > 1)) {
                // printf("%d %d %d %d\n", 1, i, tmp, bst);
                bst = tmp;
                idx = 1;
            }
        }

        mask = (1 << n) - 1;
        for (int i = 0; i < (1 << n); ++i) {
            c[0] = i;
            copy(b, b + m, c + 1);
            tmp = gao3(m, c);
            if (bst > tmp || (bst == tmp && idx > 3)) {
                // printf("%d %d %d %d\n", 3, i, tmp, bst);
                bst = tmp;
                idx = 3;
            }
        }

        for (int i = 0; i < (1 << n); ++i) {
            c[0] = i;
            copy(b, b + m, c + 1);
            tmp = gao4(m, c);
            if (bst > tmp || (bst == tmp && idx > 4)) {
                // printf("%d %d %d %d\n", 4, i, tmp, bst);
                bst = tmp;
                idx = 4;
            }
        }

        reverse(b, b + m);
        for (int i = 0; i < (1 << n); ++i) {
            c[0] = i;
            copy(b, b + m, c + 1);
            tmp = gao2(m, c);
            if (bst > tmp || (bst == tmp && idx > 2)) {
                // printf("%d %d %d %d\n", 2, i, tmp, bst);
                bst = tmp;
                idx = 2;
            }
        }

        if (bst < n * m + 1) {  // T_______________________________________T
            printf("%d %d\n", idx, bst);
        } else {
            //    Impossible
            puts("Impossible");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//619   2010-07-17 00:45:09     Accepted    1078    C++     1620    436     anotherpeg  Source

// 2012-09-07 15:47:56 | Accepted | 3353 | C++ | 1290 | 436 | watashi | Source
