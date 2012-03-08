#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d = 0;
    vector<int> v;

    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    m = max_element(v.begin(), v.end()) - v.begin();
    d += m;
    rotate(v.begin(), v.begin() + m, v.begin() + m + 1);
    m = min_element(v.rbegin(), v.rend()) - v.rbegin();
    d += m;
    printf("%d\n", d);

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1133053 	Feb 2, 2012 4:36:32 PM 	watashi 	144A - Arrival of the General 	GNU C++0x 	Accepted 	30 ms 	1400 KB
