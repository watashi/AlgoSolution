#include <cmath>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 32;
typedef pair<double, double> Point;

const double eps = 1e-5;
const double pi = acos(-1.0);
const char* ns = "CDEFGAB";

Point p[MAXN], pp[MAXN];

int safeDiv(double x, double y) {
    static char buf[1024];
    int z;
    sprintf(buf, "%.0lf\n", x / y);
    sscanf(buf, "%d", &z);
    if (fabs(x - z * y) > eps) {
        return 10000000;
    } else {
        return z;
    }
}

int main() {
    int ri = 0, n, b, q;
    char fn, ln, ans[MAXN];
    double th, sd;
    
    while (scanf("%d", &n) != EOF && n > 0) {
        scanf(" %c %c", &fn, &ln);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &p[i].first, &p[i].second);
        }
        for (int i = 1; i < n; ++i) {
            p[i].first -= p[0].first;
            p[i].second -= p[0].second;
        }
        p[0].first = 0;
        p[0].second = 0;
        printf("Case %d: ", ++ri);
        for (int d = -60; d <= 61; ++d) {
            if (d == 61) {
                throw "...";
            }
         //   printf("%d\n", d);
            th = d / 180.0 * pi;
            for (int i = 0; i < n; ++i) {
                pp[i].first = cos(th) * p[i].first - sin(th) * p[i].second;
                pp[i].second = sin(th) * p[i].first + cos(th) * p[i].second;
            }
            sort(pp, pp + n);
            sd = (pp[n - 1].second - pp[0].second) / (strchr(ns, ln) - strchr(ns, fn));
        //   if (1) {printf("sd = %lf\n", sd);}
           
            if (sd < 0.5 - eps || sd > 2.5 + eps) {
                goto next;
            }
            for (int i = 1; i < n; ++i) {
                if (pp[i - 1].first + 10 * sd + eps < pp[i].first ||
                    pp[i].first < pp[i - 1].first + 2 * sd - eps) {
                    goto next;  // ?
                }
            }
            b = strchr(ns, fn) - ns;
            for (int i = 0; i < n; ++i) {
                q = b + safeDiv(pp[i].second - pp[0].second, sd);
             //   if (d == -55) printf("%d %d %lf\n", i, q, pp[i].second - pp[0].second);
                if (q < 0 || q >= 7) {
                    goto next;
                } else {
                    ans[i] = ns[q];
                }
            }
            ans[n] = '\0';
            puts(ans);
            break;
next:
            continue;
        }        
    }

    return 0;
}


//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727357  	2011-01-29 11:59:00 	Accepted	0.006	Minimum	26909	C++	3788 - Hidden Music Score

/*
id => 1174151
pid => 3788
pname => Hidden Music Score
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:30:44
*/
