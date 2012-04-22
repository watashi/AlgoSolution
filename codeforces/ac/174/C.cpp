#include <stack>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, p, q;
    stack<int> s;
    vector<pair<int, int> > ans;

    scanf("%d", &n);
    p = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == n) {
            q = 0;
        } else {
            scanf("%d", &q);
        }
        if (p < q) {
            for (int j = p; j < q; ++j) {
                s.push(i);
            }
        } else {
            for (int j = p; j > q; --j) {
                ans.push_back({s.top(), i});
                s.pop();
            }
        }
        p = q;
    }
    printf("%d\n", ans.size());
    for (auto i: ans) {
        printf("%d %d\n", i.first + 1, i.second);
    }

    return 0;
}

