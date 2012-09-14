#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#ifndef ONLINE_JUDGE
#  define CHECK(v, l, r)\
        do {\
            if (v < l || v > r) {\
                fprintf(stderr, "%d\t!"#v"! %d $ (%d,%d)\n", __LINE__, v, l, r);\
            }\
        } while (false)
#  define CHECK_NZ(v)\
        do {\
            if (v == 0) {\
                fprintf(stderr, "%d\t!"#v"! %d @ 0\n", __LINE__, v);\
            }\
        } while (false)
#else
#  define CHECK(v, l, r)
#  define CHECK_NZ(v)
#endif

int main() {
    int n, a, b;
    long long w, wa, wb, va1, va2, vb1, vb2;
    long long l, r, m, ww, ta, tb;
    bool fa, fb;
    double ansa, ansb;
    int p[50000], d[50000];
    vector<long long> pa, pb;

    while (scanf("%d%d%d", &n, &a, &b) != EOF) {
#ifndef ONLINE_JUDGE
        static int caseId = 0;
        fprintf(stderr, "#%d:\n", ++caseId);
#endif
        /* INPUT # CHECK */
        CHECK(n, 0, 50000);
        CHECK(a, -100000000, -1);
        CHECK(b, 1, 100000000);
        pa.clear();
        pb.clear();
        ww = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            CHECK(p[i], a, b);
            CHECK_NZ(p[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &d[i]);
            CHECK(d[i], -1, 1);
            CHECK_NZ(d[i]);
        }
        scanf("%lld%lld%lld%lld%lld%lld%lld", &w, &va1, &va2, &wa, &vb1, &vb2, &wb);
        CHECK((int)w, 1, 87654321);
        CHECK((int)va1, 1, 1000);
        CHECK((int)va2, 1, 1000);
        CHECK((int)wa, 1, 1000);
        CHECK((int)vb1, 1, 1000);
        CHECK((int)vb2, 1, 1000);
        CHECK((int)wb, 1, 1000);
        swap(va1, vb1);
        swap(va2, vb2);
        ta = -a * (va1 + va2);
        tb = b * (vb1 + vb2);
        for (int i = 0; i < n; ++i) {
            if (p[i] < 0) {
                if (d[i] == -1) {
                    pa.push_back(ta + va2 * -p[i]);
                    w += wa;
                } else/* if (t == 1)*/ {
                    pa.push_back(ta - va1 * -p[i]);
                }
            } else/* if (p[i] > 0)*/ {
                if (d[i] == 1) {
                    pb.push_back(tb + vb2 * p[i]);
                    w += wb;
                } else/* if (t == -1)*/ {
                    pb.push_back(tb - vb1 * p[i]);
                }
            }
        }
#ifndef ONLINE_JUDGE
        sort(p, p + n);
        for (int i = 1; i < n; ++i) {
            if (p[i] == p[i - 1]) {
                fprintf(stderr, "!duplicate p!\t%d\n", p[i]);
            }
        }
        /*
        if (unique(p, p + n) != p + n) {
            fprintf(stderr, "!duplicate p!\n");
        }
        */
#endif
        /* PROCESS */
        l = 0LL;
        r = 0x7f7f7f7f7f7f7f7fLL;
        while (l < r) {
            m = (l + r) / 2;
            ww = w;
            for (int i = 0; ww > 0 && i < pa.size(); ++i) {
                ww -= (m + pa[i]) / ta * wa;
            }
            for (int i = 0; ww > 0 && i < pb.size(); ++i) {
                ww -= (m + pb[i]) / tb * wb;
            }
            if (ww <= 0) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        /* OUTPUT */
        m = r;
        fa = fb = false;
        ansa = ansb = 0;
        for (int i = 0; i < pa.size(); ++i) {
            ww = (m + pa[i]) / ta * wa;
            if ((m + pa[i]) % ta == 0) {
                ww -= wa;
#ifndef ONLINE_JUDGE
                if (fa) {
                    fprintf(stderr, "!duplicate pa!\n");
                }
#endif
                fa = true;
            }
            w -= ww;
            ansa += ww;
        }
        for (int i = 0; i < pb.size(); ++i) {
            ww = (m + pb[i]) / tb * wb;
            if ((m + pb[i]) % tb == 0) {
                ww -= wb;
#ifndef ONLINE_JUDGE
                if (fb) {
                    fprintf(stderr, "!duplicate pb!\n");
                }
#endif
                fb = true;
            }
            w -= ww;
            ansb += ww;
        }
        if (fa && fb) {
            CHECK(w, 1, wa + wb);
            if (wa * 2 < w) {
                ansa += wa;
                ansb += w - wa;
            } else if (wb * 2 < w) {
                ansa += w - wb;
                ansb += wb;
            } else {
                ansa += w / 2.0;
                ansb += w / 2.0;
            }
        } else if (fa) {
            CHECK(w, 1, wa);
            ansa += w;
        } else if (fb) {
            CHECK(w, 1, wb);
            ansb += w;
        } else {
            CHECK(w, 0, 0);
        }
        printf("%.1lf %.1lf\n", ansa, ansb);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1748010   2009-01-24 17:14:12     Accepted    3152    C++     1030    1208    watashi@Zodiac

// 2012-09-07 02:03:58 | Accepted | 3152 | C++ | 1040 | 1212 | watashi | Source
