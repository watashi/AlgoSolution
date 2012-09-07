#include <algorithm> // auto fix CE
#include <list>
#include <cmath>
#include <cstdio>
#include <utility>
using namespace std;

int main(int argc, char *argv[])
{
    int ri = 0, n, ans;
    double r, t, x, y;

    while(scanf("%d%lf", &n, &r) != EOF && n > 0) {
        bool flag = false;
        list<pair<double, double> > lt;
        list<pair<double, double> >::iterator it, itr;

        printf("Case %d: ", ++ri);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &x, &y);
            if(flag || y > r) {
                flag = true;
                continue;
            }
            t = sqrt(r * r - y * y);
            lt.push_front(make_pair(x + t, x - t));
        }
        if(flag) {
            printf("-1\n");
            continue;
        }
        lt.sort();
        ans = 0;
        it = lt.begin();
        while(it != lt.end()) {
            ++ans;
            itr = it;
            ++itr;
            while(itr != lt.end()) {
                if(itr->second <= it->first) {
                    itr = lt.erase(itr);
                }
                else {
                    ++itr;
                }
            }
            ++it;
        }
        printf("%d\n", ans);
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2918615 2008-05-16 20:31:48 Accepted 1360 C++ 00:00.01 872K Re:ReJudge

// 2012-09-07 13:35:19 | Accepted | 1360 | C++ | 10 | 180 | watashi | Source
