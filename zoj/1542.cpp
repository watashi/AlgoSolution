#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

class DisjointSet
{
public:
    DisjointSet(int asize)
    {
        p = new int[asize];
        c = new int[asize];
        for (int i = 0; i < asize; i++) {
            p[i] = i;
            c[i] = 1;
        }
    }
    ~DisjointSet()
    {
        delete[] p;
        delete[] c;
    }
    int size() const
    {
        return sizeof(p) / sizeof(int);
    }
    int root(int i) const
    {
        if (p[i] == i) {
            return i;
        }
        else {
            return p[i] = root(p[i]);
        }
    }
    int count(int i) const
    {
        return c[root(i)];
    }
    void set_friend(int i, int j)
    {
        i = root(i);
        j = root(j);
        if (i != j) {
            c[j] += c[i];
            p[i] = j;
        }
    }
private:
    mutable int *p;
    int *c;
};

pair<int, pair<int, int> > e[15000];

int main(void)
{
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &e[i].second.first, &e[i].second.second, &e[i].first);
        }
        sort(e, e + m);

        DisjointSet st(n + 1);

        for (int i = 0; i < m; i++) {
            st.set_friend(e[i].second.first, e[i].second.second);
            if (st.count(n) == n) {
                printf("%d\n%d\n", e[i].first, i + 1);
                for (int j = 0; j <= i; j++) {
                    printf("%d %d\n", e[j].second.first, e[j].second.second);
                }
                break;
            }
        }
    }

    return 0;
}

// Run ID   Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
// 2958055  2008-06-28 21:07:40     Accepted    1542    C++     00:00.18    624K    Re:ReJudge

// 2012-09-07 00:53:12 | Accepted | 1542 | C++ | 50 | 356 | watashi | Source
