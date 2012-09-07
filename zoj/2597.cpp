#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> ans[13];
const string ans1[] = {"0", "1"};
const string ans2[] = {"00", "10", "01", "11"};

int main() {
    ans[1].insert(ans[1].begin(), ans1, ans1 + 2);
    ans[2].insert(ans[2].begin(), ans2, ans2 + 4);
    for (int k = 3; k <= 12; ++k) {
        ans[k].resize(1 << k);
        int left = k / 2;
        int right = k - left;
        if (left % 2 != 0 && right % 2 != 0) {
            --left;
            ++right;
        }
        int maskl = (1 << left) - 1;
        int maskr = (1 << right) - 1;
        for (int i = 0; i < ans[k].size(); ++i) {
            ans[k][i] = ans[left][i & maskl] + ans[right][(i + (i >> right)) & maskr];
        }
    }

    bool blank = false;
    int n;
    while (scanf("%d", &n) != EOF && n > 0) {
        if (blank) {
            puts("");
        } else {
            blank = true;
        }
        for (vector<string>::const_iterator i = ans[n].begin(); i != ans[n].end(); ++i) {
            puts(i->c_str());
        }
    }
    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//2175199   2010-04-24 15:15:54     Accepted    2597    C++     0   440     watashi@Zodiac

// 2012-09-07 15:42:06 | Accepted | 2597 | C++ | 0 | 444 | watashi | Source
