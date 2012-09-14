#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dump(const vector<int>& v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        printf("%d ", v[i]);
    }
    puts("");
}

vector<int> P[16], Q[16];

// {any_different_set}
map<int, int> minv(int n, const vector<int>& p) {
    map<int, int> ret;
    for (int i = 0; i < n; ++i) {
        ret[p[i]] = i;
    }
    return ret;
}

// {0 .. n - 1}
vector<int> inv(int n, const vector<int>& p) {
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
        ret[p[i]] = i;
    }
    return ret;
}

// {any} -> {any} = {0 .. n - 1}
vector<int> per(int n, const vector<int>& s, const vector<int>& t) {
    //  printf("S = ");
    //  dump(s);
    //  printf("T = ");
    //  dump(t);
    map<int, int> rt = minv(n, t);
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
        ret[i] = rt[s[i]];
    }
    //  printf("P = ");
    //  dump(ret);
    //  return ret;
    return inv(ret.size(), ret);
}

vector<string> gao(int n, vector<int> p) {
    //  printf("GAO(%d): ", n);
    //  dump(p);
    if (n == 1) {
        if (p[0] == 0) {
            // {0, 1}
            return vector<string>(1, "0");
        } else {
            // {1, 0}
            return vector<string>(1, "1");
        }
    } else {
        int s = 1 << n;
        int m = 1 << (n - 1);
        vector<int> rp = inv(s, p);
        vector<int> d(s, 0);

        for (int i = 0; i < s; ++i) {
            if (d[i] != 0) {
                continue;
            }
            // assert((i & 1) == 0);
            queue<int> q;
            d[i] = -1;  // (P[n][i] < m)
            q.push(i);
            while (!q.empty()) {
                int k = q.front();
                q.pop();
                if (d[k ^ 1] == 0) {
                    d[k ^ 1] = -d[k];
                    q.push(k ^ 1);
                }
                if (d[p[rp[k] ^ 1]] == 0) {
                    d[p[rp[k] ^ 1]] = -d[k];
                    q.push(p[rp[k] ^ 1]);
                }
            }
        }

        vector<int> xs, xt, ys, yt;
        string x, y;
        for (int i = 0; i < s; i += 2) {
            if (d[i] == -1) {
                x += '0';
                xs.push_back(i);
                ys.push_back(i ^ 1);
            } else {
                x += '1';
                ys.push_back(i);
                xs.push_back(i ^ 1);
            }
        }
        for (int i = 0; i < s; i += 2) {
            if (d[p[i]] == -1) {
                y += '0';
                xt.push_back(p[i]);
                yt.push_back(p[i ^ 1]);
            } else {
                y += '1';
                yt.push_back(p[i]);
                xt.push_back(p[i ^ 1]);
            }
        }

        vector<string> ret, left, right;
        ret.push_back(x);
        //      printf("LEFT:\n");
        //      dump(xs);
        //      dump(xt);
        //      printf("RIGHT:\n");
        //      dump(ys);
        //      dump(yt);
        left = gao(n - 1, per(m, xs, xt));
        right = gao(n - 1, per(m, ys, yt));
        for (int i = 0; i < (int)left.size(); ++i) {
            ret.push_back(left[i] + right[i]);
        }
        ret.push_back(y);
        return ret;
    }
}

void init() {
    for (int n = 1; n <= 13; ++n) {
        P[n].resize(1 << n);
        for (int j = 0; j < (int)P[n].size(); ++j) {
            P[n][j] = (j >> 1) ^ ((j & 1) << (n - 1));
        }
        Q[n] = inv(P[n].size(), P[n]);
    }
}

int main() {
    bool blank = false;
    int n;
    vector<int> p;
    vector<string> s;

    init();
    while (scanf("%d", &n) != EOF && n > 0) {
        if (blank) {
            puts("");
        } else {
            blank = true;
        }
        p.resize(1 << n);
        for (int i = 0; i < (int)p.size(); ++i) {
            scanf("%d", &p[i]);
        }
        s = gao(n, p);
        for (int i = 0; i < (int)s.size(); ++i) {
            puts(s[i].c_str());
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//2377775   2010-12-25 21:11:00     Accepted    3393    C++     480     1012    watashi@Zodiac  Source

// 2012-09-07 02:08:58 | Accepted | 3393 | C++ | 480 | 1012 | watashi | Source
