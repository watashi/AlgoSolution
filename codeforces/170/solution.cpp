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
const int INF = 1000000007;
const clock_t TIME_LIMIT1 = 5 * CLOCKS_PER_SEC - CLOCKS_PER_SEC / 2;
const clock_t TIME_LIMIT2 = 5 * CLOCKS_PER_SEC - CLOCKS_PER_SEC / 10;

inline bool timeout1() {
    return clock() > TIME_LIMIT1;
}

inline bool timeout2() {
    return clock() > TIME_LIMIT2;
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

    int width() const {
       return x2 - x1;
    }

    int height() const {
       return y2 - y1;
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
            r[i].x1 = r[i].y1 = r[i].x2 = r[i].y2 = -1;
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

inline int common_(bool flag,
    int hl, const vector<pair<int, Rect> >& lhs,
    int hr, const vector<pair<int, Rect> >& rhs) {
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
            if (i->second.y2 >= hl && j->second.y2 >= hr) {
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

inline int common_fixed_(bool flag,
    int hl, const vector<pair<int, Rect> >& lhs,
    int hr, const vector<pair<int, Rect> >& rhs) {
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
            if (i->second.y2 == hl && j->second.y1 == hr) {
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

inline void summary(int& offy, vector<pair<int, Rect> >& row) {
    int y1 = 0, y2 = 0;
    for (auto& x: row) {
        offy = max(offy, x.second.y2);
        temp.score += max(0, min(y2, x.second.y2) - max(y1, x.second.y1));
        y1 = x.second.y1;
        y2 = x.second.y2;
    }
}

inline void append(int& offy, bool flag, const vector<pair<int, Rect> >& above, vector<pair<int, Rect> >& below) {
    auto it = above.begin();
    auto jt = below.begin();
    while (jt != below.end()) {
        int tmp = 0;
        while (it != above.end() && it->second.x2 <= jt->second.x1) {
            flag = !flag;
            ++it;
        }
        while (it != above.end() && it->second.x1 < jt->second.x2) {
            if (it->second.y2 == offy) {
                if (flag) {
                    tmp += min(it->second.x2, jt->second.x2) - max(it->second.x1, jt->second.x1);
                } else {
                    tmp -= min(it->second.x2, jt->second.x2) - max(it->second.x1, jt->second.x1);
                }
            }
            if (it->second.x2 <= jt->second.x2) {
                flag = !flag;
                ++it;
            } else {
                break;
            }
        }
        if (tmp >= 0) {
            temp.score += tmp;
            jt->second.shift(0, offy);
        } else {
            jt->second.shift(0, offy + 1);
        }
        flag = !flag;
        ++jt;
    }
    summary(offy, below);
}

vector<bool> bestheads;
vector<int> bestheights;
vector<vector<pair<int, Rect> > > bestrows;

inline void tryoptcol(
        const vector<bool>& heads,
        const vector<int>& heights,
        vector<vector<pair<int, Rect> > >& rows) {
    temp.clear(n);
    int m = (int)rows.size();
    for (auto& row: rows) {
        for (auto& x: row) {
            x.second.shift(0, -x.second.y1);
        }
    }
    int offy = 0;
    for (int i = 0; i < m; ++i) {
        if (i + 1 == m) {
            // LAST_LINE
            append(offy,
                i == 0 ? true : heads[i - 1] != heads[i],
                i == 0 ? vector<pair<int, Rect> >() : rows[i - 1],
                rows[i]);
        } else {
            // TWO_LINE
            vector<pair<int, Rect> > &above = rows[i], &below = rows[i + 1];
            static int dp[MAXN][2][2], pre[MAXN][2][2], pos[MAXN], last;
            static int idxi[MAXN], idxj[MAXN];
            pos[last = 0] = 0;
            fill(dp[0][0], dp[1][0], 0);
            bool flag = heads[i] != heads[i + 1];
            for (auto it = above.begin(), jt = below.begin(); it != above.end() && jt != below.end(); ) {
                bool inew = it->second.x1 == pos[last];
                bool jnew = jt->second.x1 == pos[last];
                idxi[last] = it - above.begin();
                idxj[last] = jt - below.begin();
                pos[++last] = min(it->second.x2, jt->second.x2);
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        dp[last][i][j] = -INF;
                        for (int ii = inew ? 0 : i; ii <= (inew ? 1 : i); ++ii) {
                            for (int jj = jnew ? 0 : j; jj <= (jnew ? 1 : j); ++jj) {
                                if (dp[last][i][j] < dp[last - 1][ii][jj]) {
                                    dp[last][i][j] = dp[last - 1][ii][jj];
                                    pre[last][i][j] = (ii << 1) ^ jj;
                                }
                            }
                        }
                    }
                }
                dp[last][0][0] += (flag ? 1 : -1) * (pos[last] - pos[last - 1]);
                if (it->second.x2 == pos[last]) {
                    flag = !flag;
                    ++it;
                }
                if (jt->second.x2 == pos[last]) {
                    flag = !flag;
                    ++jt;
                }
            }

            int ti = 0, tj = 0;
            {
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        if (dp[last][ti][tj] < dp[last][i][j]) {
                            ti = i;
                            tj = j;
                        }
                    }
                }
            }

            if (dp[last][ti][tj] <= 0) {
                // NOT COMBINE
                append(offy,
                    i == 0 ? true : heads[i - 1] != heads[i],
                    i == 0 ? vector<pair<int, Rect> >() : rows[i - 1],
                    rows[i]);
            } else {
                // COMBINE
                temp.score += dp[last][ti][tj];
                for (int r = idxi[last - 1] + 1; r < (int)above.size(); ++r) {
                    above[r].second.shift(0, offy + (heights[i] + 1 - above[r].second.y2));
                }
                /*
                for (int r = idxj[last] + 1; r < (int)below.size(); ++r) {
                    below[r].second.shift(0, 0);
                }
                */
                while (last > 0) {
                    int tti = pre[last][ti][tj] >> 1;
                    int ttj = pre[last][ti][tj] & 1;
                    --last;
                    if (pos[last] == above[idxi[last]].second.x1) {
                        above[idxi[last]].second.shift(0, offy + (heights[i] + 1 - ti - above[idxi[last]].second.y2));
                    }
                    if (pos[last] == below[idxj[last]].second.x1) {
                        below[idxj[last]].second.shift(0, tj);
                    }
                    ti = tti;
                    tj = ttj;
                }

                int gap = h;
                for (auto& x: above) {
                    gap = min(gap, x.second.y1 - offy);
                }
                for (auto& x: above) {
                    x.second.shift(0, -gap);
                }

                int tmp = i == 0 ? 0 : common_fixed_(heads[i - 1] != heads[i], offy, rows[i - 1], offy, above);
                if (tmp < 0) {
                    for (auto& x: above) {
                        x.second.shift(0, 1);
                    }
                    ++offy;
                } else {
                    temp.score += tmp;
                }

                summary(offy, above);
                for (auto& x: below) {
                    x.second.shift(0, offy);
                }
                summary(offy, below);
                ++i; // SKIP_NEXT_LINE
            }
        }
    }
    if (offy <= h && temp.score > best.score) {
        for (auto& row: rows) {
            for (auto& x: row) {
                temp.r[x.first] = x.second;
            }
        }
        bestheads = heads;
        bestheights = heights;
        bestrows = rows;
        upd();
    }
}

inline void trydpcol(
        const vector<bool>& heads,
        const vector<int>& heights,
        vector<vector<pair<int, Rect> > >& rows,
        int basescore) {
    static int dp[MAXR][2], pre[MAXR][2];
    int m = (int)rows.size();

    temp.clear(n);
    temp.score += basescore;

    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]);
            pre[i][j] = dp[i - 1][0] >= dp[i - 1][1] ? 2 : 3;
            for (int k = 0; k < 2; ++k) {
                int tmp = common_(heads[i - 1] != heads[i],
                    k == 0 ? heights[i - 1] : 0, rows[i - 1],
                    j == 0 ? 0 : heights[i], rows[i]);
                if (dp[i][j] <= dp[i - 1][k] + tmp) {
                    dp[i][j] = dp[i - 1][k] + tmp;
                    pre[i][j] = k;
                }
            }
        }
    }

    int jj = dp[m - 1][0] >= dp[m - 1][1] ? 0 : 1;
    temp.score += dp[m - 1][jj];
