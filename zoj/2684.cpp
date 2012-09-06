#include <cstdio>
#include <algorithm>

using namespace std;

enum CHILD
{
    LEFT,
    RIGHT
};

int main(void)
{
    int re, sp, n, l, x, y;
    static int d[1024], u[1024];
    static CHILD s[2048];

    scanf("%d", &re);
    while (re--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            s[i] = LEFT;
        }
        sp = n;
        d[0] = sp;
        for (int i = 1; i < n; i++) {
            scanf("%d", &l);
            while (s[sp] == RIGHT) {
                --sp;
                --l;
            }
            u[i - 1] = sp - 1;
            s[sp] = RIGHT;
            l -= 2;
            while (l > 0) {
                s[++sp] = LEFT;
                --l;
            }
            d[i] = sp;
//          printf("%d\n", sp);
        }
        scanf("%d%d", &x, &y);
        --x;
        --y;
        l = *min_element(u + x, u + y);
        printf("%d\n", d[x] - l + d[y] - l);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3018940 2008-08-02 22:57:24 Accepted 2684 C++ 00:00.00 452K Re:ReJudge
//

// 2012-09-07 01:34:52 | Accepted | 2684 | C++ | 0 | 196 | watashi | Source
