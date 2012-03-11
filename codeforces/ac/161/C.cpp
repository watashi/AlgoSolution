#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> PLL;

long long s[50];

void gao(int n, long long l, long long r, vector<PLL>& ret) {
    l = max(l, 0LL);
    r = min(r, s[n]);
    if (l < r) {
        ret.push_back({l, r});
        --n;
        if (0 < l || r < s[n]) {
            gao(n, l, r, ret);
            gao(n, l - s[n] - 1, r - s[n] - 1, ret);
        }
    }
}

int main() {
    long long a, b, c, d, ans;
    vector<PLL> x, y;

    s[0] = 1;
    for (int i = 1; i < 50; ++i) {
        s[i] = s[i - 1] + s[i - 1] + 1;
    }
    cin >> a >> b >> c >> d;
    gao(32, a - 1, b, x);
    gao(32, c - 1, d, y);

    ans = 0;
    for (auto& i: x) {
        for (auto& j: y) {
            ans = max(ans, min(i.second, j.second) - max(i.first, j.first));
        }
    }
    cout << ans << endl;

    return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//1348640 	Mar 11, 2012 10:35:36 PM 	watashi 	C - Abracadabra 	GNU C++0x 	Accepted 	30 ms 	1400 KB
