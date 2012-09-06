// 字典序最小有时候倒着求解就可以得到 ^^

#include <cstdio>

int mp[200][200];
int tax[200];

bool tag[200];
bool mark[200];
int mind[200][200];
int pre[200][200];

void reDijkstra(int n, int s, int t, int mind[], int pre[])
{
    int i, k;

    for (i = 1; i <= n; i++) {
        mark[i] = false;
        mind[i] = -1;
        pre[i] = -1;
    }
    mind[t] = 0;
    while(true) {
        k = -1;
        for (i = 1; i <= n; i++)
            if(!mark[i] && mind[i] != -1 && (k == -1 || mind[i] < mind[k]))
                k = i;
        if(k == -1)
            break;
        mark[k] = true;
        for (i = 1; i <= n; i++) {
            if(mark[i] || mp[i][k] == -1)
                continue;
            if(mind[i] == -1) {
                mind[i] = mp[i][k] + mind[k];
                pre[i] = k;
            }
            else if(mind[i] > mp[i][k] + mind[k]) {
                mind[i] = mp[i][k] + mind[k];
                pre[i] = k;
            }
            else if(mind[i] == mp[i][k] + mind[k] && k < pre[i]) {
                pre[i] = k;
            }
        }
    }
}

int main(void)
{
    int n, s, t, p;

    while(scanf("%d", &n) != EOF && n > 0) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &mp[i][j]);
        for (int i = 1; i <= n; i++) {
            tag[i] = false;
            scanf("%d", &tax[i]);
            for (int j = 1; j <= n; j++)
                if(mp[i][j] != -1)
                    mp[i][j] += tax[i];
        }
        while(scanf("%d%d", &s, &t) != EOF && s > 0 && t > 0) {
            if(!tag[t]) {
                tag[t] = true;
                reDijkstra(n, s, t, mind[t], pre[t]);
            }
            p = mind[t][s];
            if(s != t)
                p -= tax[s];
            printf("From %d to %d :\n", s, t);
            printf("Path: %d", s);
            while(s != t)
                printf("-->%d", s = pre[t][s]);
            printf("\nTotal cost : %d\n\n", p);
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2800747 2008-03-24 20:25:28 Accepted 1456 C++ 00:00.01 864K わたし

// 2012-09-07 00:49:57 | Accepted | 1456 | C++ | 0 | 648 | watashi | Source
