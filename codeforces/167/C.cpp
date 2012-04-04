#include <map>
#include <cstdio>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

map<pair<long long, long long>, bool> mp;

bool gao(long long a, long long b) {
    if (a > b) {
        return gao(b, a);
    } else if (a == 0) {
        return false;
    } else if (mp.count(make_pair(a, b)) > 0) {
        return mp[make_pair(a, b)];
    } else {
        bool &ret = mp[make_pair(a, b)];
        if (!gao(b % a, a)) {
            ret = true;
        } else {
            b /= a;
            if (a % 2 == 0) {
                ret = b % (a + 1) % 2 == 0;
            } else {
                ret = b % 2 == 0;
            }
        }
        return ret;
    }
}

int main() {
    /*
    for (int i = 0; i < 72; ++i) {
        printf("%3d: ", i);
        for (int j = 0; j <= i; ++j) {
            putchar(gao(i, j) > 0 ? 'W' : 'L');
        }
        puts("");
    }
    */
    int re;
    long long x, y;

    cin >> re;
    for (int ri = 1; ri <= re; ++ri) {
        cin >> x >> y;
        cout << (gao(x, y) ? "First\n" : "Second\n");
    }

    return 0;
}

