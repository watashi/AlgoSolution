#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int main() {
    bool yellow[MAXN], red[MAXN], record[MAXN];
    int miss[MAXN];
    int a, b;
    char buf[80];
    vector<pair<int, int> > todo[10], ans;

    while (scanf("%s", buf) != EOF) {
        for (int i = 1; i <= 7; ++i) {
            todo[i].clear();
        }
        while (strcmp(buf, "END") != 0) {
            assert(strcmp(buf, "Match") == 0);
            scanf("%d", &a);
            assert(1 <= a && a <= 7);
            while (scanf("%d%s", &b, buf) == 2) {
                todo[a].push_back(make_pair(b, buf[0] == 'y' ? 1 : 2));
                assert(0 <= b && b < MAXN);
                assert(buf[0] == 'y' || buf[0] == 'r');
            }
            scanf("%s", buf);
        }

        ans.clear();
        fill(miss, miss + MAXN, 0);
        fill(record, record + MAXN, false);
        fill(yellow, yellow + MAXN, false);
        fill(red, red + MAXN, false);
        for (int i = 1; i <= 7; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                if (red[j]) {
                    ++miss[j];
                }
                if (yellow[j]) {
                    if (record[j]) {
                        ++miss[j];
                        record[j] = false;
                    } else {
                        record[j] = true;
                    }
                }
            }

            if (i == 6) {
                fill(record, record + MAXN, false);
            }
            fill(yellow, yellow + MAXN, false);
            fill(red, red + MAXN, false);
            for (vector<pair<int, int> >::const_iterator it = todo[i].begin(); it != todo[i].end(); ++it) {
                if (miss[it->first] > 0 || red[it->first]) {
                    continue;
                }
                if (it->second == 2) {
                    red[it->first] = true;
                } else if (yellow[it->first]) {
                    yellow[it->first] = false;
                    red[it->first] = true;
                } else {
                    yellow[it->first] = true;
                }
            }

            for (int j = 0; j < MAXN; ++j) {
                if (miss[j] > 0) {
                    --miss[j];
                    ans.push_back(make_pair(i, j));
                }
            }
        }

        sort(ans.begin(), ans.end());
        for (vector<pair<int, int> >::const_iterator it = ans.begin(); it != ans.end(); ++it) {
            assert(2 <= it->first && it->first <= 7);
            printf("%d %d\n", it->first, it->second);
        }
        puts("#");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//898   2010-07-21 21:08:21     Accepted    1098    C++     10  180     anotherpeg  Source

// 2012-09-07 15:48:45 | Accepted | 3361 | C++ | 0 | 180 | watashi | Source
