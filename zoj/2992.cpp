#include <cstdio>

char str[256];

int main(void)
{
    int re;
    int tmp, ans;

    scanf("%d", &re);
    gets(str);
    for (int ri = 1; ri <= re; ri++) {
        gets(str);
        tmp = ans = 0;
        for (int i = 0; str[i] != '\0'; ++i) {
            if (str[i] == '[')
                ++tmp;
            else
                --tmp;
            if (tmp > ans)
                ans = tmp;
        }
        printf("%d %d\n", ri, 1 << ans);
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2950467   2008-06-15 21:01:52     Accepted    2992    C++     00:00.00    388K    Re:ReJudge

// 2012-09-07 01:53:03 | Accepted | 2992 | C++ | 0 | 180 | watashi | Source
