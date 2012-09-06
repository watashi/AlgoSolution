#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, l;
map<string, int> mp;

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
    vector<bool> m(v.size());

    for (int a = 0, b = v.size(); a < l.size(); a = b, b += v.size()) {
        fill(m.begin(), m.end(), false);
        for (int i = a; i < b && i < l.size(); i++) {
            if (m[l[i]]) {
                return false;
            }
            else {
                m[l[i]] = true;
            }
        }
    }

    return true;
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
//1644795   2008-09-15 15:54:08     Accepted    3045    C++     220     968     watashi

// 2012-09-07 01:58:10 | Accepted | 3045 | C++ | 190 | 892 | watashi | Source
