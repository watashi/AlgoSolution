#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 32;
const int LIMIT = 18;

int v[MAXN], c[MAXN], d[MAXN];
double p[MAXN];

vector<pair<int, int> > z[MAXN];
vector<pair<int, double> > x[MAXN], y[MAXN];

template<typename T>
void dump(const vector<pair<int, T> >& v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        printf("(%d,%lf) ", v[i].first, (double)v[i].second);
    }
    puts("");
}

template<typename T, typename S>
void trim(vector<pair<int, T> >& v, S f) {
    int n = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
        if (n == 0 || f(v[i].second, v[n - 1].second)) {
            v[n++] = v[i];
        }
    }
    v.resize(n);
}

void thing(int n) {
    vector<pair<int, int> > dp[MAXN][MAXN];
    dp[0][0].push_back(make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            sort(dp[i][j].begin(), dp[i][j].end());
            trim(dp[i][j], less<int>());
            for (int k = 0; k < (int)dp[i][j].size(); ++k) {
                dp[i + 1][j].push_back(dp[i][j][k]);
                dp[i + 1][j + 1].push_back(make_pair(dp[i][j][k].first + c[i], dp[i][j][k].second + d[i]));
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < (int)dp[n][i].size(); ++j) {
            if (dp[n][i][j].second < MAXN) {
                z[dp[n][i][j].second].push_back(make_pair(dp[n][i][j].first, i));
            }
        }
    }
    for (int i = 0; i < MAXN; ++i) {
        if (i > 0) {
            z[i].insert(z[i].end(), z[i - 1].begin(), z[i - 1].end());
        }
        trim(z[i], greater<int>());
    }
}

void box(int n, int sv, int sd, double pp, vector<pair<int, double> > ret[]) {
    if (pp == 0) {
    } else if (n == 0) {
        ret[sd].push_back(make_pair(sv, pp));
    } else {
        --n;
        box(n, sv + v[n], sd, pp * p[n], ret);
        box(n, sv, sd + 1, pp * (1 - p[n]), ret);
    }
}

int main() {
    int re, n, m;
    double ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d%lf", &v[i], &p[i]);
            p[i] /= 100;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &c[i], &d[i]);
        }

        for (int i = 0; i < MAXN; ++i) {
            x[i].clear();
            y[i].clear();
            z[i].clear();
        }

        thing(m);
        box(min(n, LIMIT), 0, 0, 1.0, x);
        if (n > LIMIT) {
            copy(v + LIMIT, v + n, v);
            copy(p + LIMIT, p + n, p);
        }
        box(max(n - LIMIT, 0), 0, 0, 1.0, y);

        for (int i = 0; i < MAXN; ++i) {
            sort(x[i].begin(), x[i].end());
            for (int j = 1; j < (int)x[i].size(); ++j) {
                x[i][j].second += x[i][j - 1].second;
            }
        }

        /*
        for (int i = 0; i < MAXN; ++i) {
            printf("x[%d] ", i);
            dump(x[i]);
            printf("y[%d] ", i);
            dump(y[i]);
            printf("z[%d] ", i);
            dump(z[i]);
            puts("");
        }
        */

        ans = 0;
        for (int i = 0; i < MAXN; ++i) {
            for (vector<pair<int, double> >::const_iterator it = y[i].begin(); it != y[i].end(); ++it) {
                double tmp = 0;
                for (int j = i; j < MAXN; ++j) {
                    const vector<pair<int, double> >& x = ::x[j - i];
                    for (vector<pair<int, int> >::const_iterator jt = z[j].begin(); jt != z[j].end(); ++jt) {
                        vector<pair<int, double> >::const_iterator begin, end;
                        begin = lower_bound(x.begin(), x.end(), make_pair(jt->first - it->first, 0.0));
                        if ((jt + 1) == z[j].end()) {
                            end = x.end();
                        } else {
                            end = lower_bound(x.begin(), x.end(), make_pair((jt + 1)->first - it->first, 0.0));
                        }
                        if (begin < end) {
                            // printf("+ %d * %lf * %lf\n", jt->second, it->second, (end - 1)->second - (begin == x.begin() ? 0.0 : (begin - 1)->second));
                            tmp += jt->second * ((end - 1)->second - (begin == x.begin() ? 0.0 : (begin - 1)->second));
                        }
                    }
                }
                ans += it->second * tmp;
            }
        }
        printf("%.4lf\n", ans);
    }

    return 0;
}

//Correct Answer
//Execution Time: 2.51
