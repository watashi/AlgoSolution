#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

set<int> st[6 * 6 * 6];

inline int ToInt(int a, int b, int c)
{
    return (a - 1) * 36 + (b - 1) * 6 + c - 1;
}

inline int ToInt(int a[])
{
    int ret = 0;

    for (int i = 0; i < 6; i++)
        ret = ret * 10 + a[i];

    return ret;
}

const int I[8][3] = {
    {0, 1, 4},
    {1, 2, 4},
    {2, 3, 4},
    {3, 0, 4},
    {1, 0, 5},
    {2, 1, 5},
    {3, 2, 5},
    {0, 3, 5}
};

int s[6 * 6 * 6];

void Show(int w)
{
    static int /*b, */a[6];

    for (int i = 0; i < 6; i++) {
        a[i] = w % 10;
        w /= 10;
    }

    /*
    b = 4;
    for (int i = 0; i < 3; i++)
        if(a[i] < a[b])
            b = i;
    if(b == 4)
    */  printf("%d %d %d %d %d %d\n", a[5], a[3], a[4], a[2], a[0], a[1]);
    /*if(b == 0)
        printf("%d %d %d %d %d %d\n", a[5], a[3], a[0], a[1], a[2], a[4]);
    if(b == 2)
        printf("%d %d %d %d %d %d\n", a[5], a[3], a[2], a[4], a[1], a[0]);
    if(b == 1)
        printf("%d %d %d %d %d %d\n", a[5], a[3], a[1], a[0], a[4], a[2]);
    */
}

int main(void)
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    int n, x, y, z, w;

    do {
        w = ToInt(a);
        for (int i = 0; i < 8; i++) {
            st[ToInt(a[I[i][0]], a[I[i][1]], a[I[i][2]])].insert(w);
            st[ToInt(a[I[i][1]], a[I[i][2]], a[I[i][0]])].insert(w);
            st[ToInt(a[I[i][2]], a[I[i][0]], a[I[i][1]])].insert(w);
        }
    }while(next_permutation(a, a + 6) && a[0] == 1 && a[1] == 2);
    do {
        w = ToInt(a);
        for (int i = 0; i < 8; i++) {
            st[ToInt(a[I[i][0]], a[I[i][1]], a[I[i][2]])].insert(w);
            st[ToInt(a[I[i][1]], a[I[i][2]], a[I[i][0]])].insert(w);
            st[ToInt(a[I[i][2]], a[I[i][0]], a[I[i][1]])].insert(w);
        }
    }while(next_permutation(a, a + 6) && a[0] == 1 && a[1] == 3 && a[2] == 2);

    while(scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &x, &y, &z);
            s[i] = ToInt(x, y, z);
        }
        w = -1;
        for (set<int>::iterator it = st[s[0]].begin(); it != st[s[0]].end(); ++it) {
            bool flag = true;
            for (int i = 1; i < n; i++)
                if(st[s[i]].find(*it) == st[s[i]].end()) {
                    flag = false;
                    break;
                }
            if(flag) {
                if(w == -1)
                    w = *it;
                else {
                    w = -2;
                    break;
                }
            }
        }
        if(w == -1)
            puts("T_T");
        else if(w == -2)
            puts("=.-");
        else
            Show(w);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2840134   2008-04-12 16:08:06     Accepted    1630    C++     00:00.00    864K    Re:ReJudge

// 2012-09-07 00:56:16 | Accepted | 1630 | C++ | 0 | 184 | watashi | Source
