#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    int re, n, k;
    char buf[1024];
    string lhs, rhs, src, tar;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        scanf("%s", buf);
        lhs = buf;
        scanf("%s", buf);
        rhs = lhs + buf;
        scanf("%s", buf);
        tar = buf;

        src = lhs = rhs;
        k = 0;
        while(true) {
            for (int i = 0; i < n; i++) {
                rhs[2 * i] = lhs[n + i];
                rhs[2 * i + 1] = lhs[i];
            }
            ++k;
            if (rhs == tar) {
                printf("%d %d\n", ri, k);
                break;
            }
            if (rhs == src) {
                printf("%d %d\n", ri, -1);
                break;
            }
            lhs.swap(rhs);
        }
    }

    return 0;
}

// Run ID   Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2953717   2008-06-21 02:23:47     Accepted    2774    C++     00:00.00    840K    Re:ReJudge

//没有证明循环的具体情况

// 2012-09-07 01:39:08 | Accepted | 2774 | C++ | 0 | 180 | watashi | Source
