#include <cstdio>
#include <cstring>

char buf[108];

int main(void)
{
    int ri, re;
    int m;

    scanf("%d", &re);
    for (ri = 1; ri <= re; ri++) {
        printf("%d ", ri);
        scanf("%d%s", &m, buf + 1);
        for (int i = 1; buf[i] != '\0'; ++i) {
            if(i != m) {
                putchar(buf[i]);
            }
        }
        putchar('\n');
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2950399   2008-06-15 18:43:47     Accepted    2987    C++     00:00.00    392K    Re:ReJudge

// 2012-09-07 01:52:33 | Accepted | 2987 | C++ | 0 | 180 | watashi | Source
