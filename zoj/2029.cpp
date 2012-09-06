#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, m, b;

    while(scanf("%d%d", &n, &m) != EOF) {
        vector<int> a(n);
        vector<int>::const_iterator lhs, rhs;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        while (m--) {
            scanf("%d", &b);
            lhs = lower_bound(a.begin(), a.end(), b);
            rhs = upper_bound(a.begin(), a.end(), b);
            if(rhs == a.end()) {
                printf("no such interval\n");
            }
            else if(*lhs == b) {
                printf("[%d,%d)\n", *lhs, *rhs);
            }
            else if(lhs == a.begin()) {
                printf("no such interval\n");
            }
            else {
                printf("[%d,%d)\n", *--lhs, *rhs);
            }
        }
        printf("\n");   // PE
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948267   2008-06-12 15:22:14     Accepted    2029    C++     00:00.01    836K    Re:ReJudge

// 2012-09-07 01:10:51 | Accepted | 2029 | C++ | 0 | 180 | watashi | Source
