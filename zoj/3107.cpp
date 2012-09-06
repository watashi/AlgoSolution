#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int re;
    char buf[128];

    scanf("%d", &re);
    while(getchar() != '\n');
    for (int ri = 1; ri <= re; ++ri) {
        int x = 0, y = 0, s = 0;
        vector<vector<int> > vvi(256);

        gets(buf);
        for (int i = 0; buf[i] != '\0'; ++i) {
            switch (buf[i]) {
            case 'U': --y; break;
            case 'D': ++y; break;
            case 'L': --x; vvi[x + 128].push_back(y); break;
            case 'R': vvi[x + 128].push_back(y); ++x; break;
            }
        }
        for (size_t i = 0; i < vvi.size(); ++i) {
            // assert(vvi.size() % 2 == 0);
            sort(vvi[i].begin(), vvi[i].end());
            for (size_t j = 0; j < vvi[i].size(); j += 2) {
                s += vvi[i][j + 1] - vvi[i][j];
            }
        }
        printf("case %d: %d\n", ri, s);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1749876   2009-01-28 00:30:33     Accepted    3107    C++     0   176     watashi@Zodiac

// 2012-09-07 02:01:31 | Accepted | 3107 | C++ | 0 | 180 | watashi | Source
