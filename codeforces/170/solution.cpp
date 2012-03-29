#include <ctime>
#include <cstdio>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

//#define DEBUG_WITH_LOG

const int MAXR = 20;
const int MAXN = 128;
const int MAXM = 1024;
const clock_t TIME_LIMIT = 5 * CLOCKS_PER_SEC - CLOCKS_PER_SEC / 10;

inline bool timeout() {
    return clock() > TIME_LIMIT;
}

inline int rand(int n) {
    return rand() % n;
}

inline int rand(int a, int b) {
    return a + rand() % (b - a);
}

inline int square(int x) {
    return x * x;
}

int w, h, n;

struct Rect {
    int x1, y1, x2, y2;

    Rect() {
    }

    Rect(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {
    }

    void rot() {
        swap(x1, y1);
        swap(x2, y2);
    }

    void shift(int x0, int y0) {
        x1 += x0;
        y1 += y0;
        x2 += x0;
        y2 += y0;
    }

    static void show(int x, char ch) {
        printf("%d.%d", x / 10, x % 10);
        putchar(ch);
    }

    void show() const {
        if (x1 == -1 || y1 == -1) {
            printf("-1 -1 -1 -1\n");
        } else {
            show(x1, ' ');
            show(y1, ' ');
            show(x2, ' ');
            show(y2, '\n');
        }
    }
};

struct Rectangle {
    int w, h, l, r;
    int id;
    bool flag;

    void set(bool flag) {
        if (this->flag != flag) {
            this->flag = flag;
            swap(w, h);
        }
    }

    int ratio(int x) const {
        if (x < l) {
            return l;
        } else if (x < r) {
            return x;
        } else {
            return r;
        }
    }

    Rect scale(int x) const {
        int y = ratio(x);
        return Rect(0, 0, w * y, h * y);
    }
} r[MAXN];

struct Result {
    bool flag;
    int score;
    Rect r[MAXN];

    bool operator<(const Result& o) const {
        return score < o.score;
    }

    void clear(int n) {
        score = 0;
        for (int i = 0; i < n; ++i) {
            r[i].x1 = -1;
        }
    }
} temp, best;

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline int ceil(int a, int b) {
    return (a + b - 1) / b;
}

inline void rot() {
    swap(w, h);
    for (int i = 0; i < n; ++i) {
        swap(r[i].w, r[i].h);
    }
    temp.flag = !temp.flag;
}

inline void upd() {
    if (best.score < temp.score) {
        best = temp;
    }
}

inline void trylr() {
    for (int i = 0; i < n; ++i) {
        r[i].set(false);
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            r[j].set(true);
            int lo = max(r[i].h * r[i].l, r[j].h * r[j].l), hi = h + 1;
            if (lo >= hi) {
                continue;
            }
            while (lo < hi) {
                int mi = (lo + hi) / 2;
                Rect x = r[i].scale(ceil(mi, r[i].h));
                Rect y = r[j].scale(ceil(mi, r[j].h));
                if (mi <= x.y2 && mi <= y.y2 && x.y2 <= h && y.y2 <= h && x.x2 + y.x2 <= w) {
                    lo = mi + 1;
                } else {
                    hi = mi;
                }
            }
            if (best.score < lo - 1) {
                int mi = lo - 1;
                Rect& x = temp.r[r[i].id];
                Rect& y = temp.r[r[j].id];
                temp.clear(n);
                temp.score = mi;
                x = r[i].scale(ceil(mi, r[i].h));
                y = r[j].scale(ceil(mi, r[j].h));
                y.shift(x.x2, 0);
                upd();
            }
        }
    }
}

inline vector<int> split(int s, int n) {
    vector<int> a, c;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        a.push_back(rand(10086, 65536));
        b += a.back();
    }
    for (int i = 0; i < n; ++i) {
        c.push_back(s * a[i] / b);
        s -= c[i];
        b -= a[i];
    }
    return c;
}

inline int common(const vector<pair<int, int> >& lhs, const vector<pair<int, int> >& rhs) {
    int ret = 0;
    int pos = 0;
    for (auto it = lhs.begin(), jt = rhs.begin(); it != lhs.end() && jt != rhs.end(); ) {
        pos = max(pos, max(it->first, jt->first));
        if (it->second <= pos) {
            ++it;
        } else if (jt->second <= pos) {
            ++jt;
        } else {
            int tmp = min(it->second, jt->second);
            ret += tmp - pos;
            pos = tmp;
        }
    }
    return ret;
}

