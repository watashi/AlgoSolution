#include <cstdio> // auto fix CE
#include <cstdlib>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    bool flag;
    int n, m, d;
    static int a[128], b[128];

    while (scanf("%d%d", &n, &m) != EOF && n > 0 && m > 0) {
        d = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            d -= a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
            d += b[i];
        }
        sort(b, b + m);

        flag = false;
        // O(nlgn), there is also a O(n) scan method
        if (d % 2 == 0) {
            d /= 2;
            for (int i = 0; i < n; i++) {
                if (binary_search(b, b + m, a[i] + d)) {
                    printf("%d %d\n", a[i], a[i] + d);
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            puts("-1");
        }
    }

    return (EXIT_SUCCESS);
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3041258   2008-08-18 22:23:43     Accepted    3023    C++     00:00.00    440K    Re:ReJudge

// 2012-09-07 13:37:23 | Accepted | 3023 | C++ | 0 | 180 | watashi | Source
