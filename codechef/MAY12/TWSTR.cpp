#include <cstdio>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

char buf[4096];
string pat;
vector<pair<string, int> > v;

int main() {
    int n, m, a, b;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", buf, &a);
        v.push_back(make_pair(buf, a));
    }
    sort(v.begin(), v.end());

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%s", buf);
        pat = buf;
        a = lower_bound(v.begin(), v.end(), make_pair(pat, 0)) - v.begin();
        pat += '~';
        b = upper_bound(v.begin(), v.end(), make_pair(pat, 0)) - v.begin();
        if (a < b) {
            for (int j = a; j < b; ++j) {
                if (v[j].second > v[a].second) {
                    a = j;
                }
            }
            puts(v[a].first.c_str());
        } else {
            puts("NO");
        }
    }

    return 0;
}

//Correct Answer
//Execution Time: 0.12
