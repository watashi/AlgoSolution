#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

template<int MAXN>
struct DisjointSet
{
    int p[MAXN];
    void clear(int n)
    {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int root(int x)
    {
        if (p[x] == x) {
            return x;
        }
        else {
            return p[x] = root(p[x]);
        }
    }
    void set_friend(int i, int j)
    {
        i = root(i);
        j = root(j);
        p[i] = j;
    }
    bool is_friend(int i, int j)
    {
        return root(i) == root(j);
    }
};

struct Ins
{
    int lab, ins, dst;
    bool read()
    {
        static char buf[128];

        scanf("%s", buf);
        if (strcmp(buf, "END") == 0) {
            return false;
        }
        sscanf(buf, "%d", &lab);
        scanf("%s", buf);
        if (*buf == 'R') {
            ins = (buf[3] == '1');
        }
        else {
            ins = 2 + (buf[0] == 'B');
            scanf("%d", &dst);
        }
        return true;
    }
};

DisjointSet<20002> ds;
int n[2];
Ins ins[2][10001];
map<int, int> mp[2];
bool flag;

void gao(int i, int j)
{
    if (!flag || ds.is_friend(i, n[0] + j)) {
        return;
    }
    else if (ins[0][i].ins <= 1 && ins[1][j].ins <= 1) {
        if (ins[0][i].ins != ins[1][j].ins) {
            flag = false;
        }
    }
    else if (ins[0][i].ins == 2){
        int ni = mp[0][ins[0][i].dst];

        ds.set_friend(i, ni);
        gao(ni, j);
    }
    else if (ins[1][j].ins == 2) {
        int nj = mp[1][ins[1][j].dst];

        ds.set_friend(n[0] + j, n[0] + nj);
        gao(i, nj);
    }
    else if (ins[0][i].ins <= 1) {
        gao(i, j + 1);
        gao(i, mp[1][ins[1][j].dst]);
    }
    else if (ins[1][j].ins <= 1) {
        gao(i + 1, j);
        gao(mp[0][ins[0][i].dst], j);
    }
    else {
        gao(i + 1, j + 1);
        gao(mp[0][ins[0][i].dst], mp[1][ins[1][j].dst]);
    }
    /**/
    if (flag) {
        ds.set_friend(i, n[0] + j);
    }
}

// 先缩点再判“树”同构会快很多

int main()
{
    int re;

    scanf("%d", &re);
    while (re--) {
        scanf("%*d");
        for (int i = 0; i < 2; i++) {
            n[i] = 0;
            mp[i].clear();
            while (ins[i][n[i]].read()) {
                mp[i][ins[i][n[i]].lab] = n[i]++;
            }
        }
        ds.clear(n[0] + n[1]);
        flag = true;
        gao(0, 0);
        printf("%d\n", flag ? 1 : 0);
    }

    return 0;
}

/*
Run ID      Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
3048174     2008-08-24 02:00:14     Accepted    3029    C++     00:00.47    1668K   watashi@Zodiac
*/

// 2012-09-07 01:56:31 | Accepted | 3029 | C++ | 200 | 1020 | watashi | Source
