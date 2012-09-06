#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

// 引入并查集可以降低复杂度

struct DisjointSet
{
    int n, *p;
    DisjointSet(int maxsize)
    {
        n = maxsize;
        p = new int[maxsize];
    }
    ~DisjointSet()
    {
        delete[] p;
    }
    void clear(int c)
    {
        for (int i = 0; i < c; i++) {
            p[i] = i;
        }
    }
    int root(int i)
    {
        return (p[i] == i) ? i : p[i] = root(p[i]);
    }
    void set_friend(int i, int j)
    {
        p[root(j)] = root(i);
    }
    bool is_friend(int i, int j)
    {
        return root(i) == root(j);
    }
};

const int UNKNOWN = 0x7FFFFFFF;
//const long long UNKNOWN = 0x7FFFFFFFFFFFFFFFLL;

DisjointSet ds(5005);
int v[5005];    //long long v[5005];
typedef vector<pair<int, int> > EdgeList;   //typedef vector<pair<int, long long> > EdgeList;
EdgeList e[5005];

void gao(int p)
{
    for (EdgeList::const_iterator it = e[p].begin(); it != e[p].end(); ++it) {
        if (v[it->first] == UNKNOWN) {
            v[it->first] = v[p] + it->second;
            gao(it->first);
        }
    }
}

int main(void)
{
    int n, m, q, a, b;
    int s;  //long long s;

    while (scanf("%d%d%d", &n, &m, &q) != EOF) {
        ds.clear(n + 1);
        for (int i = 0; i <= n; i++) {
            v[i] = UNKNOWN;
            e[i].clear();
        }
        while (m--) {
            scanf("%d%d%d\n", &a, &b, &s);
            //scanf("%d%d%lld\n", &a, &b, &s);
            --a;
            ds.set_friend(a, b);
            e[a].push_back(make_pair(b, s));
            e[b].push_back(make_pair(a, -s));
        }
        for (int i = 0; i <= n; i++) {
            if (ds.p[i] == i && v[i] == UNKNOWN) {
                v[i] = 0;
                gao(i);
            }
        }
        while (q--) {
            scanf("%d%d", &a, &b);
            --a;
            if (!ds.is_friend(a, b)) {
                puts("UNKNOWN");
            }
            else {
                printf("%d\n", v[b] - v[a]);
                //printf("%lld\n", v[b] - v[a]);
            }
        }
        putchar('\n');
    }

    return 0;
}

//3022421 2008-08-05 11:40:39 Accepted 2757 C++ 00:00.10 1644K Re:ReJudge

// long long -> int
//
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3022434 2008-08-05 11:44:31 Accepted 2757 C++ 00:00.08 1404K Re:ReJudge
//

// 2012-09-07 01:38:13 | Accepted | 2757 | C++ | 30 | 680 | watashi | Source
