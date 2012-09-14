#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

const int LIMIT = 1 << 20;
static int id = 0;
static int tag[100], mark[LIMIT];

int gao(int n) {
    int c = 0, r = 1, p = 0, q;

    ++id;
    while (r < n) {
        r *= 10;
    }
    while (c < 100) {
        q = r / n;
        r %= n;
        if (tag[p = p * 10 + q] != id) {
            tag[p] = id;
            ++c;
        }
        p = q;
        if (mark[r] == id) {
            q = r * 10 / n;
            if (tag[p = p * 10 + q] != id) {
                tag[p] = id;
                ++c;
            }
            break;
        }
        mark[r] = id;
        r *= 10;
    }

    if (c == 99) {
        return find_if(tag, tag + 100, bind2nd(not_equal_to<int>(), id)) - tag;
    } else {
        return -1;
    }
}

int main() {
    int n, ans, cnt, tab[100];

    cnt = 0;
    fill(tab, tab + 100, -1);
    for (int i = 1; cnt < 100; ++i) {
        ans = gao(i);
        if (ans != -1 && tab[ans] == -1) {
            tab[ans] = i;
            ++cnt;
        }
    }

    while (scanf("%d", &n) != EOF) {
        printf("%d\n", tab[n]);
    }

    return 0;
}

/*
     76344, 27839,  2938,  5246,  8662, 13161,  7412,  7843,  3386,  4566,
      8596,   981,  1654,  5609,  2623, 11357,  5703, 13634,  1269,  7067,
     10146,  7748,  1017,  2006, 13987,  2737,  1007,  9269,  2191,  9633,
      5637, 17406,  4746,   327, 19798, 10219,  6902, 11815,  7869,   731,
      5972,  5473,  8849,  9822,  3222, 16274,  2751, 22414,  2183,  5974,
      7573,  5391,  6837,  8762,  7747,  1962,  5629,  9691, 10158,  1493,
      1462, 15796,  3594,  8109,  2359, 14382,   339,  6873, 19194, 10262,
      5459,  5163, 20049,  4028,  3113, 27279,  1003,  3924,  1937,  2679,
      5183,  3378,  2969, 21395, 13907,  3074,  4911,   827,  6471,  4279,
      2283,  8465,  2538,   527, 17751,  7526,  9422,  7345,  5083,   791,
*/

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//686   2011-01-30 14:12:24     Accepted    A   C++     990     4276    watashi@ArcOfDream  Source

// 2012-09-07 15:58:01 | Accepted | 3457 | C++ | 990 | 4276 | watashi | Source
