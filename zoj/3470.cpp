#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 90000;

int a[MAXN];

int pos2id(int x, int y) {
    int i, j, k;
    if (y <= 0 && abs(x) <= -y) {
        i = -y;
        j = 0;
        k = x - y;
    } else if (x > 0 && abs(y) < x) {
        i = x - 1;
        j = 1;
        k = x + y - 1;
    } else if (y > 0 && (-y < x && x <= y)) {
        i = y - 1;
        j = 2;
        k = y - x;
    } else if (x < 0 && (x < y && y <= -x)) {
        i = -x - 1;
        j = 3;
        k = -x - y;
    }
    return a[i * 4 + j] + k;
}

void id2pos(int p, int& x, int& y) {
    int q = upper_bound(a, a + MAXN, p) - a - 1;
    int i = q / 4, j = q % 4, k = p - a[q];
    switch(j) {
        case 0:
            x = -i + k;
            y = -i;
            break;
        case 1:
            x = i + 1;
            y = -i + k;
            break;
        case 2:
            x = i + 1 - k;
            y = i + 1;
            break;
        case 3:
            x = -i - 1;
            y = i + 1 - k;
            break;
    }
}

void init() {
    a[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        a[i] = a[i - 1] + (i + 1) / 2;
    }
}

int main() {
    int re, n, x, y;
    int ans[4];

    init();
    scanf("%d", &re);
    while (re--) {
        scanf("%d", &n);
        --n;
        id2pos(n, x, y);
        ans[0] = pos2id(x - 1, y) + 1;
        ans[1] = pos2id(x + 1, y) + 1;
        ans[2] = pos2id(x, y - 1) + 1;
        ans[3] = pos2id(x, y + 1) + 1;
        sort(ans, ans + 4);
        printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//700   2011-02-08 17:36:08     Accepted    D   C++     0   532     watashi@ArcOfDream  Source

// 2012-09-07 16:50:39 | Accepted | 3470 | C++ | 10 | 532 | watashi | Source
