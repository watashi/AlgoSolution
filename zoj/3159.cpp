#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10;
const int MAXSIZE = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;

int n;
double vx, vy, t;
double x[MAXN], y[MAXN];
bool flag[2][MAXSIZE];
int fact[11];

bool gotry(int *arr, double res)
{
    double x1, x2, y1, y2;
    x1 = x[arr[0]] - res * vx;
    x2 = x[arr[0]] + res * vx;
    y1 = y[arr[0]] - res * vy;
    y2 = y[arr[0]] + res * vy;
    for (int i = 1; i < n; ++i) {
        res -= t;
        if (res < 0.0) res = 0.0;
        double xx1, xx2, yy1, yy2;
        xx1 = x[arr[i]] - res * vx;
        xx2 = x[arr[i]] + res * vx;
        yy1 = y[arr[i]] - res * vy;
        yy2 = y[arr[i]] + res * vy;
        x1 = max(x1, xx1);
        x2 = min(x2, xx2);
        y1 = max(y1, yy1);
        y2 = min(y2, yy2);
        if (x1 > x2 || y1 > y2) return false;
    }
    return true;
}

double run()
{
    scanf("%lf %lf %lf", &vx, &vy, &t);
    double maxx = -10000000, minx = 10000000, maxy = -10000000, miny = 10000000;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf", x + i, y + i);
        maxx = max(maxx, x[i]);
        maxy = max(maxy, y[i]);
        minx = min(minx, x[i]);
        miny = min(miny, y[i]);
    }
    memset(flag[0], true, sizeof(flag[0]));
    double down = t * (n - 2);
    double up = t * n + maxy - miny + maxx - minx;
    int ind = 0;
    for (int i = 0; i < 100; ++i) {
        double mid = (down + up) / 2;
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int j = 0;
        bool allfail = true;
        do {
            if (flag[ind][j] == false) {
                flag[1 - ind][j] = false;
            }
            else {
                if (gotry(arr, mid)) {
                    flag[1 - ind][j] = true;
                    for (++j; j < fact[n]; ++j) {
                        flag[1 - ind][j] = flag[ind][j];
                    }
                    ind = 1 - ind;
                    allfail = false;
                    break;
                }
                else {
                    flag[1 - ind][j] = false;
                }
            }
        }
        while (next_permutation(arr, arr + n));
        if (allfail) {
            down = mid;
        }
        else {
            up = mid;
        }
    }

    return up;
}

int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    while (scanf("%d", &n) != EOF) {
        printf("%.20lf\n", run());
    }
    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801087   2009-03-23 21:01:07     Accepted    3159    C++     4340    7264    watashi@Zodiac

// 2012-09-07 02:04:35 | Accepted | 3159 | C++ | 4140 | 7268 | watashi | Source
