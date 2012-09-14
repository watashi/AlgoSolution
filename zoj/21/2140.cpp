#include <list>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    bool b = false;
    int n;
    pair<int, int> t;

    while (scanf("%d", &n) != EOF && n != 0) {
        list<pair<int, int> > d;
        vector<vector<char> > mp(n, vector<char>(n, '0'));

        if (b) {
            putchar('\n');
        }
        else {
            b = true;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &t.first);
            t.second = i;
            d.push_back(t);
        }
        while (true) {
            d.sort();
            while (!d.empty() && d.front().first == 0) {
                d.pop_front();
            }
            if (d.empty() || d.back().first >= d.size()) {
                break;
            }
            t = d.back();
            d.pop_back();
            for (list<pair<int, int> >::reverse_iterator it = d.rbegin(); t.first > 0; ++it, --t.first) {
                mp[t.second][it->second] = mp[it->second][t.second] = '1';
                --it->first;
            }
        }
        if (d.empty()) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    putchar(mp[i][j]);
                    putchar(j == n - 1 ? '\n' : ' ');
                }
            }
        }
        else {
            puts("~><~");
        }
    }

    return 0;
}

// Run ID   Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
// 1665698  2008-10-13 23:41:09     Accepted    2140    C++     90  176     watashi@Zodiac

// 2012-09-07 01:14:00 | Accepted | 2140 | C++ | 70 | 180 | watashi | Source
