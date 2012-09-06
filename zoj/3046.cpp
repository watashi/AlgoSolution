#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, l;
map<string, int> mp;

struct group
{
    vector<int> c;
    int cc;
    group(int n) : c(n, 0)
    {
        cc = 0;
    }
    void push(int x)
    {
        if (c[x] > 0) {
            ++cc;
        }
        ++c[x];
    }
    void pop(int x)
    {
        if (c[x] > 1) {
            --cc;
        }
        --c[x];
    }
};

void addit(const string& str)
{
    map<string, int>::iterator it = mp.find(str);
    int id;

    if (it == mp.end()) {
        id = mp.size();
        mp[str] = id;
        v.push_back(1);
    }
    else {
        id = it->second;
        ++v[id];
    }
    l.push_back(id);
}

bool isshuffle()
{
    bool flag;
    int m = l.size() / v.size(), r;
    vector<group> vg(m + 2, group(v.size()));

    flag = true;
    for (int i = 1; i < vg.size(); i++) {
        int a = (i - 1) * v.size(), b = min(i * v.size(), l.size());
        for (int j = a; j < b; j++) {
            vg[i].push(l[j]);
        }
        if (vg[i].cc > 0) {
            flag = false;
        }
    }
    for (int k = 0; k < v.size() && !flag; k++) {
        for (int i = 0; i < vg.size(); i++) {
            int x = i * v.size() + k;
            if (x >= l.size()) {
                break;
            }
            vg[i].push(l[x]);
            vg[i + 1].pop(l[x]);
        }
        flag = true;
        for (int i = 0; i < vg.size(); i++) {
            if (vg[i].cc > 0) {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

char buf[128];

int main(void)
{
    int n;

    while (scanf("%d", &n) != EOF) {
        gets(buf);
        v.clear();
        l.clear();
        mp.clear();
        for (int i = 0; i < n; i++) {
            gets(buf);
            addit(buf);
        }

        puts(isshuffle() ? "Either" : "Random");
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1644796   2008-09-15 15:55:21     Accepted    3046    C++     260     1144    watashi

// 2012-09-07 01:58:16 | Accepted | 3046 | C++ | 210 | 1064 | watashi | Source
