#include <cstdio>
#include <algorithm>
using namespace std;

int m, n, a[101], b[101];

inline int same_value(int m, int n, int a[], int b[])
{
    int ret = 0, i = 0, j = 0;

    // m > 0 && n > 0 ;else return 0!
    // all element are diff
    while(true) {
        if(a[i] < b[j]) {
            if(++i >= m) return ret;
        }
        else if(a[i] > b[j]) {
            if(++j >= n) return ret;
        }
        else {
            ++ret;
            if(++i >= m) return ret;
            if(++j >= n) return ret;
        }
    }
}

int main(void)
{
    bool flag;
    int c, i, k;

    while(scanf("%d", &m) != EOF && m > 0) {
        scanf("%d", &k);
        for (i = 0; i < m; i++)
            scanf("%d", &a[i]);
        sort(a, a + m);
        flag = true;
        while(k--) {
            scanf("%d%d", &n, &c);
            for (i = 0; i < n; i++)
                scanf("%d", &b[i]);
            if(!flag) continue;
            sort(b, b + n);
            if(same_value(m, n, a, b) < c) flag = false;
        }
        puts(flag ? "yes" : "no");
    }

    return 0;
}

/*
Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
2795765 2008-03-21 23:03:47 Accepted 2548 C++ 00:00.19 436K ¤ï¤¿¤·
*/

// 2012-09-07 01:27:52 | Accepted | 2548 | C++ | 60 | 180 | watashi | Source
