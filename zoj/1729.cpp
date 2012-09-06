#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int minString(char str[], const int len)
{
    int i, j, k;

    strncpy(str + len, str, len);
    i = 0;
    j = 1;
    do {
        k = 0;
        while(k < len && str[i + k] == str[j + k])
            k++;
        if(k == len)
            break;
        else if(str[i + k] > str[j + k])
            i += k + 1;
        else
            j += k + 1;
        if(i == j)
            ++j;
     }while(i < len && j < len);

    return min(i, j);
}

char str[200002];

int main(void)
{
    int re, len;

    scanf("%d", &re);
    while(re--) {
        scanf("%d ", &len);
        gets(str);
        printf("%d\n", minString(str, len));
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2840978   2008-04-12 23:22:09     Accepted    1729    C++     00:00.00    588K    Re:ReJudge

/*
Rank    Submit time     Run time    Run memory      Language    User
1   2006-10-05 00:32:38     00:00.00    384K    C++     the sixth mj
2   2007-05-02 14:21:21     00:00.00    384K    C++     霜之哀伤
3   2006-05-21 04:25:01     00:00.00    588K    C++     SHOIT
4   2006-11-27 19:50:24     00:00.00    588K    C++     Fall
5   2008-04-12 23:22:09     00:00.00    588K    C++     Re:ReJudge
6   2006-07-20 22:06:53     00:00.00    592K    C++     WAC
7   2005-09-19 05:40:47     00:00.00    1024K   C++     阿九
8   2006-07-19 22:50:43     00:00.00    1236K   C++     horse
9   2008-02-09 21:13:46     00:00.01    588K    C   loulou
10  2007-04-01 12:14:36     00:00.01    592K    C++     9911
11  2008-01-07 11:10:53     00:00.01    680K    C++     koy
12  2008-01-07 11:08:48     00:00.01    688K    C++     Dream
13  2006-11-02 11:28:33     00:00.01    1032K   C++     Fire
14  2006-12-07 09:43:30     00:00.01    1124K   C++     cepheid
15  2007-04-04 19:31:23     00:00.02    488K    C++     chenxizju
*/

// 2012-09-07 00:59:00 | Accepted | 1729 | C++ | 0 | 376 | watashi | Source
