#include <map>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
    int ri = 0, t;

    while(scanf("%d", &t) != EOF && t) {
        printf("Scenario #%d\n", ++ri);
        map<int, int> team;
        map<int, int> id;
        for (int i = 0; i < t; i++) {
            id.insert(make_pair(i, -1));
            int n;
            scanf("%d", &n);
            while(n--) {
                int p;
                scanf("%d", &p);
                team.insert(make_pair(p, i));
            }
        }
        vector<queue<int> > tq;
        int begin, end;
        char cmd[10];
        begin = end = 0;
        while(scanf("%s", cmd) != EOF && *cmd != 'S') {
            if (*cmd == 'E') {
                int p;
                scanf("%d", &p);
                int t = team[p];
                int q = id[t];
                if(q < begin){
                    q = (id[t] = end++);
                    queue<int> tmp;
                    tmp.push(p);
                    tq.push_back(tmp);
                } else {
                    tq[q].push(p);
                }
            } else {
                printf("%d\n", tq[begin].front());
                tq[begin].pop();
                if(tq[begin].empty()) begin++;
            }
        }
        putchar('\n');
    }
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2721255   2008-01-07 22:47:00     Accepted    1948    C++     00:00.22    1944K   わたし


/*
ORZ
Rank    Submit time     Run time    Run memory      Language    User
1   2006-10-02 20:09:53     00:00.11    8628K   C++     AlPacino
2   2007-01-19 22:32:09     00:00.12    8620K   C   翔
3   2007-10-17 21:36:25     00:00.13    8596K   C++     m_m
4   2006-03-17 07:54:56     00:00.14    8232K   FPC     ÅÆÇ
5   2006-03-17 07:55:21     00:00.14    8232K   FPC     SHiVa
6   2006-10-22 22:42:21     00:00.14    8260K   C++     UniThunder
7   2005-10-09 09:17:10     00:00.15    1972K   C++     wangqingfu
*/

// 2012-09-07 04:44:25 | Accepted | 1948 | C++ | 90 | 1772 | watashi | Source
