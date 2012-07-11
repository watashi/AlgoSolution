#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXL = 10;
const int MAXN = 5050;

set<vector<int> > done;
vector<int> best[MAXN];

void gao(vector<int>& v) {
    if (!done.insert(v).second) {
        return;
    }
    int n = v.back();
    if (best[n].empty() || v.size() < best[n].size()) {
        best[n] = v;
    }
    if ((int)v.size() < MAXL) {
        for (int i: v) {
            for (int j: v) {
                if (i <= j && i + j > n) {
                    v.push_back(i + j);
                    gao(v);
                    v.pop_back();
                }
            }
        }
    }
}

int main() {
    vector<int> v = {1};
    gao(v);

    for (int i = MAXN - 1; i > 0; --i) {
        if (best[i].empty()) {
            continue;
        }
        if ((int)best[i].size() == __builtin_popcount(i) + (31 - __builtin_clz(i))) {
            best[i].clear();
        }
    }
    /*
    for (int i = MAXN - 1; i > 0; --i) {
        if (best[i].empty()) {
            continue;
        }
        for (int j = i - 1; j > 1; --j) {
            if (i % j == 0) {
                int k = i / j;
                if (!best[j].empty() && !best[k].empty() &&
                    best[i].size() + 1 >= best[j].size() + best[k].size()) {
                    best[i].clear();
                }
                break;
            }
        }
    }
    */

    for (int i = 2; i < MAXN; ++i) {
        if (!best[i].empty()) {
            printf("[%d", i);
            best[i].pop_back();
            reverse(best[i].begin(), best[i].end());
            for (int j: best[i]) {
                printf(", %d", j);
            }
            printf("]\n");
        }
    }
    return 0;
}

