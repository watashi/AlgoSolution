#include <deque>
#include <cstdio>
#include <algorithm>
using namespace std;

deque<int> e[5000];
bool s[5000];
int c[5000][51], d[5000];

int main(void)
{
    int m, n, k;

    while(scanf("%d%d%d", &m, &n, &k) != EOF) {
        for (int i = 0; i < n; i++) {
            int a, b;

            d[i] = -1;
            e[i].clear();
            scanf("%d%d", &a, &b);
            s[--a] = (b == 1);
        }
        while(m--) {
            int a, b;

            scanf("%d%d", &a, &b);
            --a;
            --b;
            e[a].push_front(b);
            e[b].push_front(a);
        }

        deque<int> q;
        q.push_back(0);
        d[0] = 0;
        fill(c[0], c[0] + k + 1, 0);
        fill(c[n - 1], c[n - 1] + k + 1, 0);
        c[0][s[0]] = 1;
        while(q.empty() == false) {
            int f = q.front();
            q.pop_front();
            for (deque<int>::iterator it = e[f].begin(); it != e[f].end(); ++it) {
                int t = *it;
                if(d[t] == -1) {
                    d[t] = d[f] + 1;
                    if(s[t]) {
                        for (int i = 1; i <= k; i++)
                            c[t][i] = c[f][i - 1];
                    }
                    else {
                        for (int i = 0; i <= k; i++)
                            c[t][i] = c[f][i];
                    }
                    q.push_back(t);
                }
                else if(d[t] == d[f] + 1) {
                    if(s[t]) {
                        for (int i = 1; i <= k; i++)
                            c[t][i] += c[f][i - 1];
                    }
                    else {
                        for (int i = 0; i <= k; i++)
                            c[t][i] += c[f][i];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= k; i++)
            ans += c[n - 1][i];
        if(ans > 0) printf("%d\n", ans);
        else printf("Impossible!\n");
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2762286 2008-02-26 22:49:29 Accepted 2923 C++ 00:01.50 10648K ¤ï¤¿¤·

// 2012-09-07 01:47:41 | Accepted | 2923 | C++ | 440 | 11692 | watashi | Source
