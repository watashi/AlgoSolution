#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int d[10086][128];

int main() {
    int r, c, x;

    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
        vector<int> v;
        for (int j = 0; j < c; ++j) {
            scanf("%1d", &x);
            if (x != 0) {
                v.push_back(j);
            }
        }
        if (v.empty()) {
            puts("-1");
            return 0;
        }
        v.push_back(v.front() + c);
        for (int k = 0; k < (int)v.size() - 1; ++k) {
            for (int j = v[k]; j < v[k + 1]; ++j) {
                d[j % c][i] = min(j - v[k], v[k + 1] - j);
            }
        }
    }

    x = r * c;
    for (int i = 0; i < c; ++i) {
        x = min(x, accumulate(d[i], d[i] + r, 0));
    }
    printf("%d\n", x);

    return 0;
}
