#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle
{
    int xl, yl, xr, yr;
};

Rectangle rect[108];

int main(void)
{
    int re;
    int w, h, n;
    vector<int> xx, yy;

    scanf("%d", &re);
    while(re--) {
        xx.clear();
        yy.clear();
        scanf("%d%d", &w, &h);
        xx.push_back(0); // 555 555
        yy.push_back(0); // 555 555
        xx.push_back(w); // 555
        yy.push_back(h); // 555
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &rect[i].xl, &rect[i].yl, &rect[i].xr, &rect[i].yr);
            xx.push_back(rect[i].xl);
            xx.push_back(rect[i].xr);
            yy.push_back(rect[i].yl);
            yy.push_back(rect[i].yr);
        }
        sort(xx.begin(), xx.end());
        xx.erase(unique(xx.begin(), xx.end()), xx.end());
        sort(yy.begin(), yy.end());
        yy.erase(unique(yy.begin(), yy.end()), yy.end());

        vector<vector<bool> > mark(xx.size() - 1, vector<bool>(yy.size() - 1, false));
        bool DISJOINT = true, CONTAIN = true, COVER = true;
        if(xx[0] < 0 || yy[0] < 0 || xx[xx.size() - 1] > w || yy[yy.size() - 1] > h)
            CONTAIN = false;
        for (int k = 0; k < n && DISJOINT; k++) {
            for (size_t i = lower_bound(xx.begin(), xx.end(), rect[k].xl) - xx.begin(); xx[i] < rect[k].xr && DISJOINT; ++i)
                for (size_t j = lower_bound(yy.begin(), yy.end(), rect[k].yl) - yy.begin(); yy[j] < rect[k].yr; ++j)
                    if(mark[i][j]) {
                        DISJOINT = false;
                        break;
                    }
                    else {
                        mark[i][j] = true;
                    }
        }
        if(!DISJOINT) {
            puts("NONDISJOINT");
        }
        else if(!CONTAIN) {
            puts("NONCONTAINED");
        }
        else {
            for (size_t i = 0; i < mark.size() && COVER; i++)
                for (size_t j = 0; j < mark[i].size(); j++)
                    if(!mark[i][j]) {
                        COVER = false;
                        break;
                    }
            puts(COVER ? "OK" : "NONCOVERING");
        }
    }

    return 0;
}

// 来自ljzhao的一个好方法O(n^2)比较Disjoint;max min 看CONTAINED;*比总面积看COVERING*!

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2839538   2008-04-12 10:20:39     Accepted    1565    C++     00:00.01    856K    わたし

// 2012-09-07 00:54:07 | Accepted | 1565 | C++ | 0 | 180 | watashi | Source