inline void tryrow() {
    int m = rand(2, min(n + 1, MAXR));
    vector<int> v = split(h, m);
    /*
    if (*min_element(v.begin(), v.end()) <= 0) {
        return;
    }
    */
    v.erase(remove_if(v.begin(), v.end(), bind2nd(less<int>(), 2)), v.end());
    if (v.empty()) {
        return;
    }
    /*
       printf("[%d]", m);
       for (int i: v) {
       printf(" %d", i);
       }
       puts("");
       */

    // pack
    vector<vector<pair<int, Rect> > > z(m);
    for (int i = 1, k = 0; i <= m && k < n; ++i) {
        // printf("%d:%d\n", i, k);
        int vi = v[i % m];
        vector<pair<int, Rect> >& zi = z[i % m];
        bool flag = (i % m % 2 == 0);
        for (int j = k; j < n; ++j) {
            r[j].set(flag);
        }
        sort(r + k, r + n, [vi](const Rectangle& lhs, const Rectangle& rhs) {
            Rect x = lhs.scale(vi / lhs.h);
            Rect y = rhs.scale(vi / rhs.h);
            if (x.y2 == vi) {
            return y.y2 != vi || x.x2 > y.x2;
            } else if (x.y2 < vi) {
            return y.y2 > vi || (y.y2 < vi && x.x2 > y.x2);
            } else {
            return false;
            }
            });
        int off = -1;
        for (int j = k; j < n; ++j) {
            Rect x = r[j].scale(vi / r[j].h);
            if (x.y2 > vi) {
                break;
            } else if (off + 1 + x.x2 > w) {
                continue;
            } else {
                off += 1 + x.x2;
                zi.push_back({r[j].id, x});
                swap(r[j], r[k]);
                ++k;
            }
        }
    }

    // score
    static int dp[MAXR][2], pre[MAXR][2];
    static vector<pair<int, int> > more[MAXR], less[MAXR];
    for (int i = 0; i < m; ++i) {
        int offx = 0;
        v[i] = 1;
        more[i].clear();
        for (auto& x: z[i]) {
            x.second.shift(offx, 0);
            more[i].push_back({x.second.x1, x.second.x2});
            offx = x.second.x2 + 1;
            v[i] = max(v[i], x.second.y2);
        }
        less[i].clear();
        for (auto& x: z[i]) {
            if (x.second.y2 == v[i]) {
                less[i].push_back({x.second.x1, x.second.x2});
            }
        }
    }
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = 0;
            pre[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                int tmp = common(
                    k == 0 ? less[i - 1] : more[i - 1],
                    j == 0 ? more[i] : less[i]);
                if (dp[i][j] < dp[i - 1][k] + tmp) {
                    dp[i][j] = dp[i - 1][k] + tmp;
                    pre[i][j] = k;
                }
            }
        }
    }
    if (dp[m - 1][0] <= best.score) {
        return;
    }
    temp.clear(n);
    temp.score = dp[m - 1][0];
    int offy = h;
    for (int i = m - 1, j = 0; i >= 0; j = pre[i][j], --i) {
        for (auto& x: z[i]) {
            x.second.shift(0, j == 0 ? offy - v[i] : offy - x.second.y2);
            temp.r[x.first] = x.second;
        }
        offy -= v[i];
    }
    // printf("temp.score = %d\n", temp.score);
    upd();
}

typedef pair<double, pair<int, Rect> > HVRec;

inline void trycol_(const vector<HVRec>& p, const vector<HVRec>& q, int& s, vector<pair<int, Rect> >& ret) {
    static int stamp = 0, tag[MAXN];
    auto ip = p.begin(), iq = q.begin();
    vector<pair<int, Rect> > pp, qq;
    int offx = 0;

    s = 0;
    ret.clear();
    ++stamp;
    while (true) {
        auto& it = pp.size() <= qq.size() ? ip : iq;
        auto& v = pp.size() <= qq.size() ? p : q;
        auto& vv = pp.size() <= qq.size() ? pp : qq;
        if (it == v.end()) {
            break;
        } else if (tag[it->second.first] == stamp || offx + it->second.second.x2 > w) {
            ++it;
            continue;
        } else {
            tag[it->second.first] = stamp;
            vv.push_back(it->second);
            offx += it->second.second.x2;
            ++it;
        }
    }

    sort(pp.begin(), pp.end(),
        [](const pair<int, Rect>& lhs, const pair<int, Rect>& rhs){
            return lhs.second.y2 > rhs.second.y2; });
    sort(qq.begin(), qq.end(),
        [](const pair<int, Rect>& lhs, const pair<int, Rect>& rhs){
            return lhs.second.y2 > rhs.second.y2; });

    for (int i = 0; ; ++i) {
        if (i % 2 == 0) {
            if (i / 2 < (int)pp.size()) {
                ret.push_back(pp[i / 2]);
            } else {
                break;
            }
        } else {
            if (i / 2 < (int)qq.size()) {
                ret.push_back(qq[i / 2]);
            } else {
                break;
            }
        }
        if (i > 0) {
            s += min(ret[i - 1].second.y2, ret[i].second.y2);
        }
    }
}

