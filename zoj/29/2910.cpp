#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

class Team
{
public:
    string name;
    int id, cnt, win, tie, lose, goal, diff, pt;
    void init(const string& that, int aid)
    {
        name = that;
        id = aid;
        cnt = win = tie = lose = goal = diff = pt = 0;
    }
    void doit(int a, int b)
    {
        ++cnt;
        goal += a;
        diff += a - b;
        if(a > b) { pt += 3; ++win; }
        else if(a == b) { ++pt; ++tie; }
        else ++lose;
    }
    bool operator<(const Team& that) const
    {
        if(pt != that.pt) return pt > that.pt;
        if(diff != that.diff) return diff > that.diff;
        if(goal != that.goal) return goal > that.goal;
        if(win != that.win) return win > that.win;
        return id > that.id;
    }
};

map <string, int> mp;
Team team[80];
pair <int, int> rec[80][80];

inline void showmulti(int cnt, char ch = ' ')
{
    while(cnt--) putchar(ch);
}

inline void showline(int maxl, int n)
{
    putchar('+');
    showmulti(maxl, '-');
    putchar('+');
    while(n--) printf("---+");
    putchar('\n');
}

int main(void)
{
    int n, m, a, b, l, r, maxl;
    int rankl, cntl, winl, tiel, losel, scorel, ptl;
    char buf[80], buff[80];

    while(scanf("%d", &n) != EOF && n > 0) {
        mp.clear();
        maxl = -1;
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            maxl = max(maxl, (int)strlen(buf));
            mp.insert(make_pair(buf, i));
            team[i].init(buf, i);
            for (int j = 0; j < n; j++)
                rec[i][j] = make_pair(-1, -1);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%s - %s %d:%d", buf, buff, &a, &b);
            l = mp[buf];
            r = mp[buff];
            team[l].doit(a, b);
            team[r].doit(b, a);
            rec[l][r] = make_pair(a, b);
        }
        printf("RESULTS:\n");
        showline(maxl, n);
        putchar('|');
        showmulti(maxl);
        for (int j = 0; j < n; j++)
            printf("|%-3s", team[j].name.substr(0, 3).c_str());
        printf("|\n");
        showline(maxl, n);
        for (int i = 0; i < n; i++) {
            printf("|%s", team[i].name.c_str());
            showmulti(maxl - team[i].name.length());
            for (int j = 0; j < n; j++) {
                if(i == j) printf("| X ");
                else if(rec[i][j].first < 0) printf("|   ");
                else printf("|%d:%d", rec[i][j].first, rec[i][j].second);
            }
            printf("|\n");
            showline(maxl, n);
        }
        printf("\nSTANDINGS:\n----------\n");
        sort(team, team + n);
        rankl = (n < 10) ? 1 : 2;
        cntl = winl = tiel = losel = scorel = ptl = -1;
        for (int i = 0; i < n; i++) {
            sprintf(buf, "%d", team[i].cnt);
            cntl = max(cntl, (int)strlen(buf));
            sprintf(buf, "%d", team[i].win);
            winl = max(winl, (int)strlen(buf));
            sprintf(buf, "%d", team[i].tie);
            tiel = max(tiel, (int)strlen(buf));
            sprintf(buf, "%d", team[i].lose);
            losel = max(losel, (int)strlen(buf));
            sprintf(buf, "%d:%d", team[i].goal, team[i].goal - team[i].diff);
            scorel = max(scorel, (int)strlen(buf));
            sprintf(buf, "%d", team[i].pt);
            ptl = max(ptl, (int)strlen(buf));
        }
        for (int i = 0; i < n; i++) {
            sprintf(buf, "%d", i + 1);
            showmulti(rankl - strlen(buf));
            printf("%s. %s", buf, team[i].name.c_str());
            showmulti(maxl - team[i].name.length() + 1);
            sprintf(buf, "%d", team[i].cnt);
            showmulti(cntl - strlen(buf));
            printf("%s ", buf);
            sprintf(buf, "%d", team[i].win);
            showmulti(winl - strlen(buf));
            printf("%s ", buf);
            sprintf(buf, "%d", team[i].tie);
            showmulti(tiel - strlen(buf));
            printf("%s ", buf);
            sprintf(buf, "%d", team[i].lose);
            showmulti(losel - strlen(buf));
            printf("%s ", buf);
            sprintf(buf, "%d:%d", team[i].goal, team[i].goal - team[i].diff);
            showmulti(scorel - strlen(buf));
            printf("%s", buf);
            sprintf(buf, "%d", team[i].pt);
            showmulti(ptl - strlen(buf));
            printf(" %s\n", buf);
        }
        putchar('\n');
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2751257 2008-02-14 22:22:47 Accepted 2910 C++ 00:00.01 900K ¤ï¤¿¤·

// 2012-09-07 01:46:40 | Accepted | 2910 | C++ | 0 | 232 | watashi | Source
