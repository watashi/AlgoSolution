#include <set>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

set<pair<int, int> > st;

int main() {
    int n = 1000000, m = 1000000;

    printf("%d %d\n", n, m);
    for (int i = 0; i < 10; ++i) {
        for (int j = 11; j < 10000; ++j) {
            st.insert(make_pair(i, j));
        }
    }
    while ((int)st.size() < m) {
        int a = rand() % (n - 9000);
        int b = rand() % (n - 9000);
        if (a > b) {
            swap(a, b);
        }
        if (a < b) {
            st.insert(make_pair(a + 9000, b + 9000));
        }
    }
    for (const auto& p: st) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }

    return 0;
}

