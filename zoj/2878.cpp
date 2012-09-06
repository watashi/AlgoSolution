#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int f, t;
        scanf("%d", &f);
        t = f;
        for (int i = 1; i < n; i++){
            int a;
            scanf("%d", &a);
            f = min(f, a);
            t = max(t, a);
        }
        printf("%d\n", (t - f) << 1);
    }
    return 0;
}
//2708373   2007-12-21 17:08:44     Accepted    2878    C++     00:00.00    388K    ¤ï¤¿¤·

// 2012-09-07 01:44:18 | Accepted | 2878 | C++ | 0 | 180 | watashi | Source
