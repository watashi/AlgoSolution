#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const double TARGET = 0.1 + 1e-8;
const int PARAM = 10;
const int TIME_LIMIT = 30 * CLOCKS_PER_SEC / 52;

int time_limit = 0;

bool timeout() {
    return clock() > time_limit;
}

bool mark[MAXN];
int c[MAXN];
double q[MAXN];
double p[MAXN][MAXN];

int tmp, cmp;
set<int> cur, ans;
set<set<int> > done;

void gao(int n, int m) {
    if (tmp >= cmp || timeout() || !done.insert(cur).second) {
        return;
    }

    vector<pair<double, int> > qq;
    for (int i = 0; i < n; ++i) {
        if (q[i] > TARGET) {
            qq.push_back(make_pair(q[i], i));
        }
    }
    sort(qq.rbegin(), qq.rend());
    if (qq.empty()) {
        cmp = tmp;
        ans = cur;
        return;
    } else if ((int)qq.size() > PARAM) {
        qq.resize(PARAM);
    }

    map<int, int> mp;
    for (int i = 0; i < (int)qq.size(); ++i) {
        int k = qq[i].second;
        vector<pair<double, int> > pp;
        for (int j = 0; j < m; ++j) {
            if (!mark[j] && p[k][j] < 1) {
                pp.push_back(make_pair(p[k][j], j));
            }
        }
        sort(pp.begin(), pp.end());
        if ((int)pp.size() > PARAM - i) {
            pp.resize(PARAM - i);
        }
        for (int j = 0; j < (int)pp.size(); ++j) {
            mp[pp[j].second] += PARAM - i;
        }
    }

    vector<pair<int, int> > todo;
    for (map<int, int>::const_iterator it = mp.begin(); it != mp.end(); ++it) {
        todo.push_back(make_pair(-it->second + c[it->first] / 100, it->first));
    }
    sort(todo.begin(), todo.end());

    vector<double> bak(q, q + n);
    for (int i = 0; i < (int)todo.size(); ++i) {
        int j = todo[i].second;
        copy(bak.begin(), bak.end(), q);
        for (int k = 0; k < n; ++k) {
            q[k] *= p[k][j];
        }
        mark[j] = true;
        tmp += c[j];
        cur.insert(j);
        gao(n, m);
        cur.erase(j);
        tmp -= c[j];
        mark[j] = false;
    }
}

int main() {
    int re, n, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &c[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%lf", &p[i][j]);
                p[i][j] = (100 - p[i][j]) / 100;
            }
        }

        tmp = cmp = 0;
        cur.clear();
        ans.clear();
        for (int i = 0; i < m; ++i) {
            cmp += c[i];
            ans.insert(i);
        }

        time_limit += TIME_LIMIT;
        fill(mark, mark + m, false);
        fill(q, q + n, 1.0);
        done.clear();
        gao(n, m);
        printf("%d\n", (int)ans.size());
        for (set<int>::const_iterator it = ans.begin(); it != ans.end(); ++it) {
            printf("%s%d", it == ans.begin() ? "" : " ", *it + 1);
        }
        puts("");
    }

    return 0;
}

