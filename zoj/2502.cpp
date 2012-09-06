#include <map>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char buf[108];

bool mat[100][100], tmp[2][100][100];
bool x[101], y[101];

int first1(int x)
{
    int ret = 30;

    while((x & (1 << ret)) == 0)
        --ret;

    return ret;
}

void copy(const int n, bool t[100][100], const bool s[100][100])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t[i][j] = s[i][j];
}

void mul(const int n, const bool a[100][100], const bool b[100][100], bool ret[100][100])
{
    int t;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            t = 0;
            for (int k = 0; k < n; k++)
                if(a[i][k] & b[k][j])
                    ++t;
            ret[i][j] = (t & 1);
        }
    // if(a && b) x = !x; -> TLE
}

int main(void)
{
    int re;
    int n, t, m, a, b;
    map<string, int> mp;
    map<string, int>::iterator it;

    scanf("%d", &re);
    while(re--) {
        mp.clear();
        scanf("%d%d", &n, &t);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = false;
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            it = mp.find(buf);
            if(it == mp.end()) {
                a = (int)mp.size();
                mp.insert(make_pair((string)buf, a));
            }
            else {
                a = it->second;
            }
            scanf("%d%d", &b, &m);
            x[a] = (b & 1);
            for (int j = 0; j < m; j++) {
                scanf("%s", buf);
                it = mp.find(buf);
                if(it == mp.end()) {
                    b = (int)mp.size();
                    mp.insert(make_pair((string)buf, b));
                }
                else {
                    b = it->second;
                }
                mat[b][a] = true;
            }
        }
        for (int i = 0; i < n; i++)
            mat[i][i] = !mat[i][i];

        if(t == 1) {
            printf("%d\n", count(x, x + n, true));
        }
        else {
            --t;
            a = 0;
            b = 1;
            copy(n, tmp[a], mat);
            for (int i = first1(t) - 1; i >= 0; i--) {
                mul(n, tmp[a], tmp[a], tmp[b]);
                swap(a, b);
                if(t & (1 << i)) {
                    mul(n, mat, tmp[a], tmp[b]);
                    swap(a, b);
                }
            }
            for (int i = 0; i < n; i++) {
                y[i] = false;
                for (int j = 0; j < n; j++)
                    if(x[j] & tmp[a][i][j])
                        y[i] = !y[i];
            }
            printf("%d\n", count(y, y + n, true));
        }
    }

    return 0;
}
//2875270   2008-04-27 21:07:05     Accepted    2502    C++     00:00.81    872K    Re:ReJudge

// 2012-09-07 01:25:07 | Accepted | 2502 | C++ | 270 | 208 | watashi | Source
