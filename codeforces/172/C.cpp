#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
multimap<int, int> mp;

int main() {
    int n, m, t, x, y, c;

    scanf("%d%d", &n, &m);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }

    t = 0;
    for (int i = 0; i < (int)v.size(); ) {
        for (int j = 0; j < m && i < (int)v.size(); ++j, ++i) {
            t = max(t, v[i].first);
            mp.insert({v[i].second, i});
        }
        x = 0;
        while (!mp.empty()) {
            y = mp.begin()->first;
            t += y - x;
            x = y;
            c = 0;
            do {
                v[mp.begin()->second].first = t;
                ++c;
                mp.erase(mp.begin());
            } while (!mp.empty() && mp.begin()->first == x);
            t += 1 + c / 2;
        }
        t += x;
    }

    for (auto& i: v) {
        printf("%d ", i.first);
    }

    return 0;
}

