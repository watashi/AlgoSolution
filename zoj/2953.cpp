#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class Team
{
public:
    string name;
    int pt, ct;
    Team(const string& name) : name(name)
    {
        pt = ct = 0;
    }
    bool operator<(const Team& rhs) const
    {
        if(pt < rhs.pt)
            return true;
        else if(pt > rhs.pt)
            return false;
        if(ct == rhs.ct)
            return name < rhs.name;
        else if(pt < 0)
            return ct < rhs.ct;
        else if(pt > 0)
            return ct > rhs.ct;
        else
            return name < rhs.name;
    }
};

vector<Team> rec;

class TeamRef
{
public:
    int id;
    TeamRef(const int id) : id(id)
    {
    }
    bool operator<(const TeamRef& rhs) const
    {
        return rec[id] < rec[rhs.id];
    }
};

vector<TeamRef> rank;

int nh, h[22];
map<string, int> mp;

void show(void)
{
    int p = 0, pt = -1024, n = (int)mp.size(), id;

    sort(rank.begin(), rank.end());
    printf("Place  Name        Score  Holes\n");
    for (int i = 0; i < n; i++) {
        id = rank[i].id;
        if(rec[id].pt > pt) {
            p = i + 1;
            pt = rec[id].pt;
        }
        printf("%5d  %-10s", p, rec[id].name.c_str());
        if(pt == 0)
            printf("  %5d", pt);
        else
            printf("  %+5d", pt);
        if(rec[id].ct == nh)
            printf("  %5s\n", "F");
        else
            printf("  %5d\n", rec[id].ct);
    }
    printf("\n");
}

void insert(const string& name)
{
    int id, pt;
    map<string, int>::iterator it = mp.find(name);

    if(it == mp.end()) {
        id = (int)mp.size();
        mp.insert(make_pair(name, id));
        rec.push_back(Team(name));
        rank.push_back(TeamRef(id));
    }
    else {
        id = it->second;
    }
    scanf("%d", &pt);
    rec[id].pt += pt -= h[rec[id].ct++];
}

const char *SR = "ShowRank", *EOT = "EndOfTournament";

int main(void)
{
    int re;
    char buf[40];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ri++) {
        mp.clear();
        rec.clear();
        rank.clear();
        scanf("%d", &nh);
        for (int i = 0; i < nh; i++)
            scanf("%d", &h[i]);
        printf("Tournament %d\n", ri);
        while(scanf("%s", buf) != EOF) {
            if(!strcmp(buf, EOT))
                break;
            else if(!strcmp(buf, SR))
                show();
            else
                insert(buf);
        }
    }

    return 0;
}

// 2012-09-07 01:49:43 | Accepted | 2953 | C++ | 20 | 180 | watashi | Source
