#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertex{
    int v;
    int e;
    struct vertex* next;
}Node;

Node lt[10000];
int mk[10000];
int n;
double ans;

int bfs(int v)
{
    int cnt, res = 0;
    Node *p;

    for (p = lt[v].next; p != NULL; p = p -> next) {
        if(!mk[p -> v]) {
            mk[p -> v] = 1;
            cnt = bfs(p -> v);
            ans += (double)p -> e * cnt * (n - cnt);
            res += cnt;
        }
    }
    res++;
    return res;
}

void clear(Node *p)
{
    if(p != NULL) {
        clear(p -> next);
        free(p);
    }
}

void insert(Node *p, int v, int e)
{
    Node *next = p -> next;
    Node *cur = (Node *)malloc(sizeof(Node));
    cur -> v = v;
    cur -> e = e;
    p -> next = cur;
    cur -> next = next;
}

int main()
{
    int t;
    int i, j, k, m;

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            lt[i].next = NULL;
            mk[i] = 0;
        }
        m = n - 1;
        while(m--) {
            scanf("%d%d%d", &i, &j, &k);
            mk[i]++;
            mk[j]++;
            insert(&lt[i], j, k);
            insert(&lt[j], i, k);
        }
        for (i = 0; i < n; i++)
            if (mk[i] == 1) break;
        memset(mk, 0, n * sizeof(int));
        mk[i] = 1;
        ans = 0;
        bfs(i);
        printf("%.4lf\n", 2 * ans / n / (n - 1));
        for (i = 0; i < n; i++)
            clear(lt[i].next);
    }
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2756975 2008-02-21 18:18:17 Accepted 2912 C++ 00:00.43 1208K ¤ï¤¿¤·

// 2012-09-07 01:46:46 | Accepted | 2912 | C++ | 130 | 600 | watashi | Source
