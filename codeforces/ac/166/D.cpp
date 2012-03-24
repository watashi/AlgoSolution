#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

struct Shoe {
    int c, i, j;
    vector<int> v;
} shoe;

map<int, Shoe> mp;

int main() {
    int n, m, a, b;
    long long ans = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        shoe.c = a;
        shoe.i = i;
        shoe.j = -1;
        mp[b] = shoe;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        vector<int> e;
        if (mp.count(b) > 0 && mp[b].c <= a) {
            e.push_back(b);
        }
        if (mp.count(b + 1) > 0 && mp[b + 1].c <= a) {
            e.push_back(b + 1);
        }
        if (e.size() == 1) {
            mp[e[0]].j = i;
        } else if (e.size() == 2) {
            mp[e[0]].v.push_back(i);
        }
    }

    for (auto& i: mp) {
        if (i.second.v.size() >= 2) {
            i.second.j = i.second.v[0];
            mp[i.first + 1].j = i.second.v[1];
            i.second.v.clear();
        }
    }

    queue<int> q;
    for (auto& i: mp) {
        if (i.second.j != -1) {
            q.push(i.first);
        }
    }
    while (!q.empty()) {
        a = q.front();
        q.pop();
        b = a + 1;
        if (mp.count(b) > 0 && mp[b].j == -1 && !mp[a].v.empty()) {
            mp[b].j = mp[a].v[0];
            mp[a].v.clear();
            q.push(b);
        }
        b = a - 1;
        if (mp.count(b) > 0 && mp[b].j == -1 && !mp[b].v.empty()) {
            mp[b].j = mp[b].v[0];
            mp[b].v.clear();
            q.push(b);
        }
    }

    for (auto& i: mp) {
        if (i.second.j != -1) {
            continue;
        }
        vector<int> x, y;
        a = i.first;
        /*
        while (mp.count(a - 1) > 0 && !mp[a - 1].v.empty()) {
           --a;
        }
        */
        b = a;
        while (!mp[b].v.empty()) {
            x.push_back(b);
            y.push_back(mp[b].v[0]);
            mp[b].v.clear();
            ++b;
        }
        x.push_back(b);
        x.erase(min_element(x.begin(), x.end(), [&mp](int i, int j){ return mp[i].c < mp[j].c; }));
        if (mp[a].c < mp[b].c) {
            ++a;
        } else {
            --b;
        }
        for (int i = 0; i < (int)y.size(); ++i) {
            mp[x[i]].j = y[i];
        }
    }

    ans = 0;
    vector<pair<int, int> > w;
    for (const auto& i: mp) {
        if (i.second.j != -1) {
            ans += i.second.c;
            w.push_back({i.second.i, i.second.j});
        }
    }
    cout << ans << endl;
    cout << w.size() << endl;
    for (const auto& p: w) {
        cout << p.second + 1 << " " << p.first + 1 << endl;
    }

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1405988 	Mar 24, 2012 9:19:21 PM 	watashi 	166D - Shoe Store 	GNU C++0x 	Accepted 	810 ms 	10000 KB
