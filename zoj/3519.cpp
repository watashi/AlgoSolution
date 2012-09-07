#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, iq, jq;
    vector<int> a;

    while (scanf("%d%d", &n, &iq) != EOF) {
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        jq = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > iq) {
                iq += 2;
            } else {
                ++jq;
            }
        }
        printf("%d\n", iq + jq);
    }

    return 0;
}

// 2012-09-07 16:51:22 | Accepted | 3519 | C++ | 60 | 180 | watashi | Source
