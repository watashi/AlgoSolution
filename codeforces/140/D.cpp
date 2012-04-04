#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int START = 10, MID = 6 * 60, END = 12 * 60;

int main() {
    int n, x, y;
    vector<int> a;

    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    partial_sum(a.begin(), a.end(), a.begin());

    x = y = 0;
    for (int i = 0; i < n; ++i) {
        if (START + a[i] <= END) {
            ++x;
            y += max(0, START + a[i] - MID);
        }
    }
    printf("%d %d\n", x, y);

    return 0;
}

