#include <algorithm> // auto fix CE
#include <cstdio>

struct Point
{
    int x, y;
};

struct Triangle
{
    Point a, b, c;
};

inline bool right_side(const Point& a, const Point& b, const Point& p)
{
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x) < 0;
}

inline bool in_triangle(const Triangle& abc, const Point& p)
{
    return right_side(abc.a, abc.b, p) &&
        right_side(abc.b, abc.c, p) &&
        right_side(abc.c, abc.a, p);
}

bool mp[20][20];

int main(void)
{
    bool flag;
    int xmin, xmax, ymin, ymax;
    Point p;
    Triangle abc;

    printf("Program 4 by team X\n");
    while(scanf("%d%d%d%d%d%d", &abc.a.x, &abc.a.y, &abc.b.x, &abc.b.y, &abc.c.x, &abc.c.y) != EOF) {
        xmin = ymin = 10;
        xmax = ymax = -10;
        for (p.x = -8; p.x <= 8; p.x++)
            for (p.y = -8; p.y <= 8; p.y++) {
                if (in_triangle(abc, p)) {
                    mp[p.x + 10][p.y + 10] = true;
                    /* xmax >?= p.x; */ /* auto fix >?= */
                    xmax = xmax > p.x ? xmax : p.x;
                    /* xmin <?= p.x; */ /* auto fix <?= */
                    xmin = xmin < p.x ? xmin : p.x;
                    /* ymax >?= p.y; */ /* auto fix >?= */
                    ymax = ymax > p.y ? ymax : p.y;
                    /* ymin <?= p.y; */ /* auto fix <?= */
                    ymin = ymin < p.y ? ymin : p.y;
                }
                else mp[p.x + 10][p.y + 10] = false;
            }
        for (int j = ymax; j >= ymin; j--) {
            flag = true;
            for (int i = xmin; i <= xmax; i++)
                if(mp[i + 10][j + 10])
                    flag = false;
            if(flag)
                puts("");
            for (int i = xmin; i <= xmax; i++) {
                if(mp[i + 10][j + 10]) {
                    flag = true;
                    if(i > xmin)
                        putchar(' ');
                    printf("(%2d, %2d)", i, j);
                }
                else if(flag) {
                    putchar('\n');
                    flag = false;
                    break;
                }
                else {
                    if(i > xmin)
                        putchar(' ');
                    printf("        ");
                }
            }
            if(flag)
                putchar('\n');
        }
        puts("");
    }
    printf("End of program 4 by team X\n");

    return 0;
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2834956   2008-04-09 22:48:01     Accepted    1123    C++     00:00.00    392K    わたし

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//18443     2008-04-16 20:30:27     Accepted    1011    C++     0   504     watashi

// 2012-09-07 13:53:02 | Accepted | 1123 | C++ | 0 | 180 | watashi | Source
