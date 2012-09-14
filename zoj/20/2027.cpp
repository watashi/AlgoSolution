#include <map>
#include <string>
#include <cstdio>
using namespace std;
const int MAXN = 202;
const int inf = 999999999;
void Dijkstra(int n, int s, int mp[MAXN][MAXN], int mind[MAXN])
{
    bool mark[MAXN];
    fill(mark, mark + MAXN, false);
    fill(mind, mind + MAXN, inf);
    mind[s] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if(!mark[j] && (k == -1 || mind[j] < mind[k])) k = j;
        mark[k] = true;
        for (int j = 0; j < n; j++)
            if(!mark[j] && mind[k] + mp[k][j] < mind[j]) mind[j] = mind[k] + mp[k][j];
    }
}

void reDijkstra(int n, int t, int mp[MAXN][MAXN], int mind[MAXN])
{
    bool mark[MAXN];
    fill(mark, mark + MAXN, false);
    fill(mind, mind + MAXN, inf);
    mind[t] = 0;
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++)
            if(!mark[j] && (k == -1 || mind[j] < mind[k])) k = j;
        mark[k] = true;
        for (int j = 0; j < n; j++)
            if(!mark[j] && mp[j][k] + mind[k] < mind[j]) mind[j] = mp[j][k] + mind[k];
    }
}

int main()
{
    char buf[12];
    string tmp;

    while(scanf("%s", buf) != EOF) {
        map<string, int> mp;
        int s, t;
        tmp = (string)buf;
        if (mp.find(tmp) != mp.end()) s = mp[tmp];
        else {s = mp.size(); mp.insert(make_pair(tmp, mp.size()));}
        scanf("%s", buf);
        tmp = (string)buf;
        if (mp.find(tmp) != mp.end()) t = mp[tmp];
        else {t = mp.size(); mp.insert(make_pair(tmp, mp.size()));}

        int n;
        scanf("%d", &n);
        int board[MAXN][MAXN];
        fill (board[0], board[MAXN], inf);
        while(n--) {
            int i;
            scanf("%s", buf);
            tmp = (string)buf;
            if (mp.find(tmp) != mp.end()) i = mp[tmp];
            else {i = mp.size(); mp.insert(make_pair(tmp, mp.size()));}
            int j;
            scanf("%s", buf);
            tmp = (string)buf;
            if (mp.find(tmp) != mp.end()) j = mp[tmp];
            else {j = mp.size(); mp.insert(make_pair(tmp, mp.size()));}
            int k;
            scanf("%d", &k);
            board[i][j] = k; //是单向 无不同权重边
        }

        int minds[MAXN];
        Dijkstra(mp.size(), s, board, minds);
        int mindt[MAXN];
        reDijkstra(mp.size(), t, board, mindt);

        int ans = inf;
        for (unsigned int i = 0; i < mp.size(); i++)
            for (unsigned int j = 0; j < mp.size(); j++)
                if(board[i][j] < inf && minds[i] + mindt[j] < ans) ans = minds[i] + mindt[j];
        printf("%d\n", ans);
    }
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2721930   2008-01-09 08:48:55     Accepted    2027    C++     00:00.01    1004K   わたし

// 2012-09-07 01:10:45 | Accepted | 2027 | C++ | 0 | 180 | watashi | Source
