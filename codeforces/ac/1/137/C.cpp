#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

pair<int, int> p[MAXN];

int main() {
    int n, m;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    m = 0;
    for (int i = 1; i < n; ++i) {
        if (p[i].second < p[i - 1].second) {
            p[i].second = p[i - 1].second;
            ++m;
        }
    }
    printf("%d\n", m);

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1132737 	Feb 2, 2012 2:24:43 PM 	watashi 	137C - History 	GNU C++ 	Accepted 	110 ms 	2100 KB

