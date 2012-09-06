#include <cstdio>
#include <algorithm>
using namespace std;
int a[20002];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int ans = 0;
        for (int i = n - 3; i >= 0; i-=3)
            ans += a[i];
        printf("%d\n",ans);
    }
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2708377   2007-12-21 17:12:09     Accepted    2883    C++     00:00.16    520K    ¤ï¤¿¤·

// 2012-09-07 01:44:31 | Accepted | 2883 | C++ | 50 | 256 | watashi | Source
