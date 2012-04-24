#include <set>
#include <iostream>

using namespace std;

struct Set {
    int c;
    long long slo, shi;
    multiset<long long> hi;
    multiset<long long, greater<long long> > lo;

    void init(int n) {
        c = n;
        slo = shi = 0LL;
    }

    void insert(long long x) {
        hi.insert(x);
        shi += x;
        if ((int)hi.size() > c) {
            x = *hi.begin();
            hi.erase(hi.begin());
            lo.insert(x);
            shi -= x;
            slo += x;
        }
    }

    void erase(long long x) {
        if (lo.count(x) > 0) {
            lo.erase(lo.find(x));
            slo -= x;
        } else {
            hi.erase(hi.find(x));
            shi -= x;
            if (!lo.empty()) {
                x = *lo.begin();
                lo.erase(lo.begin());
                hi.insert(x);
                slo -= x;
                shi += x;
            }
        }
    }
} pos, neg;

const int MAXN = 100100;

long long a[MAXN];

void insert(long long x) {
    if (x >= 0) {
        pos.insert(x);
    } else {
        neg.insert(-x);
    }
}

void erase(long long x) {
    if (x >= 0) {
        pos.erase(x);
    } else {
        neg.erase(-x);
    }
}

long long query() {
    return max(
        pos.shi + pos.slo + neg.shi - neg.slo,
        neg.shi + neg.slo + pos.shi - pos.slo);
}

int main() {
    int n, m, k;
    long long ans = 0;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    pos.init(k);
    neg.init(k);
    for (int i = 0; i < n; ++i) {
        if (i >= m) {
            erase(a[i - m]);
        }
        insert(a[i]);
        if (i >= m) {
            ans = max(ans, query());
        } else if (i == m - 1) {
            ans = query();
        }
    }
    cout << ans << endl;

    return 0;
}

