#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

const string ones     [] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const string tens     [] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string hundreds [] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string thousands[] = {"", "M", "MM", "MMM"};

string a2r(int x) {
    return thousands[x / 1000 % 10] + hundreds[x / 100 % 10] + tens[x / 10 % 10] + ones[x % 10];
}

int main() {
    int re, n;
    vector<pair<string, int> > v;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d", &n) == 1);
        assert(1 <= n && n <= 10000);
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            assert(scanf("%d", &v[i].second) == 1);
            v[i].first = a2r(v[i].second);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            printf("%d%c", v[i].second, i == n - 1 ? '\n' : ' ');
        }
    }
    assert(scanf("%d", &re) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//729   2011-04-22 17:03:25     Accepted    B   C++     180     576     watashi@ArcOfDream  Source

// 2012-09-07 16:02:36 | Accepted | 3501 | C++ | 180 | 576 | watashi | Source
