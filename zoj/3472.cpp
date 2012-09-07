#include <utility> // auto fix CE
#include <cstdio>
#include <utility> // auto fix CE
#include <vector>
#include <utility> // auto fix CE
#include <cstring>
#include <utility> // auto fix CE
#include <algorithm>

using namespace std;

typedef pair<int, int> Card;

const char* player = "NESW";
const char* suit = "SHDCN";

int main() {
    int re, a, b;
    int trump, bid, leader;
    char buf[80];
    Card w[4];
    vector<Card> v[4];

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%s", buf);
        leader = strchr(player, buf[0]) - player;
        scanf("%d", &bid);
        scanf("%s", buf);
        trump = strchr(suit, buf[0]) - suit;
        for (int i = 0; i < 4; ++i) {
            v[i].clear();
            for (int j = 0; j < 4; ++j) {
                scanf("%d", &a);
                for (int k = 0; k < a; ++k) {
                    scanf("%d", &b);
                    v[i].push_back(make_pair(j, b == 1 ? -14 : -b));
                }
            }
            sort(v[i].begin(), v[i].end());
        }

        a = leader % 2;
        b = -(6 + bid);
        leader = (leader + 1) & 3;
        while (!v[0].empty()) {
            for (int i = leader, ii = 0; ii < 4; i = (i + 1) & 3, ++ii) {
                w[i].first = -2;
                for (int j = 0; j < (int)v[i].size(); ++j) {
                    if (v[i][j].first == w[leader].first) {
                        w[i] = v[i][j];
                        v[i].erase(v[i].begin() + j);
                        break;
                    }
                }
                if (w[i].first == -2) {
                    w[i] = v[i][0];
                    v[i].erase(v[i].begin());
                }
                if (w[i].first != w[leader].first) {
                    w[i].first = w[i].first == trump ? -1 : 5;
                }
            }
            leader = min_element(w, w + 4) - w;
            if (leader % 2 == a) {
                ++b;
            }
        }

        if (b == 0) {
            puts("MAKE");
        } else {
            printf("%+d\n", b);
        }
    }

    return 0;
}

// 2012-09-07 15:59:33 | Accepted | 3472 | C++ | 10 | 180 | watashi | Source
