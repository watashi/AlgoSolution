#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class point
{
public:
    int x;
    int y;
    point(int x, int y) : x(x), y(y) { }
};

class shape
{
public:
    int size;
    vector<point> vp;
    void clear()
    {
        size = 0;
        vp.clear();
    }
    void get()
    {
        char buf[12];
        int x, y;

        scanf("%s", buf);
        if(strcmp(buf, "line") == 0) {
            size = 1;
            scanf(" (%d,%d)", &x, &y);
            vp.push_back(point(x << 1, y << 1));
            scanf(" (%d,%d)", &x, &y);
            vp.push_back(point(x << 1, y << 1));
        }
        else if(strcmp(buf, "triangle") == 0) {
            size = 3;
            for (int i = 0; i < size; i++) {
                scanf(" (%d,%d)", &x, &y);
                vp.push_back(point(x << 1, y << 1));
            }
            vp.push_back(vp[0]);
        }
        else if(strcmp(buf, "square") == 0) {
            size = 4;
            scanf(" (%d,%d)", &x, &y);
            vp.push_back(point(x << 1, y << 1));
            scanf(" (%d,%d)", &x, &y);
            vp.push_back(vp[0]);
            vp.push_back(point(x << 1, y << 1));
            vp.push_back(vp[0]);
            vp.push_back(vp[0]);
            x = vp[0].x + vp[2].x;
            y = vp[0].y + vp[2].y;
            vp[1].x = (x + vp[2].y - vp[0].y) >> 1;
            vp[1].y = (y + vp[0].x - vp[2].x) >> 1;
            vp[3].x = (x + vp[0].y - vp[2].y) >> 1;
            vp[3].y = (y + vp[2].x - vp[0].x) >> 1;
        }
        else if(strcmp(buf, "rectangle") == 0) {
            size = 4;
            scanf(" (%d,%d)", &x, &y);
            vp.push_back(point(x << 1, y << 1));
            scanf(" (%d,%d)", &x, &y);
            vp.push_back(point(x << 1, y << 1));
            scanf(" (%d,%d)", &x, &y);
            vp.push_back(point(x << 1, y << 1));
            vp.push_back(point(vp[0].x + vp[2].x - vp[1].x, vp[0].y + vp[2].y - vp[1].y));
            vp.push_back(vp[0]);
        }
        else if(strcmp(buf, "polygon") == 0) {
            scanf("%d", &size);
            for (int i = 0; i < size; i++) {
                scanf(" (%d,%d)", &x, &y);
                vp.push_back(point(x << 1, y << 1));
            }
            vp.push_back(vp[0]);
        }
    }
};

char buf[12];
shape s[26];
bool ans[26][26];

inline bool between(const int m, const int l, const int r)
{
    return l <= m && m <= r || l >= m && m >= r;
}

inline bool between(const point& m, const point& l, const point& r)
{
    return between(m.x, l.x, r.x) && between(m.y, l.y, r.y);
}

inline bool intersect(const point& a1, const point& a2, const point& b1, const point& b2)
{
    int xx, yy, p1, p2;

    xx = a2.x - a1.x;
    yy = a2.y - a1.y;
    p1 = (b1.y - a1.y) * xx - (b1.x - a1.x) * yy;
    p2 = (b2.y - a1.y) * xx - (b2.x - a1.x) * yy;
    if(p1 > 0) { if(p2 > 0) return false; else if(p2 == 0) return between(b2, a1, a2); }
    else if(p1 < 0) { if(p2 < 0) return false; else if(p2 == 0) return between(b2, a1, a2); }
    else if(p2 == 0) return between(a1, b1, b2) || between(a2, b1, b2) || between(b1, a1, a2) || between(b2, a1, a2);
    else return between(b1, a1, a2);

    xx = b2.x - b1.x;
    yy = b2.y - b1.y;
    p1 = (a1.y - b1.y) * xx - (a1.x - b1.x) * yy;
    p2 = (a2.y - b1.y) * xx - (a2.x - b1.x) * yy;
    if(p1 > 0) { if(p2 > 0) return false; else if(p2 < 0) return true; else return between(a2, b1, b2); }
    else if(p1 < 0) { if(p2 < 0) return false; else if(p2 > 0) return true; else return between(a2, b1, b2); }
    else return between(a1, b1, b2);
}

int main()
{
    while(scanf("%s", buf) != EOF && strcmp(buf, ".") != 0) {
        for (int i = 0; i < 26; i++) {
            s[i].clear();
            for (int j = 0; j < 26; j++)
                ans[i][j] = false;
        }
        while(strcmp(buf, "-") != 0) {
            s[buf[0] - 'A'].get();
            scanf("%s", buf);
        }
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < i; j++)
                for (int ii = 0; ans[i][j] == false && ii < s[i].size; ii++)
                    for (int jj = 0; ans[i][j] == false && jj < s[j].size; jj++)
                        if(intersect(s[i].vp[ii], s[i].vp[ii + 1], s[j].vp[jj], s[j].vp[jj + 1]))
                            ans[i][j] = ans[j][i] = true;
        for (int i = 0; i < 26; i++) {
            if(s[i].size == 0) continue;
            int k = 0, kk;
            for (int j = 0; j < 26; j++)
                if(ans[i][j]) {++k; kk = j;}
            putchar('A' + i);
            if(k == 0) {
                puts(" has no intersections");
            }
            else if(k == 1) {
                printf(" intersects with %c\n", 'A' + kk);
            }
            else if(k == 2) {
                printf(" intersects with");
                for (int j = 0; j < kk; j++)
                    if(ans[i][j]) printf(" %c", 'A' + j);
                printf(" and %c\n", 'A' + kk);
            }
            else {
                printf(" intersects with");
                for (int j = 0; j < kk; j++)
                    if(ans[i][j]) printf(" %c,", 'A' + j);
                printf(" and %c\n", 'A' + kk);
            }
        }
        putchar('\n');
    }
    return 0;
}

// Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
// 2750759 2008-02-14 13:08:47 Accepted 2906 C++ 00:00.05 844K ¤ï¤¿¤·

// 2012-09-07 01:46:21 | Accepted | 2906 | C++ | 30 | 180 | watashi | Source
