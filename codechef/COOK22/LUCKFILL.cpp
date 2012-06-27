#include <set>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 128;

char buf[MAXN];

int n, m, ans;

int size;

struct Node {
    int l, r, c;
    long long mask;
    void init() {
        l = r = -1;
        c = 1;
        mask = 0;
    }
} v[MAXN];

void gao(int p) {
    // printf("do %d %d\n", p, size);
    if (p == n) {
        ++ans;
        return;
    }

    int leaf = 0;
    for (int i = 0; i < size; ++i) {
        if (v[i].l == -1 && v[i].r == -1) {
            // if (((v[i].mask >> p) & 1) == 0) {
            //    throw 1;
            // }
            ++leaf;
        }
    }
    int mm = m - leaf * (n - p - 1);
    if (size > mm) {
        return;
    }

    int back = size;

    if (buf[p] == '4' || buf[p] == '?') {
        for (int i = 0; i < back; ++i) {
            if (((v[i].mask >> p) & 1) == 0) {
                continue;
            }
            if (v[i].r != -1) {
                ++v[v[i].r].c;
            } else {
                v[size].init();
                v[i].r = size++;
            }
            v[v[i].r].mask |= 1LL << (p + 1);
        }
        if (size <= mm) {
            gao(p + 1);
        }
        for (int i = 0; i < back; ++i) {
            if (((v[i].mask >> p) & 1) == 0) {
                continue;
            }
            v[v[i].r].mask &= ~(1LL << (p + 1));
            if (--v[v[i].r].c == 0) {
                v[i].r = -1;
            }
        }
        size = back;
    }
    // printf("%llx %d %d\n", v[0].mask, back, size);
    if (buf[p] == '7' || buf[p] == '?') {
        for (int i = 0; i < back; ++i) {
            if (((v[i].mask >> p) & 1) == 0) {
                continue;
            }
            if (v[i].l != -1) {
                ++v[v[i].l].c;
            } else {
                v[size].init();
                v[i].l = size++;
            }
            v[v[i].l].mask |= 1LL << (p + 1);
        }
        if (size <= mm) {
            gao(p + 1);
        }
        for (int i = 0; i < back; ++i) {
            if (((v[i].mask >> p) & 1) == 0) {
                continue;
            }
            v[v[i].l].mask &= ~(1LL << (p + 1));
            if (--v[v[i].l].c == 0) {
                v[i].l = -1;
            }
        }
        size = back;
    }
}

int main() {
    int re;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d%s", &n, &m, buf);
        ++m;
        ans = 0;
        v[0].init();
        v[0].mask = ~(0LL);
        size = 1;
        gao(0);
        printf("%d\n", ans);
    }

    return 0;
}

