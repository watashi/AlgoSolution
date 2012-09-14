#include <cstdio>
#include <vector>
#include <limits>
#include <numeric>
#include <algorithm>
using namespace std;

class Rec
{
public:
    int b, p, t;
    Rec(int b, int p, int t) : b(b), p(p), t(t)
    {
    }
    bool operator<(const Rec& rhs) const
    {
        return b > rhs.b;
    }
};

int main(void)
{
    int re;
    int n, m, b, p;

    scanf("%d", &re);
    while(re--) {
        scanf("%d", &n);

        vector<int> vp(n, numeric_limits<int>::max());
        vector<Rec> vr;

        for (int i = 0; i < n; i++) {
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d%d", &b, &p);
                vr.push_back(Rec(b, p, i));
            }
        }
        sort(vr.begin(), vr.end());

        int s = 0;
        double ans = 0;

        m = n;
        p = -1;
        while(++p < (int)vr.size()) {
            if(vp[vr[p].t] == numeric_limits<int>::max())
                --m;
            vp[vr[p].t] = min(vp[vr[p].t], vr[p].p);
            if(m == 0) {
                s = accumulate(vp.begin(), vp.end(), 0);
                ans = (double)vr[p].b / (double)s;
                break;
            }
        }
        while(++p < (int)vr.size()) {
            if(vr[p].p < vp[vr[p].t]) {
                s -= vp[vr[p].t] - vr[p].p;
                vp[vr[p].t] = vr[p].p;
            }
            ans = max(ans, (double)vr[p].b / (double)s);
        }
        printf("%.3lf\n", ans);
    }
}
//2916721   2008-05-15 20:09:32     Accepted    1409    C++     00:00.01    840K    Re:ReJudge

// 2012-09-07 00:48:50 | Accepted | 1409 | C++ | 0 | 568 | watashi | Source
