#include <cstdio> // auto fix CE
#include <algorithm> // auto fix CE
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int n, p, q, l, a, b, t;
string str;
vector<int> pre;
vector<int> post;
int el[256], er[256];
int cnt[256];

void prego(int i, vector<int>::iterator begin, vector<int>::iterator end) {
    int p = 0;
    if (el[i] != -1) {
        p += cnt[el[i]];
    }
    cnt[i] = *(begin + p);
    if (el[i] != -1) {
        prego(el[i], begin, begin + p);
    }
    if (er[i] != -1) {
        prego(er[i], begin + p + 1, end);
    }
}

void postgo(int i) {
    if (el[i] != -1) {
        postgo(el[i]);
    }
    if (er[i] != -1) {
        postgo(er[i]);
    }
    post[t++] = cnt[i];
}

int main() {
    while (cin >> n) {
        pre.resize(n);
        post.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> pre[i];
            el[i] = er[i] = -1;
        }
        sort(pre.begin(), pre.end());
        cin >> l;
        getline(cin, str);
        cnt[0] = n;
        p = 0;
        q = 1;
        t = 1;
        for (int i = 0; i < l - 1; ++i) {
            getline(cin, str);
            istringstream iss(str);
            for (int j = p; j < q; ++j) {
                if (cnt[j] > 1) {
                    iss >> a >> b;
                    if (a > 0) {
                        el[j] = t;
                        cnt[t] = a;
                        ++t;
                    }
                    if (b > 0) {
                        er[j] = t;
                        cnt[t] = b;
                        ++t;
                    }
                }
            }
            p = q;
            q = t;
        }
        prego(0, pre.begin(), pre.end());
        t = 0;
        postgo(0);
        for (int i = 0; i < post.size(); ++i) {
            printf("%d%c", post[i], (i == post.size() - 1) ? '\n' : ' ');
        }
    }
    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801343   2009-03-23 23:30:09     Accepted    3170    C++     0   188     watashi@Zodiac

// 2012-09-07 13:38:06 | Accepted | 3170 | C++ | 0 | 188 | watashi | Source
