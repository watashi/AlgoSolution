#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef map <int, int, greater<int> > MAP;
typedef MAP::iterator MAPITR;

class REC
{
public:
    int x;
    int p;
    int m;
};

REC vr[100000];

int main(void)
{
    int t, n, ans;

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &vr[i].x, &vr[i].p, &vr[i].m);
        ans = 0;

        MAP mp;
        MAPITR itr;

        for (int i = n - 1; i >= 0; i--) {
            itr = mp.find(vr[i].p);
            if(itr == mp.end()) mp.insert(make_pair(vr[i].p, vr[i].m));
            else itr -> second += vr[i].m;
            while(vr[i].x > 0 && mp.empty() == false) {
                if(vr[i].x >= mp.begin() -> second) {
                    ans += mp.begin() -> first * mp.begin() -> second;
                    vr[i].x -= mp.begin() -> second;
                    mp.erase(mp.begin());
                }
                else {
                    ans += mp.begin() -> first * vr[i].x;
                    mp.begin() -> second -= vr[i].x;
                    vr[i].x = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2756992 2008-02-21 18:29:05 Accepted 2921 C++ 00:00.81 2008K ¤ï¤¿¤·

// 2012-09-07 01:47:29 | Accepted | 2921 | C++ | 230 | 1352 | watashi | Source
