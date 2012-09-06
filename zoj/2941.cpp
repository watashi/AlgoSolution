#include <cstdio>

const int num[20] = {
    0, 2, 4, 6, 30, 32, 34, 36, 40, 42, 44, 46, 50, 52, 54, 56, 60, 62, 64, 66
};

int a[10];

int main(void)
{
    int n, m;

    while(scanf("%d", &n) != EOF && n != 0) {
        m = -1;
        while (n) {
            a[++m] = n % 20;
            n /= 20;
        }
        printf("%d", num[a[m--]]);
        if(m == 6) {
            printf(",000,000");
        }
        while (m >= 0) {
            printf(",%03d", num[a[m--]]);
        }
        printf("\n");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948499   2008-06-12 19:21:28     Accepted    2941    C++     00:00.00    388K    Re:ReJudge

// 2012-09-07 01:49:06 | Accepted | 2941 | C++ | 0 | 180 | watashi | Source
