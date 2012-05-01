#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXD = 11;
const int MAXN = 150000;
const int MAXM = 10000;

int s[1000];

int sum(int n) {
    if (n < 1000) {
        return s[n];
    } else {
        return s[n % 1000] + sum(n / 1000);
    }
}

int p[1000];

int prod(int n) {
    if (n < 1000) {
        return p[n];
    } else if (n % 1000 < 100) {
        return 0;
    } else {
        return p[n % 1000] * prod(n / 1000);
    }
}

bool ispsd(int n) {
    return n != 0 && prod(n) % sum(n) == 0;
}

int cnt[MAXN], zero;
map<pair<int, int>, int> mp;
int ss[500], pp[500], cc[500];

int main() {
    int n, m;

    for (int i = 0; i < 1000; ++i) {
        s[i] = i == 0 ? 0 : i % 10 + s[i / 10];
        p[i] = i == 0 ? 1 : i % 10 * p[i / 10];
    }
    for (int i = 0; i < MAXM; ++i) {
        if (ispsd(i)) {
            ++cnt[1];
        }
    }

    zero = MAXM / 10;
    for (int i = MAXM / 10; i < MAXM; ++i) {
        int s = sum(i);
        int p = prod(i);
        if (p == 0) {
            ++zero;
        } else {
            ++mp[make_pair(s, p)];
        }
    }
    m = 0;
    for (map<pair<int, int>, int>::const_iterator j = mp.begin(); j != mp.end(); ++j) {
        ss[m] = j->first.first;
        pp[m] = j->first.second;
        cc[m] = j->second;
        ++m;
    }

    // printf("%d\n", (int)mp.size());
    for (int i = 1; i < MAXN - 1; ++i) {
        int s = sum(i);
        int p = prod(i);
        if (p == 0) {
            cnt[i + 1] = cnt[i] + MAXM;
        } else {
            cnt[i + 1] = cnt[i] + zero;
            for (int j = 0; j < m; ++j) {
                if (p * pp[j] % (s + ss[j]) == 0) {
                    cnt[i + 1] += cc[j];
                }
            }
        }
    }
    // printf("%lld\n", cnt[MAXN - 1]);

    while (scanf("%d", &n) != EOF && n > 0) {
        m = lower_bound(cnt, cnt + MAXN, n) - cnt;
        n -= cnt[m - 1];
        for (m = (m - 1) * MAXM; n > 0; ++m) {
            if (ispsd(m)) {
                --n;
            }
        }
        printf("%d\n", m - 1);
    }

    return 0;
}

