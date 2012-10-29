#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 8192;
const int INF = 1000000007;

vector<string> v;
int h[MAXN];

int lcp(const string& lhs, const string& rhs) {
    int ret = 0;
    while (ret < (int)lhs.length() && ret < (int)rhs.length() && lhs[ret] == rhs[ret]) {
        ++ret;
    }
    return ret;
}

vector<int> gao(int n, int l, int r) {
    // printf("gao(%d, %d, %d)\n", n, l, r);
    vector<int> ret(min(r - l, n) + 1, 0);
    if (r - l == 1) {
    } else if (r - l == 2) {
        // printf("h[%d] = %d\n", l + 1, h[l + 1]);
        if (n >= 2) {
            ret[2] += h[l + 1];
        }
    } else {
        int m = min_element(h + l + 1, h + r) - h;
        vector<int> lhs = gao(n, l, m);
        vector<int> rhs = gao(n, m, r);
        int nlhs = (int)lhs.size() - 1;
        int nrhs = (int)rhs.size() - 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = max(0, i - nrhs); j <= i && j <= nlhs; ++j) {
                ret[i] = max(ret[i], lhs[j] + rhs[i - j] + j * (i - j) * h[m]);
            }
        }
    }
    return ret;
}

int main() {
    int n, m;
    char buf[MAXN];

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        v.push_back(buf);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; ++i) {
        h[i] = lcp(v[i - 1], v[i]);
        // printf("(%s,%s) = %d\n", v[i - 1].c_str(), v[i].c_str(), h[i]);
    }

    vector<int> ans = gao(m, 0, n);

    printf("%d\n", ans[m]);

    return 0;
}

