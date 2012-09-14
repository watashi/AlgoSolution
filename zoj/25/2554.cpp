#include <cstdio>

class Point
{
    public:
        int x, y;
};

Point p[200002];
int lx, ly;

int main(void)
{
    int n, k, a, b;

    while(scanf("%d", &n) != EOF && n > 0) {
        k = n / 2;
        for (int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        lx = p[k].x;
        ly = p[k].y;
        a = b = 0;
        for (int i = 0; i < n; i++) {
            if(p[i].x > lx) {
                if(p[i].y > ly)
                    ++a;
                else if(p[i].y < ly)
                    ++b;
            }
            else if(p[i].x < lx) {
                if(p[i].y < ly)
                    ++a;
                else if(p[i].y > ly)
                    ++b;
            }
        }
        printf("%d %d\n", a, b);
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2874662   2008-04-27 17:11:23     Accepted    2554    C++     00:00.01    1956K   Re:ReJudge

// 2012-09-07 01:28:11 | Accepted | 2554 | C++ | 0 | 1744 | watashi | Source
