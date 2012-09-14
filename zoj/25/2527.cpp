// O(1000*1000*log(1000))

#include <cstdio>
#include <algorithm>
using namespace std;

int a[1001];
bool m[1001][1001];

int main(void)
{
    int n, tmp, ans;
    int i, j, l, r, d, *p;

    while(scanf("%d", &n) != EOF) {
        ans = 0;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        i = j = 0;
        while(j < n) {
            a[i++] = a[tmp = j];
            while(++j < n && a[j] == a[tmp]);
            tmp = j - tmp;
            if(tmp > ans) ans = tmp;
        }
        n = i;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                m[i][j] = false;
        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++) {
                if(m[i][j]) continue;
                m[i][j] = true;
                d = a[j] - a[i];
                /*
                if  (!binary_search(a + j, a + n, a[i] + ans * d))
                    continue;
                */
                if(a[i] + ans * d > a[n - 1])
                    continue;
                tmp = 2;
                r = j;
                while ((p = lower_bound(a + r, a + n, a[r] + d)) != a + n && *p == a[r] + d) {
                    l = r;
                    r = p - a;
                    m[l][r] = true;
                    ++tmp;
                }
                if(tmp > ans) ans = tmp;
            }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795050 2008-03-21 16:42:28 Accepted 2527 C++ 00:00.07 1420K わたし

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795064 2008-03-21 16:47:34 Accepted 2527 C++ 00:00.08 1420K わたし

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795069 2008-03-21 16:48:39 Accepted 2527 C++ 00:00.04 1424K わたし

/*
Rank Submit time Run time Run memory Language User
1 2006-01-27 23:21:26 00:00.02 508K C++ Ronin
2 2006-05-02 14:18:58 00:00.03 436K C++ cryboy
3 2005-10-13 17:36:49 00:00.03 452K C++ Dreaming
4 2005-09-26 22:19:14 00:00.03 1824K C++ Jung Ju-young@ICU
5 2005-10-14 10:47:34 00:00.04 444K C++ zhousc
6 2006-05-11 12:45:39 00:00.04 528K C++ nbu_test
7 2008-03-21 16:48:39 00:00.04 1424K C++ わたし
8 2005-09-28 00:08:00 00:00.04 4344K C++ lord
9 2006-04-29 09:59:35 00:00.04 4352K C++ fengyao
10 2006-05-02 14:15:44 00:00.05 444K C++ cap
*/

// 2012-09-07 01:26:51 | Accepted | 2527 | C++ | 10 | 1164 | watashi | Source
