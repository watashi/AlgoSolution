#include <cstdlib> // auto fix CE
#include <utility> // auto fix CE
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

const double eps = 1e-6;

struct Point
{
    double x, y, z;
    Point() { };
    Point(double x, double y, double z)
        : x(x), y(y), z(z)
    {
    }
};

double sqr(double x)
{
    return x * x;
}

double abs(const Point& a)
{
    return sqrt(sqr(a.x) + sqr(a.y) + sqr(a.z));
}

Point operator-(const Point& a, const Point& b)
{
    return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

double dmult(const Point& a, const Point& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point xmult(const Point& a, const Point& b)
{
    return Point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

double mult(const Point& a, const Point& b, const Point& c)
{
    return dmult(xmult(a, b), c);
}

int n, m;
Point p[52];
pair<pair<int, int>, int> r[52];
double mind[5050];
vector<pair<int, double> > rp[52];
vector<pair<int, double> > e[5050];

// a, b共线
double operator/(const Point& a, const Point& b)
{
    if (dmult(a, b) < 0) {
        return -1;
    }
    else {
        return abs(a) / abs(b);
    }
}

void add(int a, int b, double d)
{
    e[a].push_back(make_pair(b, d));
    e[b].push_back(make_pair(a, d));
}

void gao(int i, int j)
{
    int a = r[i].first.first, b = r[i].first.second, ab = r[i].second;
    int c = r[j].first.first, d = r[j].first.second, cd = r[j].second;
    int diff = abs(ab - cd);
    // 共面
    if (fabs(mult(p[a] - p[d], p[b] - p[d], p[c] - p[d])) > eps) {  // fabs T_T
        return;
    }
    // 平行
    if (abs(xmult(p[a] - p[b], p[c] - p[d])) < eps) {
        // 共线
/*      if (abs(xmult(p[a] - p[c], p[b] - p[c])) < eps) {
            double dab = abs(p[a] - p[b]), dcd = abs(p[c] - p[d]), rr;

            if (dmult(p[c] - p[a], p[b] - p[a]) > 0 && (rr = abs(p[a] - p[c]) / dab) < 1) {
                e[n].clear();
                add(n, c, diff);
                rp[i].push_back(make_pair(n++, rr));
            }
            if (dmult(p[d] - p[a], p[b] - p[a]) > 0 && (rr = abs(p[a] - p[d]) / dab) < 1) {
                e[n].clear();
                add(n, d, diff);
                rp[i].push_back(make_pair(n++, rr));
            }
            if (dmult(p[a] - p[c], p[d] - p[c]) > 0 && (rr = abs(p[c] - p[a]) / dcd) < 1) {
                e[n].clear();
                add(n, a, diff);
                rp[j].push_back(make_pair(n++, rr));
            }
            if (dmult(p[b] - p[c], p[d] - p[c]) > 0 && (rr = abs(p[c] - p[b]) / dcd) < 1) {
                e[n].clear();
                add(n, b, diff);
                rp[j].push_back(make_pair(n++, rr));
            }
        };
*/      return;
    }
    else {
        double r1 = xmult(p[a] - p[c], p[c] - p[d]) / xmult(p[a] - p[b], p[c] - p[d]), r2 = xmult(p[c] - p[a], p[a] - p[b]) / xmult(p[c] - p[d], p[a] - p[b]);

        // 相交
        if (r1 >= -eps && r1 <= 1 + eps && r2 >= -eps && r2 <= 1 + eps) {
            e[n].clear();
            rp[i].push_back(make_pair(n, r1));
            e[n + 1].clear();
            rp[j].push_back(make_pair(n + 1, r2));
            add(n, n + 1, diff);
            n += 2;
        }
    }
}

// 可以从虫洞到虫洞
// 此题远比看起来要难
int main()
{
    int s, t;
    int u, v, aa;

    Point p1(0, 0, 0), p2(1, 0, 0), p3(0, 1, 0), p4(0, 0, 1);

    //freopen("input", "r", stdin);
    while (scanf("%d%d%d%d", &n, &m, &s, &t) != EOF) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
            scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &aa);
            r[i] = make_pair(make_pair(u, v), aa);
            rp[i].clear();
            rp[i].push_back(make_pair(u ,0));
            rp[i].push_back(make_pair(v, 1));
            for (int j = 0; j < i; j++) {
                if (r[j].first.first != u && r[j].first.first != v && r[j].first.second != u && r[j].first.second != v) {
                    gao(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            mind[i] = 1e100;
        }
        for (int i = 0; i < m; i++) {
            double d = r[i].second * abs(p[r[i].first.first] - p[r[i].first.second]);
            for (int j = 0; j < rp[i].size(); j++) {
                for (int k = 0; k < j; k++) {
                    add(rp[i][j].first, rp[i][k].first, d * fabs(rp[i][j].second - rp[i][k].second));
                }
            }
        }

        pair<double, int> p;
        priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;

        mind[s] = 0;
        pq.push(make_pair(mind[s], s));
        while (!pq.empty()) {
            p = pq.top();
            pq.pop();
            if (p.first != mind[p.second]) {
                continue;
            }
            if (p.second == t) {
                break;
            }
            for (vector<pair<int, double> >::const_iterator i = e[p.second].begin(); i != e[p.second].end(); ++i) {
                if (mind[i->first] > p.first + i->second) {
                    mind[i->first] = p.first + i->second;
                    pq.push(make_pair(mind[i->first], i->first));
                }
            }
        }

        //printf("%d\n", n);
        if (mind[t] == 1e100) {
            puts("Impossible!");
        }
        else {
            printf("%.2lf\n", mind[t]);
        }
    }

    return 0;
}

// 2012-09-07 13:37:11 | Accepted | 3004 | C++ | 0 | 280 | watashi | Source
