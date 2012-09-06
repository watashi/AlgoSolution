#include <set>
#include <cstdio>

using namespace std;

// 0: 1:get 2:sold&get 3:sell&get
const int pig[] = {
    0, -100, -200, -400
};
const int sheep[] = {
    0, +100, -200, -400
};
const int change[] = {
    1, 2, 4, 8
};
const int heartA[] = {
    0, -50, -100, -200
};
const int heart[12] = {
    -40, -30, -20, -10, -10, -10, -10, -10, -10, 0, 0, 0
};

int bts[1 << 12];
int pts[1 << 12];

set<int> st[17];

int main()
{
    // only change
    st[1].insert(50);
    st[1].insert(100);

    // ...
    // there is a "impossible 0(only change)", but it doesn't matter
    bts[0] = pts[0] = 0;
    for (int i = 0; i < 12; i++) {
        pts[1 << i] = heart[i];
    }
    for (int i = 0; i < (1 << 12) - 1; i++) {
        bts[i] = bts[i >> 1] + (i & 1);
        pts[i] = pts[i - (i & -i)] + pts[i & -i];
        for (int p = 0; p < 4; p++) {
            for (int s = 0; s < 4; s++) {
                for (int c = 0; c < 4; c++) {
                    for (int h = 0; h < 4; h++) {
                        st[bts[i] + (p > 0) + (s > 0) + (c > 0) + (h > 0)].insert(
                                change[c] * (pts[i] + pig[p] + sheep[s] + heartA[h])
                                );
                    }
                }
            }
        }
    }

    // full_red
    static const int full_red[2] = {200, 400};
    for (int p = 0; p < 4; p++) {
        for (int s = 0; s < 4; s++) {
            for (int c = 0; c < 4; c++) {
                int t = 13 + (p > 0) + (s > 0) + (c > 0);
                st[t].insert(change[c] * (full_red[0] + pig[p] + sheep[s]));
                st[t].insert(change[c] * (full_red[1] + pig[p] + sheep[s]));
            }
        }
    }

    // full_all
    st[16].clear(); // ^^
    st[16].insert(800);

    int re, n, p;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%d%d", &n, &p);
        puts(st[n].count(p) > 0 ? "yes" : "no");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1644794   2008-09-15 15:51:04     Accepted    3044    C++     140     292     watashi

// 2012-09-07 01:58:03 | Accepted | 3044 | C++ | 110 | 212 | watashi | Source
