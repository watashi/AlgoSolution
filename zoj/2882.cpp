#include <cstdio>
#include <algorithm>
using namespace std;
class doll
{
public:
    int w;
    int h;
    inline bool operator< (const class doll &that) const
    {
        if(w == that.w) return h > that.h;
        return w < that.w;
    }
};
const int MAXN = 20002;
doll a[MAXN];
int l[MAXN];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].w, &a[i].h);
        sort(a, a + n);
        int len = 0;
        l[len] = a[0].h;
        for (int i = 1; i < n; i++){
            int t = a[i].h;
            if(t <= l[len]) l[++len] = t;
            else if(t > l[0]) l[0] = t;
            else{
                int left = 0, right = len;
                while(left < right){
                    int mid = (left + right) >> 1;
                    if(t <= l[mid]) left = mid + 1;
                    else right = mid;
                }
                l[right] = t;
            }
        }
        printf("%d\n", len + 1);
    }
    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2708375   2007-12-21 17:10:22     Accepted    2882    C++     00:00.26    676K    ¤ï¤¿¤·

// 2012-09-07 01:44:25 | Accepted | 2882 | C++ | 100 | 412 | watashi | Source
