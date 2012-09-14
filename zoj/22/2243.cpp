/*
此问题还有一种最快的方法。考虑到对所有的输入节点做针对key的排序后，得到的数组为cartesian tree的中序遍历。

1. 现在我们从左到右，一边顺序遍历数组，一边建立cartesian tree。
2. 假设我们已经遍历到数组的第i个元素，并相应建立了有i个节点组成的cartesian tree，那么第i+1个节点必定在由i+1个节点组成的cartesian tree的最右路径的最右端点。
3. 我们原i几点的cartesian tree的最右路径的最右端点出发往上查找第一个priority比i+1节点大的节点，如果找到了，就把i+1节点的左子树设为那个节点的右子树，把那个节点的右子树设为i+1节点。如果找不到，则把i+1节点的左子树设为原树的根，并把i+1节点设为新根。
4. 需要主意的是，必须从下到上搜索最右路径，而不是从上到下。因为从上到下会出现O(n!)的复杂度，而从下到上的过程中，没个几点最多被走过一次，因为被走过的节点必被设为某个点的左子树，不再可能出现在最右路径中，所有有O(n)的复杂度。

Rank Submit time Run time Run memory Language User
1 2006-07-10 13:00:21 00:00.36 3780K C++ SHiVa
2 2006-07-10 12:59:55 00:00.37 3776K C++ ???
3 2007-06-09 10:40:22 00:00.38 4148K C++ Fire!
4 2008-04-13 15:57:50 00:00.41 3160K C++ leokan
*/





#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int a[16][65536][2];

void reset()
{
    for (int l = 1; (1 << l) <= n; l++) {
        int d = (1 << (l - 1)), dd = (1 << l);
        for (int i = 0; i + dd <= n; i++) {
            if (a[l - 1][i][0] >= a[l - 1][i + d][0]) {
                a[l][i][0] = a[l - 1][i][0];
                a[l][i][1] = a[l - 1][i][1];
            }
            else {
                a[l][i][0] = a[l - 1][i + d][0];
                a[l][i][1] = a[l - 1][i + d][1];
            }
        }
    }
}

int lg(int x)
{
    int ret = 0;

    while ((1 << ret) <= x) {
        ++ret;
    }

    return ret - 1;
}

//[l, r)
int query_index(int l, int r)
{
    int d = lg(r - l);

    if (a[d][l][0] >= a[d][r - (1 << d)][0]) {
        return a[d][l][1];
    }
    else {
        return a[d][r - (1 << d)][1];
    }
}

/******************************************************************/

vector<pair<string, int> > v;

void gao(int l, int r)
{
    if (l == r) {
        return;
    }
    int m = query_index(l, r);
    putchar('(');
    gao(l, m);
    printf("%s/%d", v[m].first.c_str(), v[m].second);
    gao(m + 1, r);
    putchar(')');
}

int main(void)
{
    int p;
    static char buf[256];

    for (int i = 0; i < 65536; i++) {
        a[0][i][1] = i;
    }
    while (scanf("%d", &n) != EOF && n > 0) {
        v.clear();
        for (int i = 0; i < n; i++) {
            scanf(" %[a-z]/%d", buf, &p);
            v.push_back(make_pair((string)buf, p));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            a[0][i][0] = v[i].second;
        }
        reset();
        gao(0, n);
        putchar('\n');
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3018568 2008-08-02 19:40:26 Accepted 2243 C++ 00:01.21 13080K Re:ReJudge

// 2012-09-07 01:16:56 | Accepted | 2243 | C++ | 380 | 10004 | watashi | Source
