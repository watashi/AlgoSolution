#include <cstdio>

int main(void)
{
    int ww, w, h, tw, th, maxw, maxh;

    while(scanf("%d", &ww) != EOF && ww > 0) {
        tw = th = 0;
        maxw = maxh = 0;
        while(scanf("%d%d", &w, &h) != EOF && w >= 0 && h >= 0) {
            if(tw + w > ww) {
                tw = w;
                if(tw > maxw)
                    maxw = tw;
                th = maxh;
                maxh = th + h;
            }
            else {
                tw = tw + w;
                if(tw > maxw)
                    maxw = tw;
                if(th + h > maxh)
                    maxh = th + h;
            }
        }
        printf("%d x %d\n", maxw, maxh);
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2841895   2008-04-13 17:18:30     Accepted    2173    C++     00:00.00    388K    Re:ReJudge

// 2012-09-07 01:14:48 | Accepted | 2173 | C++ | 0 | 180 | watashi | Source
