#include <list>
#include <cstdio>
#include <algorithm>
using namespace std;

list<int> el[100];
int p, c2s[100], n, s2c[300];

int Hungary(int x, int y, int x2y[], int y2x[], list<int> xe[])
{
    bool *mark = new bool[x];
    int *temp = new int[y];
    int a, b, p, t, *q = new int[x];
    int res = 0;

    fill(x2y, x2y + x, -1);
    fill(y2x, y2x + y, -1);
    for (int i = 0; i < x; i++) {
        fill(mark, mark + x, false);
        fill(temp, temp + y, -1);
        mark[i] = true;
        q[0] = i;
        p = 0;
        t = 1;
        while(p < t) {
            for (list<int>::iterator itr = xe[q[p]].begin(); itr != xe[q[p]].end(); ++itr) {
                b = *itr;
                if(temp[b] != -1) continue;
                else temp[b] = q[p];
                a = y2x[b];
                if(a == -1) {
                    p = t;
                    break;
                }
                else if(mark[a] == false) {
                    mark[a] = true;
                    q[t++] = a;
                }
            }
            ++p;
        }
        if(p > t) {
            while(b != -1) {
                y2x[b] = temp[b];
                a = x2y[temp[b]];
                x2y[temp[b]] = b;
                b = a;
            }
            ++res;
        }
    }

    delete[] mark;
    delete[] temp;
    delete[] q;
    return res;
}

int main(void)
{
    int re;
    scanf("%d", &re);
    while(re--) {
        scanf("%d%d", &p, &n);
        int m, t;
        for (int i = 0; i < p; i++) {
            el[i].clear();
            scanf("%d", &m);
            while(m--) {
                scanf("%d", &t);
                el[i].push_front(t - 1);
            }
        }
        puts(Hungary(p, n, c2s, s2c, el) == p ? "YES" : "NO");
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2747460 2008-02-10 01:49:46 Accepted 1140 C++ 00:00.66 1316K ¤ï¤¿¤·

// 2012-09-07 00:38:47 | Accepted | 1140 | C++ | 300 | 580 | watashi | Source
