#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void flip(int s[], int p)
{
    for (int i = 0; i < p; i++)
        s[i] = -s[i];
    reverse(s, s + p);
}

int s[32];
int k, ans[128];

int main(void)
{
    int re;
    int n;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &s[i]);
        k = 0;
        for (int i = n; i > 1; i--) {
            int p = 0;
            for (int j = 0; j < i; j++) {
                if (abs(s[j]) == i) {
                    p = j + 1;
                    break;
                }
            }
            if (p == i && s[p - 1] > 0)
                continue;
            if (p != 1) {
                ans[k++] = p;
                flip(s, p);
            }
            if (s[0] > 0) {
                ans[k++] = 1;
                flip(s, 1);
            }
            ans[k++] = i;
            flip(s, i);
        }
        if (s[0] < 0) {
            ans[k++] = 1;
            flip(s, 1);
        }

        printf("%d %d", ri, k);
        for (int i = 0; i < k; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2950442   2008-06-15 19:49:36     Accepted    2991    C++     00:00.02    440K    Re:ReJudge

// 2012-09-07 01:52:57 | Accepted | 2991 | C++ | 10 | 180 | watashi | Source
