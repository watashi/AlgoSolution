#include <cstdio>

const char *ans[] =
{
    "",
    "",
    "not special",
    "21",
    "31",
    "43",
    "5421",
    "5431",
    "76531",
    "765421",
    "9875321",
    "9876421",
    "BA98765421",
    "BA8765431",
    "DCBA9654321",
    "EDCBA8765432",
    "FEDCBA8765431"
};

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        puts(ans[n]);
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//27657     2008-07-09 00:17:17     Accepted    1001    C++     0   260     watashi     Source
//
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3040678   2008-08-18 16:16:18     Accepted    3014    C++     00:00.00    392K    Re:ReJudge
//

// 2012-09-07 01:55:05 | Accepted | 3014 | C++ | 0 | 180 | watashi | Source
