#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int ten[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000
};

vector<int> v;

void gen(int n, int d, int x, int y) {
    if (0 <= d && d < 10) {
        --n;
        y += d;
        if (n == 0) {
            v.push_back(y);
        } else {
            int t = x / ten[n - 1];
            x -= t * ten[n - 1];
            y *= 10;
            gen(n, d - t, x, y);
            gen(n, d + t, x, y);
        }
    }
}

int main() {
    int x, y;
    vector<int> a(1, 7);

    for (int l = 2; l <= 9; ++l) {
        v.clear();
        for (vector<int>::const_iterator i = a.begin(); i != a.end(); ++i) {
            for (int d = 1; d <= 9; ++d) {
                gen(l, d, *i, 0);
            }
        }
        a.insert(a.end(), v.begin(), v.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }
//  for (int i = 0; i < (int)a.size(); ++i) {
//      printf("%d\n", a[i]);
//  }
//  printf("%d\n", a.size());
//  return 0;
    while (scanf("%d%d", &x, &y) != EOF) {
        printf("%d\n", upper_bound(a.begin(), a.end(), y) - lower_bound(a.begin(), a.end(), x));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//377   2010-11-10 01:10:40     Accepted    J   C++     340     7360    watashi@Zodiac  Source

// 2012-09-07 17:07:45 | Accepted | 3436 | C++ | 330 | 7360 | watashi | Source
