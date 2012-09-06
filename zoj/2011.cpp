/*
#include <cmath>
#include <cstdio>
#include <utility>

using namespace std;

typedef pair<long long, long long> Complex;

const int MAXN = 100;
const double eps = 1e-8;
const Complex ZERO = Complex(0, 0);
long long a[MAXN + 1], nx, nb, nbb[MAXN + 1];
Complex x, b, bb[MAXN + 1];

long long norm(const Complex& c)
{
    return c.first * c.first + c.second * c.second;
}

Complex mul(const Complex& lhs, const Complex& rhs)
{
    return make_pair(lhs.first * rhs.first - lhs.second * rhs.second,
            lhs.first * rhs.second + lhs.second * rhs.first);
}

bool flag;
int n;

void gao(Complex c, int i)
{
    if (!flag) {
        if (i < 0) {
            if (c == ZERO) {
                flag = true;
                i = n;
                while (i > 0 && a[i] == 0) {
                    --i;
                }
                for (; i >= 0; --i) {
                    printf("%lld%c", a[i], (i == 0) ? '\n' : ',');
                }
            }
        }
        else {
            a[i] = (long long)(sqrt((double)(norm(c) / nbb[i])) + eps);
            c.first -= a[i] * bb[i].first;
            c.second -= a[i] * bb[i].second;
            if (a[i] > 0 && (a[i] - 1) * (a[i] - 1) < nb) {
                --a[i];
                gao(Complex(c.first + bb[i].first, c.second + bb[i].second), i - 1);
                ++a[i];
            }
            if (a[i] >= 2 && (a[i] - 2) * (a[i] - 2) < nb) {
                a[i] -= 2;
                gao(Complex(c.first + 2 * bb[i].first, c.second + 2 * bb[i].second), i - 1);
                a[i] += 2;
            }
            if (a[i] * a[i] < nb) {
                gao(c, i - 1);
                ++a[i];
                if (a[i] * a[i] < nb) {
                    c.first -= bb[i].first;
                    c.second -= bb[i].second;
                    gao(c, i - 1);
                }
                ++a[i];
                if (a[i] * a[i] < nb) {
                    c.first -= bb[i].first;
                    c.second -= bb[i].second;
                    gao(c, i - 1);
                }
            }
        }
    }
}

int main()
{
    int re;
    long long xr, xi, br, bi;

    scanf("%d", &re);
    while (re--) {
        scanf("%lld%lld%lld%lld", &xr, &xi, &br, &bi);
        x = Complex(xr, xi);
        nx = norm(x);
        b = Complex(br, bi);
        nb = norm(b);
        bb[0] = Complex(1, 0);
        nbb[0] = norm(bb[0]);
        for (n = 1; ; n++) {
            bb[n] = mul(bb[n - 1], b);
            nbb[n] = norm(bb[n]);
            if (nbb[n] > nx * 100) {
                break;
            }
        }
        flag = false;
        gao(x, n);
        if (!flag) {
            puts("The code cannot be decrypted.");
        }
    }

    return 0;
}

//1647852   2008-09-19 21:05:22       Accepted      2011    C++     510     260     watashi
*/

#include <cmath>
#include <stack>
#include <cstdio>

using namespace std;

int main()
{
    int re;
    int r, i, xr, xi, br, bi, bb, b, a;

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d%d%d", &xr, &xi, &br, &bi);
        bb = br * br + bi * bi;
        b = (int)(sqrt((double)bb) - 1e-6);
        stack<int> ans;
        do {
            for (a = 0; a <= b; a++) {
                r = (xr - a) * br - xi * (-bi);
                i = (xr - a) * (-bi) + xi * br;
                if (r % bb == 0 && i % bb == 0) {
                    xr = r / bb;
                    xi = i / bb;
                    ans.push(a);
                    break;
                }
            }
            if (a > b || ans.size() > 100) {
                break;
            }
        } while (xr != 0 || xi != 0);
        if (xr != 0 || xi != 0) {
            puts("The code cannot be decrypted.");
        }
        else {
            while(!ans.empty()) {
                printf("%d", ans.top());
                ans.pop();
                putchar(ans.empty() ? '\n' : ',');
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1647951   2008-09-19 22:12:10     Accepted    2011    C++     220     260     watashi

// 2012-09-07 01:10:08 | Accepted | 2011 | C++ | 200 | 180 | watashi | Source
