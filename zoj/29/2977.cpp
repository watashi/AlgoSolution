// solution by whatashya @ zju

// 1354  Extended Lights Out

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <limits>
#include <numeric>
#include <utility>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int bin[17];
int cnt1[1 << 16];
int change[1 << 16];

void init(void)
{
    for (int k = 0; k <= 16; k++)
        bin[k] = 1 << k;
    for (int i = 0; i < 65536; i++) {
        cnt1[i] = 0;
        change[i] = 0;
        for (int j = 0; j < 16; j++)
            if((i & bin[j]) != 0) {
                ++cnt1[i];
                if(j > 0) change[i] ^= bin[j - 1];
                change[i] ^= bin[j] | bin[j + 1];
            }
    }
}

char buf[20];
int mp[20];
int bb[20];

int main(void)
{
    int r, c, tmp, ans;

    init();
    while(scanf("%d%d", &r, &c) != EOF && r + c > 0) {
        for (int i = 0; i < r; i++) {
            scanf("%s", buf);
            mp[i] = 0;
            for (int j = 0; j < c; j++)
                if(buf[j] == 'X')
                    mp[i] |= bin[j];
        }
        ans = numeric_limits<int>::max();
        for (int i = 0; i < bin[c]; i++) {
            tmp = cnt1[i];
            for (int j = 0; j < r; j++)
                bb[j] = mp[j];
            bb[0] ^= change[i] & (bin[c] - 1);
            bb[1] ^= i;
            for (int j = 1; j < r; j++) {
                tmp += cnt1[bb[j - 1]];
                bb[j] ^= change[bb[j - 1]] & (bin[c] - 1);
                bb[j + 1] ^= bb[j - 1];
            }
            if(bb[r - 1] == 0 && tmp < ans)
                ans = tmp;
        }
        if(ans == numeric_limits<int>::max())
            puts("Damaged billboard.");
        else
            printf("You have to tap %d tiles.\n", ans);
    }

    return 0;
}

/*
real    0m0.156s
user    0m0.140s
sys     0m0.046s
*/

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948277   2008-06-12 15:37:04     Accepted    2977    C++     00:00.25    1348K   Re:ReJudge

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2948280   2008-06-12 15:38:15     Accepted    2977    C++     00:00.22    908K    Re:ReJudge

// 2012-09-07 01:51:50 | Accepted | 2977 | C++ | 110 | 700 | watashi | Source
