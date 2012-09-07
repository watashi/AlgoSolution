#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gao(const vector<int>& v, int b) {
    if (v.size() < 2 && v[0] < 10) {
        return v[0];
    } else {
        long long c = 0;
        for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
            c *= 1000000LL;
            c += *i;
            if (c >= 1000000000LL) {
                c %= (10 - b);
            }
        }
        c = (c - 10) % (10 - b);
        while (c < 0) {
            c += (10 - b);
        }
        return b + c;
    }
}

int main() {
    char buf[100100];

    while (scanf("%s", buf) != EOF) {
        vector<int> v;
        for (int i = 0; buf[i] != '\0'; ++i) {
            v.push_back(buf[i] - '0');
        }
        reverse(v.begin(), v.end());
        vector<int> w;
        for (int i = 0; i < (int)v.size(); i += 6) {
            w.push_back(0);
            for (int j = min(i + 5, (int)v.size() - 1); j >= i; --j) {
                w.back() = w.back() * 10 + v[j];
            }
        }
        reverse(w.begin(), w.end());
        for (int i = 1; i < 10; ++i) {
            printf("%d%c", gao(w, i), i == 9 ? '\n' : ' ');
            fflush(stdout);
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//632   2010-12-24 00:28:57     Accepted    E   C++     180     1208    watashi@Zodiac  Source

// 2012-09-07 15:57:12 | Accepted | 3449 | C++ | 170 | 1208 | watashi | Source
