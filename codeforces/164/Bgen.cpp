#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int n = 987654, m = 1000000;
    vector<int> v;

    printf("%d %d\n", n, m);

    for (int i = 0; i < n; ++i) {
        v.push_back(rand());
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; ++i) {
        printf("%d%c", v[i], i == n - 1 ? '\n' : ' ');
    }

    for (int i = 0; i < m; ++i) {
        v.push_back(rand());
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // random_shuffle(v.begin(), v.end());
    v.resize(m);
    for (int i = 0; i < m; ++i) {
        printf("%d%c", v[i], i == m - 1 ? '\n' : ' ');
    }

    return 0;
}