inline int common_(bool flag, int offy, const vector<pair<int, Rect> >& lhs, const vector<pair<int, Rect> >& rhs) {
    int ret = 0, pos = 0;
    for (auto i = lhs.begin(), j = rhs.begin(); i != lhs.end() && j != rhs.end(); ) {
        if (i->second.x2 <= pos) {
            ++i;
            flag = !flag;
        } else if (j->second.x2 <= pos) {
            ++j;
            flag = !flag;
        } else {
            int tmp = min(i->second.x2, j->second.x2);
            if (i->second.y2 == offy) {
                if (flag) {
                    ret += tmp - pos;
                } else {
                    ret -= tmp - pos;
                }
            }
            pos = tmp;
        }
    }
    return ret;
}

inline void trycol() {
    int m = rand(1, min(n, MAXR) / 2 + 2);
    vector<int> v = split(h + 1, m);
    if (*min_element(v.begin(), v.end()) <= 1) {
        return;
    }

    if (rand(2) == 0) {
        sort(v.rbegin(), v.rend());
    }
#ifdef DEBUG_WITH_LOG
       printf("[%d]", m);
       for (int i: v) {
       printf(" %d", i);
       }
       puts("");
#endif
    temp.clear(n);
    bool fpre = false, fcur;
    vector<pair<int, Rect> > pre, cur;
    int offy = 0;
    for (int i = 0, k = 0; i < (int)v.size() && k < n; ++i) {
        int vi = v[i] - 1;
        vector<HVRec> p, q;
        for (int j = k; j < n; ++j) {
            Rect x;
            r[j].set(false);
            x = r[j].scale(vi / r[j].h);
            if (x.y2 <= vi) {
                p.push_back({x.x2 + abs(vi - x.y2), {j, x}});
            }
            r[j].set(true);
            x = r[j].scale(vi / r[j].h);
            if (x.y2 <= vi) {
                q.push_back({x.x2 + abs(vi - x.y2), {j, x}});
            }
        }
        sort(p.begin(), p.end(),
            [](const HVRec& lhs, const HVRec& rhs){ return lhs.first < rhs.first; });
        sort(q.begin(), q.end(),
            [](const HVRec& lhs, const HVRec& rhs){ return lhs.first < rhs.first; });

        int pq, qp;
        vector<pair<int, Rect> > pp, qq;
        trycol_(p, q, pq, pp);
        trycol_(q, p, qp, qq);
        if (pq > qp) {
            fcur = false;
            cur.swap(pp);
        } else {
            fcur = true;
            cur.swap(qq);
        }

        int offx = 0;
        vi = 0;
        for (auto& x: cur) {
            x.second.shift(offx, 0);
            offx = x.second.x2;
            vi = max(vi, x.second.y2);
        }

        temp.score += max(pq, qp);
        int tmp = common_(fpre != fcur, offy, pre, cur);
        if (i == 0) {
        } else if (tmp < 0) {
            ++offy;
        } else {
            if (i + 1 < (int)v.size()) {
                ++v[i + 1];
            }
            temp.score += tmp;
        }
        for (auto& x: cur) {
            x.second.shift(0, offy);
        }
        fpre = fcur;
        pre = cur;
        sort(cur.begin(), cur.end(),
            [](const pair<int, Rect>& lhs, const pair<int, Rect>& rhs){ return lhs.first < rhs.first; });
        for (auto& x: cur) {
            swap(r[k], r[x.first]);
            temp.r[r[k].id] = x.second;
            ++k;
        }
        offy += vi;
#ifdef DEBUG_WITH_LOG
        printf("#%d h=%d [%d|%d|%d] => %d\n", i, vi, p.size(), q.size(), cur.size(), temp.score);
#endif
    }
    upd();
}

int main() {
    // input
    scanf("%d%d%d", &w, &h, &n);
    w *= 10;
    h *= 10;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &r[i].w, &r[i].h);
        int g = gcd(r[i].w, r[i].h);
        r[i].w = r[i].w / g;
        r[i].h = r[i].h / g;
        r[i].l = g;
        r[i].r = 20 * g;
        r[i].id = i;
        r[i].flag = false;
    }
    fprintf(stderr, "%d x %d @ %d\n", w, h, n);

    // process
    temp.flag = best.flag = false;
    best.clear(n);
    trylr();
    rot();
    trylr();
    rot();
    int counter = 0;
    fprintf(stderr, "score = %d; counter = %d\n", best.score, counter);
    while (!timeout()) {
        ++counter;
#ifdef DEBUG_WITH_LOG
        if (counter > 10) {
           break;
        }
#endif
        // random_shuffle(r, r + n);

        // tryrow();
        trycol();
        rot();
    }
    fprintf(stderr, "score = %d; counter = %d\n", best.score, counter);

    // output
    for (int i = 0; i < n; ++i) {
        if (best.flag) {
            best.r[i].rot();
        }
        best.r[i].show();
    }

    return 0;
}

