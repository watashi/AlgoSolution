#include <set>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, m, x, y;
    set<pair<int, int> > st;
    vector<pair<int, int> > v;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        v.push_back({x, y});
        st.insert({x * 2, y * 2});
    }
    m = 0;
    for (auto a: v) {
        for (auto b: v) {
            if (a == b) {
                break;
            } else if (st.count({a.first + b.first, a.second + b.second}) > 0) {
                ++m;
            }
        }
    }
    printf("%d\n", m);

    return 0;
}
