#include <algorithm> // auto fix CE
#include <cstdio>
#include <algorithm> // auto fix CE
#include <cassert>
#include <algorithm> // auto fix CE
#include <cstdlib>
#include <algorithm> // auto fix CE
#include <numeric>

using namespace std;

const int O = 1024;
const int Q = 100;
const int MAXN = O * O + O * O;

bool p[MAXN];
int s[O + O + 1][O + O + 1];

void init() {
    for (int i = 2; i < MAXN; ++i) {
        p[i] = !p[i];
        if (p[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                p[j] = true;
            }
        }
    }
    for (int i = -O; i <= O; ++i) {
        for (int j = -O; j <= O; ++j) {
            if (p[i * i + j * j] ||
                (i == 0 && p[abs(j)] && (abs(j) & 3) == 3) ||
                (j == 0 && p[abs(i)] && (abs(i) & 3) == 3)) {
                s[O + i][O + j] = 1;
            }
        }
        partial_sum(s[O + i], s[O + i + 1], s[O + i]);
        if (i > -O) {
            for (int j = -O; j <= O; ++j) {
                s[O + i][O + j] += s[O + i - 1][O + j];
            }
        }
    }
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

static int counter = 0;

int main() {
    int re, x1, x2, y1, y2, n, d, g;

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d%d%d%d", &x1, &x2, &y1, &y2) == 4);
        assert(-Q <= x1 && x1 <= x2 && x2 <= Q);
        assert(-Q <= y1 && y1 <= y2 && y2 <= Q);
        --x1;
        --y1;
        n = s[O + x2][O + y2] + s[O + x1][O + y1] - s[O + x1][O + y2] - s[O + x2][O + y1];
        d = (x2 - x1) * (y2 - y1);
        g = gcd(n, d);
        printf("%d/%d\n", n / g, d / g);
        assert(d > 0);
        for (int i = x1; i < x2; ++i) {
            for (int j = y1; j < y2; ++j) {
                ++counter;
            }
        }
    }
    assert(scanf("%d", &re) == EOF);
    fprintf(stderr, "%d\n", counter);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//217   2011-04-03 01:10:35     Accepted    G   C++     330     18628   watashi     Source

// 2012-09-07 16:00:46 | Accepted | 3483 | C++ | 120 | 18628 | watashi | Source
