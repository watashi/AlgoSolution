#include <cstdio>
#include <algorithm>

using namespace std;

int a[65536], b[65536];

int main(void)
{
    int n, m;

    while(scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[j]);
        }
        sort(b, b + m);
        int ans = 0;
        for (int i = 0, j = 0; i < n && j < m; ) {
            if (a[i] == b[j]) {
                ++i;
                ++j;
                ++ans;
            }
            else if (a[i] < b[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}

//26480     2008-07-06 15:55:15     Accepted    1010    C++     180     772     watashi     Source
//
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3040699   2008-08-18 16:22:43     Accepted    3019    C++     00:00.17    948K    Re:ReJudge
//

// 2012-09-07 01:55:36 | Accepted | 3019 | C++ | 50 | 692 | watashi | Source
