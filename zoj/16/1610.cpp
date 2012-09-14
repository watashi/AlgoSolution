#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

// Replace-Sum SegmentTree
class SegmentTree
{
    private:
        size_t n;
        int *a;
        bool *b;
        static inline size_t left(size_t p);
        static inline size_t right(size_t p);
        void replace(bool flag, int v, size_t l, size_t r, size_t pl, size_t pr, size_t p);
        int sum(size_t l, size_t r, size_t pl, size_t pr, size_t p);
    public:
        SegmentTree(size_t c);
        ~SegmentTree();
        int sum(size_t l, size_t r);
        void replace(int v, size_t l, size_t r);
};

inline size_t SegmentTree::left(size_t p)
{
    return (p << 1);
}

inline size_t SegmentTree::right(size_t p)
{
    return (p << 1) ^ 1;
}

SegmentTree::SegmentTree(size_t c)
{
    n = 1;
    while (n < c) {
        n <<= 1;
    }
    a = new int[2 * n];
    b = new bool[2 * n];
    fill(b, b + 2 * n, false);
    a[1] = -1;
    b[1] = true;
}

SegmentTree::~SegmentTree()
{
    delete[] a;
    delete[] b;
}

void SegmentTree::replace(bool flag, int v, size_t l, size_t r, size_t pl, size_t pr, size_t p)
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

int SegmentTree::sum(size_t l, size_t r, size_t pl, size_t pr, size_t p)
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

int SegmentTree::sum(size_t l, size_t r)
{
    return sum(l, r, 0, n, 1);
}

void SegmentTree::replace(int v, size_t l, size_t r)
{
    replace(true, v, l, r, 0, n, 1);
}

int main(void)
{
    int n, l, r, c;

    while (scanf("%d", &n) != EOF) {
        SegmentTree tr(8000);

        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &l, &r, &c);
            tr.replace(c, l, r);
/*          for (int j = 0; j < 10; j++) {
                printf("%d%c", tr.sum(j, j + 1), (j == 9) ? '\n' : ' ');
            }
*/      }

        int prev, next;
        map<int, int> ans;

        prev = tr.sum(0, 1);
        if (prev != -1) {
            ++ans[prev];
        }
        for (int i = 1; i < 8000; i++) {
            next = tr.sum(i, i + 1);
            if (next != -1 && next != prev) {
                ++ans[next];
            }
            prev = next;
        }
        for (map<int, int>::const_iterator i = ans.begin(); i != ans.end(); ++i) {
            printf("%d %d\n", i->first, i->second);
        }
        putchar('\n');
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3022058 2008-08-05 08:24:26 Accepted 1610 C++ 00:00.21 916K Re:ReJudge
//

// 2012-09-07 00:55:45 | Accepted | 1610 | C++ | 80 | 180 | watashi | Source
