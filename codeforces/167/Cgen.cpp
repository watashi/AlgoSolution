#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const long long MAXN = 1000000000LL * 1000000000LL;

long long randll() {
    long long ret = 0;
    for (int i = 0; i < 4; ++i) {
        ret ^= rand();
        ret <<= 16;
    }
    return ret % MAXN;
}

int main() {
    vector<long long> fib = {0, 1};
    vector<pair<long long, long long> > test;

    while (fib[(int)fib.size() - 2] + fib[(int)fib.size() - 1] <= MAXN) {
        fib.push_back(fib[(int)fib.size() - 2] + fib[(int)fib.size() - 1]);
    }
    fib.push_back(1000000007);
    fib.push_back(1000000009);
    fib.push_back(987654321987654329LL);
    fib.push_back(987654321987654383LL);
    fib.push_back(987654321987654401LL);
    fib.push_back(987654321987654553LL);
    fib.push_back(987654321987654557LL);
    fib.push_back(987654321987654631LL);
    fib.push_back(987654321987654637LL);
    fib.push_back(987654321987654691LL);
    fib.push_back(987654321987654719LL);
    fib.push_back(987654321987654721LL);
    fib.push_back(987654439LL * 1000000007LL);
    for (long long i: fib) {
        for (long long j: fib) {
            if (i <= j) {
                if (rand() % 2 == 0) {
                    test.push_back({i, j});
                } else {
                    test.push_back({j, i});
                }
            }
        }
    }
   // printf("%d\n", (int)test.size());
    for (long long i = 10; i < 50; ++i) {
        for (long long j = 0; j <= i; ++j) {
            test.push_back({i, j});
        }
    }
   //  printf("%d\n", (int)test.size());
    while ((int)test.size() < 10000) {
        if (rand() % 2 == 0) {
            test.push_back({randll(), randll()});
        } else if (rand() % 2 == 0) {
            test.push_back({rand(), randll()});
        } else {
            test.push_back({randll(), rand()});
        }
    }

    cout << test.size() << endl;
    for (auto& p: test) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

