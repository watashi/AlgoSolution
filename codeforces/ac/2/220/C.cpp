#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int a[MAXN], b[MAXN];
multiset<int> st;

int main() {
    int n, x;
    vector<pair<int, int> > v, w;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[x - 1] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        b[x - 1] = i;
    }
    for (int i = 0; i < n; ++i) {
        v.push_back({0, b[i] - a[i]});
        w.push_back({b[i] + 1, b[i] - a[i]});
        v.push_back({b[i] + 1, n + b[i] - a[i]});
    }
    st.insert(-n - n);
    st.insert(n + n);
    sort(v.rbegin(), v.rend());
    sort(w.rbegin(), w.rend());

    for (int i = 0; i < n; ++i) {
        while (!v.empty() && v.back().first == i) {
            st.insert(v.back().second);
            v.pop_back();
        }
        while (!w.empty() && w.back().first == i) {
            st.erase(st.find(w.back().second));
            w.pop_back();
        }
        auto it = st.lower_bound(i);
        int r = *it;
        --it;
        int l = *it;
        // printf("%d %d\n", l, r);
        // printf("%d\n", min(dis(n, l, i), dis(n, r, i)));
        printf("%d\n", min(i - l, r - i));
    }

    return 0;
}