#ifdef DEBUG_WITH_LOG
    fprintf(stderr, "score = %d\n", temp.score);
#endif
    int offy = h;
    for (int i = m - 1, j = jj; i >= 0; j = pre[i][j] % 2, --i) {
        for (auto& x: rows[i]) {
            x.second.shift(0, j == 0 ? offy - heights[i] : offy - x.second.y2);
            temp.r[x.first] = x.second;
        }
        offy -= heights[i];
        if (pre[i][j] >= 2) {
            --offy;
        }
    }
    upd();

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
    // int zebratype = rand(5);
#ifdef DEBUG_WITH_LOG
    printf("[%d]", m);
    for (int i: v) {
        printf(" %d", i);
    }
    puts("");
#endif
    int basescore = 0;
    //temp.clear(n);
    // bool fpre = false, fcur;
    // vector<pair<int, Rect> > pre, cur;
    vector<bool> heads;
    vector<int> heights;
    vector<vector<pair<int, Rect> > > rows;
    // int offy = 0;
    int k = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        vector<pair<int, Rect> > cur;
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

        int pq = -1, qp = -1;
        vector<pair<int, Rect> > pp, qq;
        // if (zebratype >= 2 || i % 2 == zebratype) {
        trycol_(p, q, pq, pp);
        // }
        // if (zebratype >= 2 || i % 2 != zebratype) {
        trycol_(q, p, qp, qq);
        // }
        if (pq > qp) {
            heads.push_back(false);
            // fcur = false;
            cur.swap(pp);
        } else {
            heads.push_back(true);
            // fcur = true;
            cur.swap(qq);
        }

        int offx = 0;
        vi = 0;
        for (auto& x: cur) {
            x.second.shift(offx, 0);
            offx = x.second.x2;
            vi = max(vi, x.second.y2);
        }
        heights.push_back(vi);

        // temp.score += max(pq, qp);
        basescore += max(pq, qp);
        // int tmp = common_(fpre != fcur, offy, pre, cur);
        int tmp = i == 0 ? 0 : common_(heads[i - 1] != heads[i],
            heights[i - 1], rows.back(),
            0, cur);
        if (i == 0) {
        } else if (tmp < 0) {
            // ++offy;
        } else {
            if (i + 1 < (int)v.size()) {
                ++v[i + 1];
            }
            // temp.score += tmp;
        }

        // pre = cur;
        sort(cur.begin(), cur.end(),
            [](const pair<int, Rect>& lhs, const pair<int, Rect>& rhs){ return lhs.first < rhs.first; });
        for (auto& x: cur) {
            swap(r[k], r[x.first]);
            x.first = r[k].id;
            // temp.r[r[k].id] = x.second;
            ++k;
        }
        sort(cur.begin(), cur.end(),
            [](const pair<int, Rect>& lhs, const pair<int, Rect>& rhs){ return lhs.second.x1 < rhs.second.x1; });
        rows.push_back(cur);
        // offy += vi;
