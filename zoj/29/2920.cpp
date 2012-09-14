#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

class Team
{
public:
    string name;
    int wa[10];
    int cnt, sum;
    vector <pair <int, int> > vp;
    void init(const string& that)
    {
        name = that;
        fill(wa, wa + 10, 0);
        cnt = sum = 0;
        vp.clear();
    }
    void doit(int ti, char id, bool res = false)
    {
        id -= 'A';
        if(wa[id] == -1) return;
        else if(res == false) ++wa[id];
        else {
            vp.push_back(make_pair(ti, wa[id]));
            ++cnt;
            sum += ti + wa[id] * 20;
            wa[id] = -1;
        }
    }
    bool operator<(const Team& that) const
    {
        if(cnt != that.cnt) return cnt > that.cnt;
        if(sum != that.sum) return sum < that.sum;
        for (int i = cnt - 1; i >= 0; i--) {
            if(vp[i].first != that.vp[i].first) return vp[i].first < that.vp[i].first;
            if(vp[i].second != that.vp[i].second) return vp[i].second > that.vp[i].second;
        }
        return name < that.name;
    }
    bool operator==(const Team& that) const
    {
        if(cnt != that.cnt) return false;
        if(sum != that.sum) return false;
        for (int i = cnt - 1; i >= 0; i--)
            if(vp[i].first != that.vp[i].first || vp[i].second != that.vp[i].second) return false;
        return true;
    }
};

Team team[50];
int rank[50];
char buf[50], buff[50];

int main(void)
{
    int re;
    scanf("%d", &re);
    while(re--) {
        int t, r;
        map <string, int> mp;

        scanf("%d%d", &t, &r);
        for (int i = 0; i < t; i++) {
            scanf("%s", buf);
            mp.insert(make_pair((string)buf, i));
            team[i].init(buf);
        }
        for (int i = 0; i < r; i++) {
            int ti;
            char id;

            scanf("%d%s %c%s", &ti, buf, &id, buff);
            team[mp[buf]].doit(ti, id, buff[0] == 'a');
        }
        sort(team, team + t);
        for (int i = 0; i < t; i++) {
            if(i > 0 && team[i] == team[i - 1]) rank[i] = rank[i - 1];
            else rank[i] = i + 1;
            printf("%d %s %d %d\n", rank[i], team[i].name.c_str(), team[i].cnt, team[i].sum);
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2756989 2008-02-21 18:26:51 Accepted 2920 C++ 00:00.12 880K ¤ï¤¿¤·

// 2012-09-07 01:47:23 | Accepted | 2920 | C++ | 40 | 184 | watashi | Source
