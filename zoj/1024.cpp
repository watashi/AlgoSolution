/*
pic1: not this question
    1   2   ... 27  28  29  30  31
11  L   W   L   W||             \
10  W   L   ..      L   W   L   W
9   L   W   ..      W   L   W   \
8   W   L   ..      L   W   L   W
7   L   W   ..      W   L   W   L
6   W   L   ..      L   W   {W} \
5   L   W   ..      W   L   W   L
4   W   L   ..      L   W   {W} \
3   L   W   ..  L   W   L   W   L
2   W   L   ..  W   W(L)    (W) \   \
1   L   W   ..  L   W   L   W   L
12  W   L   ..      L   W   L   W
11  L   W   ..      W   L   W   \

pic2: this question
    1   2   ... 27  28  29  30  31
11  W   L   W   L||             \
10  L   W   ..      W   L   W   L
9   W   L   ..      L   W   {W} \
8   L   W   ..      W   L   W   L
7   W   L   ..      L   W   L   W
6   L   W   ..      W   L   W   \
5   W   L   ..      L   W   L   W
4   L   W   ..      W   L   W   \
3   W   L   ..  W   L   W   L   W
2   L   W   ..  L   W   (L) \   \
1   W   L   ..      L   W   L   W
12  L   W   ..      W   L   W   L
11  W   L   ..      L   W   {W} \
*/

#include <cstdio>

int main(void)
{
    int re;
    int yy, mm, dd;

    scanf("%d", &re);
    while(re--) {
        scanf("%d%d%d", &yy, &mm, &dd);
        if((mm + dd) % 2 == 0 || (mm == 9 || mm == 12) && dd == 30)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2800489 2008-03-24 18:10:08 Accepted 1024 C++ 00:00.00 388K わたし
//2800488 2008-03-24 18:09:05 Accepted 1024 C++ 00:00.01 388K わたし

// 2012-09-07 00:33:07 | Accepted | 1024 | C++ | 0 | 180 | watashi | Source
