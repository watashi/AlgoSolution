#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <utility>

using namespace std;

double ALPHA = M_PI * rand() / RAND_MAX;
double COSA = cos(ALPHA);
double SINA = sin(ALPHA);

void rot(double& x, double& y) {
    double xx = COSA * x - SINA * y;
    double yy = SINA * x + COSA * y;
    x = xx;
    y = yy;
}

const int MAXN = 200200;
pair<double, double> p[MAXN];
set<pair<int, int> > st;

int main() {
    int n, m;
    double r;

    scanf("%d%lf", &n, &r);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf", &p[i].first, &p[i].second);
        p[i].first += ALPHA;
        p[i].second -= ALPHA;
        // rot(p[i].first, p[i].second);
        st.insert({(int)floor(p[i].first / r), (int)floor(p[i].second / r)});
    }
    m = 0;
    while (!st.empty()) {
        auto p = *st.begin();
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                st.erase({p.first + i, p.second + j});
            }
        }
        ++m;
    }
    printf("%d\n", m);

    return 0;
}

