#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

template<class T, class Pred>
size_t LIS(size_t n, T* a, Pred p = less<T>(), int* pre = NULL, int* last = NULL)
{
    vector<size_t> b;

    b.push_back(0);
    if (pre != NULL) {
        pre[0] = -1;
    }
    for (size_t i = 1; i < n; i++) {
        if (p(a[b.back()], a[i])) {
            if (pre != NULL) {
                pre[i] = b.back();
            }
            b.push_back(i);
        }
        else {
            size_t l = 0, r = b.size(), m;

            while (l < r) {
                m = (l + r) >> 1;
                if (p(a[b[m]], a[i])) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            if (pre != NULL) {
                pre[i] = (r == 0) ? -1 : b[r - 1];
            }
            b[r] = i;
        }
    }
    if (last != NULL) {
        *last = b.back();
    }

    return b.size();
}

struct Member
{
    int s, b, p;
};

inline bool pr1(const Member& lhs, const Member& rhs)
{
    if (lhs.s != rhs.s) {
        return lhs.s < rhs.s;
    }
    else {
        return lhs.b > rhs.b;
    }
}

inline bool pr2(const Member& lhs, const Member& rhs)
{
    return lhs.b < rhs.b;
}

int pre[100000];
vector<Member> v;

void gao(int i)
{
    if (pre[i] == -1) {
        printf("%d\n", v[i].p);
    }
    else {
        printf("%d ", v[i].p);
        gao(pre[i]);
    }
}

int main(void)
{
    int re, n, t;

    scanf("%d", &re);
    while (re--) {
        scanf("%d", &n);
        v.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &v[i].s, &v[i].b);
            v[i].p = i + 1;
        }
        sort(v.begin(), v.end(), pr1);
        printf("%u\n", LIS(v.size(), &v[0], pr2, pre, &t));
        gao(t);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3023257 2008-08-05 18:17:54 Accepted 2319 C++ 00:02.85 4364K Re:ReJudge
//

// 2012-09-07 01:18:47 | Accepted | 2319 | C++ | 850 | 3620 | watashi | Source