#ifdef DEBUG_WITH_LOG
        printf("#%d h=%d [%d|%d|%d] => %d\n", i, vi, p.size(), q.size(), cur.size(), temp.score);
#endif
    }

    int score = 0;
    trydpcol(heads, heights, rows, basescore);
    score = max(score, temp.score);
    tryoptcol(heads, heights, rows);
    score = max(score, temp.score);
    //tryoptcol(heads, heights, rows, true);
    //score = max(score, temp.score);
    if (score * 3 >= best.score * 2) {
        reverse(heads.begin(), heads.end());
        reverse(heights.begin(), heights.end());
        reverse(rows.begin(), rows.end());
        //trydpcol(heads, heights, rows, basescore);
        //score = max(score, temp.score);
        tryoptcol(heads, heights, rows);
        score = max(score, temp.score);
        //tryoptcol(heads, heights, rows, true);
        //score = max(score, temp.score);
    }

    for (int i = 2; i <= 12; ++i) {
        if (score * (i + 1) >= best.score * i) {
            for (int j = 0; j < m; ++j) {
                int k = rand(m);
                bool swp = heads[j];
                heads[j] = heads[k];
                heads[k] = swp;
                swap(heights[j], heights[k]);
                rows[j].swap(rows[k]);
                if (rows[j].size() % 2 == 0 && rand(3) == 0) {
                    heads[j] = !heads[j];
                    for (int t = 0; t < (int)rows[j].size(); t += 2) {
                        int w1 = rows[j][t].second.width();
                        int w2 = rows[j][t + 1].second.width();
                        rows[j][t].second.shift(w2, 0);
                        rows[j][t + 1].second.shift(-w1, 0);
                        swap(rows[j][t], rows[j][t + 1]);
                    }
                }
            }
            //trydpcol(heads, heights, rows, basescore);
            //score = max(score, temp.score);
            tryoptcol(heads, heights, rows);
            score = max(score, temp.score);
            //tryoptcol(heads, heights, rows, true);
            //score = max(score, temp.score);
        }
    }
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
    int counter = 0;
    //fprintf(stderr, "score = %d; counter = %d\n", best.score, counter);
    while (!timeout2()) {
        ++counter;
#ifdef DEBUG_WITH_LOG
        if (counter > 10) {
            break;
        }
#endif
        // random_shuffle(r, r + n);

        // tryrow();
        trycol();
        if (counter % 100 == 0) {
            rot();
        }
    }
    fprintf(stderr, "score = %d; counter0 = %d\n", best.score, counter);

    if (false && !bestheads.empty()) {
        int m = (int)bestheads.size();
        vector<int> perm;
        for (int i = 0; i < m; ++i) {
            perm.push_back(i);
        }
        while (!timeout2()) {
            ++counter;
            random_shuffle(perm.begin(), perm.end());
            vector<bool> heads;
            vector<int> heights;
            vector<vector<pair<int, Rect> > > rows;
            for (int i: perm) {
                heads.push_back(bestheads[i]);
                heights.push_back(bestheights[i]);
                rows.push_back(bestrows[i]);
                vector<pair<int, Rect> >& row = rows.back();
                if (rand(2) == 0) {
                    if (row.size() % 2 == 0) {
                        heads.back() = !heads.back();
                        for (int t = 0; t < (int)row.size(); t += 2) {
                            int w1 = row[t].second.width();
                            int w2 = row[t + 1].second.width();
                            row[t].second.shift(w2, 0);
                            row[t + 1].second.shift(-w1, 0);
                            swap(row[t], row[t + 1]);
                        }
                    } else if (rand(3) == 0) {
                        heads.back() = !heads.back();
                        int w = row[0].second.width();
                        row.erase(row.begin());
                        for (auto& x: row) {
                            x.second.shift(-w, 0);
                        }
                    }
                }
            }
            tryoptcol(heads, heights, rows);
        }
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

