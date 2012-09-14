#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Rect
{
    int x1, y1, x2, y2;
    int tag;
};

struct Pred
{
    bool operator()(const Rect& r) const
    {
        return r.tag == -1;
    }
};

bool intersect(const Rect& lhs, const Rect& rhs)
{
    return !(lhs.x2 <= rhs.x1 || rhs.x2 <= lhs.x1) &&
        !(lhs.y2 <= rhs.y1 || rhs.y2 <= lhs.y1);
}

vector<Rect> rects;
vector<set<int> > ans;

int main(void)
{
    int n, m, q;
    Rect r, rr;

    while (scanf("%d", &n) != EOF) {
        rects.clear();
        ans = vector<set<int> >(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &r.x1, &r.y1, &r.x2, &r.y2);
            r.tag = i;
            m = (int)rects.size();
            for (int j = 0; j < m; j++) {
                if (!intersect(r, rects[j])) {
                    continue;
                }
                ans[rects[j].tag].insert(i);
                if (rects[j].x1 < r.x1) {
                    rr = rects[j];
                    rr.x2 = r.x1;
                    rects.push_back(rr);
                    rects[j].x1 = r.x1;
                }
                if (rects[j].x2 > r.x2) {
                    rr = rects[j];
                    rr.x1 = r.x2;
                    rects.push_back(rr);
                    rects[j].x2 = r.x2;
                }
                if (rects[j].y1 < r.y1) {
                    rr = rects[j];
                    rr.y2 = r.y1;
                    rects.push_back(rr);
                    rects[j].y1 = r.y1;
                }
                if (rects[j].y2 > r.y2) {
                    rr = rects[j];
                    rr.y1 = r.y2;
                    rects.push_back(rr);
                    rects[j].y2 = r.y2;
                }
                rects[j].tag = -1;
            }
            rects.push_back(r);
            rects.erase(remove_if(rects.begin(), rects.end(), Pred()), rects.end());
        }

        scanf("%d", &m);
        while (m--) {
            scanf("%d", &q);
            --q;
            printf("%u", ans[q].size());
            for (set<int>::const_iterator i = ans[q].begin(); i != ans[q].end(); ++i) {
                printf(" %d", *i + 1);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3009487   2008-07-27 21:48:09     Accepted    3005    C++     00:00.04    1004K   Re:ReJudge

// 2012-09-07 01:54:10 | Accepted | 3005 | C++ | 0 | 312 | watashi | Source
