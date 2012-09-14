#include <map>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

map<string, int> mp;
vector<vector<int> > tr;

inline int zaigao(const string& s)
{
    int ret;
    map<string, int>::iterator it = mp.find(s);

    if (it == mp.end()) {
        ret = (int)mp.size();
        mp[s] = ret;
        tr.push_back(vector<int>());
    }
    else {
        ret = it->second;
    }

    return ret;
}

inline void gao(const string& a, const string& b)
{
    tr[zaigao(b)].push_back(zaigao(a));
}

int time_stamp;
vector<pair<int, int> > ts;

void dfs(int i)
{
    ts[i].first = time_stamp++;
    for (vector<int>::const_iterator it = tr[i].begin(); it != tr[i].end(); ++it) {
        dfs(*it);
    }
    ts[i].second = time_stamp++;
}

bool judge(const string& a, const string& b)
{
    int i = mp[a], j = mp[b];

    return ts[i].first >= ts[j].first && ts[i].second <= ts[j].second;
}

int main(void)
{
    bool blank = false;
    char a[256], b[256];
    int ri = 0, n, m;

    while (scanf("%s%d", a, &n) != EOF) {
        mp.clear();
        tr.clear();
        tr.reserve(n + 1);
        zaigao(a);
        for (int i = 0; i < n; i++) {
            scanf("%s%s", a, b);
            gao(a, b);
        }
        ts.resize(tr.size());
        dfs(0);

        scanf("%d", &m);
        if (blank) {
            printf("\n");
        }
        else {
            blank = true;
        }
        printf("Project %d\n", ++ri);
        while(m--) {
            scanf("%s%s", a, b);
            puts(judge(a, b) ? "Yes" : "No");
        }
    }

    return 0;
}

//Run ID    Submit time     Language    Run time    Run memory      User Name
//638   2008-06-21 15:02:38     C++     00:01:78    4188K   Re:ReJudge

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2954369   2008-06-22 03:15:31     Accepted    2999    C++     00:01.69    3696K   Re:ReJudge

// 2012-09-07 01:53:40 | Accepted | 2999 | C++ | 860 | 2896 | watashi | Source
