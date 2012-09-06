#include <cstdio>

const int Dir[4][2] = {
    {10, 0},
    {0, 10},
    {-10, 0},
    {0, -10}
};

char buf[256];

int main(void)
{
    int x, y, d;

    while(scanf("%s", buf) != EOF) {
        x = 300;
        y = 420;
        d = 0;
        printf("%d %d moveto\n", x, y);
        x += Dir[d][0];
        y += Dir[d][1];
        printf("%d %d lineto\n", x, y);
        for (int i = 0; buf[i] != '\0'; i++) {
            if(buf[i] == 'V') {
                ++d;
                if(d == 4)
                    d = 0;
            }
            else {
                --d;
                if(d == -1)
                    d = 3;
            }
            x += Dir[d][0];
            y += Dir[d][1];
            printf("%d %d lineto\n", x, y);
        }
        printf("stroke\nshowpage\n");
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2843441   2008-04-14 15:39:42     Accepted    1982    C++     00:00.00    392K    Re:ReJudge

// 2012-09-07 01:09:25 | Accepted | 1982 | C++ | 0 | 180 | watashi | Source
