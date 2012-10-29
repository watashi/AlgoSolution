#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 100100;
const int MAXP = 10001000;

int p[MAXP];

void init() {
    for (int i = 2; i < MAXP; ++i) {
        if (p[i] == 0) {
            for (int j = i; j < MAXP; j += i) {
                p[j] = i;
            }
        }
    }
}

void gao(int n, vector<int>& a, vector<int>& x) {
    a.resize(n);
    vector<int>(MAXP, 0).swap(x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = a[i]; j > 1; j /= p[j]) {
            ++x[p[j]];
        }
    }
}

void gao(const vector<int>& v, vector<int> w) {
    for (int i: v) {
        for (int j = i; j > 1; j /= p[j]) {
            if (w[p[j]] > 0) {
                --w[p[j]];
                i /= p[j];
            }
        }
        printf("%d ", i);
    }
    puts("");
}

int main() {
    int n, m;
    vector<int> a, b, x, y, z;

    init();
    scanf("%d%d", &n, &m);
    gao(n, a, x);
    gao(m, b, y);
    printf("%d %d\n", n, m);
    transform(x.begin(), x.end(), y.begin(),
        insert_iterator<vector<int> >(z, z.end()),
        [](int a, int b) { return min(a, b); });
    gao(a, z);
    gao(b, z);

    return 0;
}

