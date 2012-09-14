// ¾ØÐÎÇÐ¸î

#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int deleted_tag = -1;

struct Rect
{
    int x1, y1, x2, y2;
    int tag;
    int a() const
    {
        return (x2 - x1) * (y2 - y1);
    }
};

struct Pred
{
    bool operator()(const Rect& r) const
    {
        return r.tag == deleted_tag;
    }
};

bool intersect(const Rect& lhs, const Rect& rhs)
{
    return !(lhs.x2 <= rhs.x1 || rhs.x2 <= lhs.x1) &&
        !(lhs.y2 <= rhs.y1 || rhs.y2 <= lhs.y1);
}

vector<Rect> rects;

void add(Rect& r)
{
    static Rect rr;
    int m = (int)rects.size();

    for (int j = 0; j < m; j++) {
        if (!intersect(r, rects[j])) {
            continue;
        }
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
        rects[j].tag = deleted_tag;
    }
    rects.push_back(r);
    rects.erase(remove_if(rects.begin(), rects.end(), Pred()), rects.end());
}

int main(void)
{
    int n, ri = 0;
    Rect r;
    map<int, int> a;

    while (scanf("%*d%*d%d", &n) == 1) {
        rects.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d%d", &r.x1, &r.y1, &r.x2, &r.y2, &r.tag);
            add(r);
        }
        a.clear();
        for (size_t i = 0; i < rects.size(); i++) {
            a[rects[i].tag] += rects[i].a();
        }
        if (ri++ > 0) {
            putchar('\n');
        }
        printf("Case %d:\n", ri);
        for (map<int, int>::const_iterator i = a.begin(); i != a.end(); i++) {
            printf("%d %d\n", i->first, i->second);
        }
        printf("There %s %u color%s left on the wall.\n", a.size() == 1 ? "is" : "are", a.size(), a.size() == 1 ? "" : "s");
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3020899 2008-08-04 14:50:54 Accepted 2747 C++ 00:00.03 856K Re:ReJudge
//

// 2012-09-07 01:37:48 | Accepted | 2747 | C++ | 0 | 180 | watashi | Source
