#include <queue>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int w[MAXN];
vector<int> v[MAXN];

int main() {
    int re, n, m, ww;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &m);
            v[i].resize(m);
            for (int j = 0; j < m; ++j) {
                scanf("%d", &v[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w[i]);
        }
/*
        priority_queue<int> q;
        ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (vector<int>::const_iterator j = v[i].begin(); j != v[i].end(); ++j) {
                q.push(-*j);
            }
            while (!q.empty() && w[i] + q.top() >= 0) {
                ++ans;
                w[i] += q.top();
                q.pop();
            }
        }
*/
        priority_queue<int> p;
        ww = 0;
        for (int i = 0; i < n; ++i) {
            priority_queue<int> q;
            ww += w[i];
            for (vector<int>::const_iterator j = v[i].begin(); j != v[i].end(); ++j) {
                q.push(-*j);
            }
            while (true) {
                if (!p.empty() && !q.empty() && p.top() > -q.top()) {
                    int a = p.top();
                    int b = -q.top();
                    p.pop();
                    q.pop();
                    p.push(b);
                    q.push(-a);
                    ww += a - b;
                } else if (!q.empty() && ww >= -q.top()) {
                    int b = -q.top();
                    p.push(b);
                    q.pop();
                    ww -= b;
                } else {
                    break;
                }
            }
        }
        printf("%d\n", p.size());
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//371   2010-11-10 00:14:11     Accepted    G   C++     380     4180    watashi@Zodiac  Source

// 2012-09-07 15:54:37 | Accepted | 3433 | C++ | 390 | 4180 | watashi | Source
