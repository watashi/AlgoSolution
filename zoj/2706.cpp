#include <cstdio>
#include <algorithm>

using namespace std;

// Replace-Sum SegmentTree
class SegmentTree
{
    private:
        size_t n;
        long long *a, s, ss;
        bool *b;
        static inline size_t left(size_t p);
        static inline size_t right(size_t p);
        void replace(bool flag, long long v, size_t l, size_t r, size_t pl, size_t pr, size_t p);
        long long sum(size_t l, size_t r, size_t pl, size_t pr, size_t p);
    public:
        SegmentTree(size_t c, const long long v[]);
        ~SegmentTree();
        long long sum(size_t l, size_t r);
        void update(size_t l, size_t r);
};

inline size_t SegmentTree::left(size_t p)
{
    return (p << 1);
}

inline size_t SegmentTree::right(size_t p)
{
    return (p << 1) ^ 1;
}

SegmentTree::SegmentTree(size_t c, const long long v[])
{
    n = 1;
    while (n < c) {
        n <<= 1;
    }
    a = new long long[2 * n];
    b = new bool[2 * n];
    fill(b, b + 2 * n, false);
    fill(b + n, b + n + c, true);
    s = 0;
    for (size_t i = 0; i < c; i++) {
        a[n + i] = v[i];
        s += v[i];
    }
    ss = s;
}

SegmentTree::~SegmentTree()
{
    delete[] a;
    delete[] b;
}

void SegmentTree::replace(bool flag, long long v, size_t l, size_t r, size_t pl, size_t pr, size_t p)
{
    if (l == pl && r == pr) {
        b[p] = true;
        a[p] = v;
        return;
    }
    else {
        size_t pm = (pl + pr) >> 1;
        if (b[p]) {
            b[p] = false;
            if (flag) {
                flag = false;
                if (l > pl) {
                    replace(flag, a[p], pl, l, pl, pr, p);
                }
                if (r < pr) {
                    replace(flag, a[p], r, pr, pl, pr, p);
                }
            }
        }
        if (r <= pm) {
            replace(flag, v, l, r, pl, pm, left(p));
        }
        else if (l >= pm) {
            replace(flag, v, l, r, pm, pr, right(p));
        }
        else {
            replace(flag, v, l, pm, pl, pm, left(p));
            replace(flag, v, pm, r, pm, pr, right(p));
        }
    }
}

long long SegmentTree::sum(size_t l, size_t r, size_t pl, size_t pr, size_t p)
{
    if (b[p]) {
        return a[p] * (r - l);
    }
    else {
        size_t pm = (pl + pr) >> 1;
        if (r <= pm) {
            return sum(l, r, pl, pm, left(p));
        }
        else if (l >= pm) {
            return sum(l, r, pm, pr, right(p));
        }
        else {
            return sum(l, pm, pl, pm, left(p)) + sum(pm, r, pm, pr, right(p));
        }
    }
}

long long SegmentTree::sum(size_t l, size_t r)
{
    return sum(l, r, 0, n, 1);
}

void SegmentTree::update(size_t l, size_t r)
{
    long long v, vs;

    vs = sum(l, r);
    // v = (s > ss) ? vs / (r - l) : (vs + r - l - 1) / (r - l);    // WA if vs is negtive  // no std for this, only recommand
    if (s > ss) {
        v = (vs >= 0 ? vs / (r - l) : (vs - r + l + 1) / (r - l));
    }
    else {
        v = (vs >= 0 ? (vs + r - l - 1) / (r - l) : vs / (r - l));
    }
    s = s - vs + v * (r - l);
    replace(true, v, l, r, 0, n, 1);
}

int main(void)
{
    int n, m, l, r;
    static long long a[32768];

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        SegmentTree tr(n, a);

        for (int i = 0; i < m; i++) {
            scanf("%d%d", &l, &r);
            tr.update(l - 1, r);
/*          for (int j = 0; j < n; j++) {
                printf("%lld%c", tr.sum(j, j + 1), (j == n - 1) ? '\n' : ' ');
            }
*/      }
        for (int i = 0; i < n; i++) {
            printf("%lld%c", tr.sum(i, i + 1), (i == n - 1) ? '\n' : ' ');
        }
        putchar('\n');
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3022069 2008-08-05 08:34:00 Accepted 2706 C++ 00:01.60 1276K Re:ReJudge
//

// 2012-09-07 01:35:47 | Accepted | 2706 | C++ | 700 | 952 | watashi | Source
