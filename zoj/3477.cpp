#include <cstdio>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>

using namespace std;

inline bool odd(int x) {
    return x % 2 != 0;
}

struct Rect {
    bool _valid;
    int a1, a2, b1, b2;

    Rect(int x, int y, int z) : _valid(true) {
        a1 = x + y - z;
        a2 = x + y + z;
        b1 = x - y - z;
        b2 = x - y + z;
        valid();
    }

    bool valid() {
        for (bool loop = true; loop && _valid; _valid &= a1 <= a2 && b1 <= b2) {
            loop = false;
            if (a1 == a2) {
            //  if (a1 % 2 != b1 % 2) { BUG: a1 > 0 && b1 < 0 ...
                if (odd(a1) != odd(b1)) {
                    ++b1;
                    loop = true;
                }
                if (odd(a1) != odd(b2)) {
                    --b2;
                    loop = true;
                }
            }
            if (b1 == b2) {
                if (odd(b1) != odd(a1)) {
                    ++a1;
                    loop = true;
                }
                if (odd(b1) != odd(a2)) {
                    --a2;
                    loop = true;
                }
            }
        }
        return _valid;
    }

    bool intersect(const Rect& r) const {
        return a1 < r.a2 && r.a1 < a2 && b1 < r.b2 && r.b1 < b2;
    }

    void cut(Rect r, vector<Rect>& v) const {
        if (r.a1 <= a1) {
            v.push_back(r);
            v.back().a2 = a1;
            r.a1 = a1;
        }
        if (r.a2 >= a2) {
            v.push_back(r);
            v.back().a1 = a2;
            r.a2 = a2;
        }
        if (r.b1 <= b1) {
            v.push_back(r);
            v.back().b2 = b1;
            r.b1 = b1;
        }
        if (r.b2 >= b2) {
            v.push_back(r);
            v.back().b1 = b2;
            r.b2 = b2;
        }
    }

    void cutBy(int x1, int y1, int x2, int y2) {
        a1 = max(a1, x1 + y1);
        a2 = min(a2, x2 + y2);
        b1 = max(b1, x1 - y2);
        b2 = min(b2, x2 - y1);
    }

    void upd(pair<int, int>& p) const {
        p = min(p, make_pair((a1 + b1) / 2, (a1 - b1) / 2));
        p = min(p, make_pair((a1 + b2) / 2, (a1 - b2) / 2));
        p = min(p, make_pair((a2 + b1) / 2, (a2 - b1) / 2));
        p = min(p, make_pair((a2 + b2) / 2, (a2 - b2) / 2));
    }
};

const int MAXN = 256;
int x[MAXN], y[MAXN], z[MAXN];

void gao(int r, int c, int n, int d, vector<Rect>& ret, bool debug = false) {
    ret.clear();
    ret.push_back(Rect(1, 1, r + c));

    for (int i = 0; i < n; ++i) {
        if (z[i] > d) {
            continue;
        }
        Rect tmp(x[i], y[i], d - z[i]);
        vector<Rect> swp;
        for (vector<Rect>::const_iterator it = ret.begin(); it != ret.end(); ++it) {
            if (tmp.intersect(*it)) {
                tmp.cut(*it, swp);
            } else {
                swp.push_back(*it);
            }
        }
        ret.clear();
        for (vector<Rect>::iterator it = swp.begin(); it != swp.end(); ++it) {
            if (it->valid()) {
                ret.push_back(*it);
            }
        }
    }

    vector<Rect> swp;
    for (vector<Rect>::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        it->cut(*it, swp);
    }
    ret.clear();
    for (vector<Rect>::iterator it = swp.begin(); it != swp.end(); ++it) {
        if (!it->valid()) {
        } else if (it->a1 == it->a2) {
            it->cutBy(max(1, it->a1 - c), max(1, it->a1 - r),
                min(r, it->a1 - 1), min(c, it->a1 - 1));
        } else if (it->b1 == it->b2) {
            it->cutBy(max(1, 1 + it->b1), max(1, 1 - it->b1),
                min(r, c + it->b1), min(c, r - it->b1));
        } else {
            throw 1;
        }
        if (it->valid()) {
            ret.push_back(*it);
        }
    }
}

int main() {
    char ch;
    vector<Rect> v;
    pair<int, int> p;
    int re, r, c, n, lo, up, mi, diff;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        assert(scanf("%d%d%d%c", &r, &c, &n, &ch) == 4 && ch == '\n');
        assert(1 <= r && r <= (1 << 20) && 1 <= c && c <= (1 << 19) && 1 <= n && n <= 218);
        for (int i = 0; i < n; ++i) {
            assert(scanf("%d%d%d%c", &x[i], &y[i], &z[i], &ch) == 4 && ch == '\n');
        }
        assert(scanf("%c", &ch) == 1 && ch == '\n');
        diff = *min_element(z, z + n);
        for (int i = 0; i < n; ++i) {
            z[i] -= diff;
        }

        lo = 0;
        up = r + c + 100;
        while (lo < up) {
            mi = (lo + up) / 2;
            gao(r, c, n, mi, v);
            if (!v.empty()) {
                lo = mi + 1;
            } else {
                up = mi;
            }
        }
        assert(up < r + c);

        --up;
        printf("%d ", diff + up);
        if (up == 0) {
            printf("(%d, %d)\n", 1, 1);
        } else {
            gao(r, c, n, up, v, true);
            p = make_pair(r, c);
            for (vector<Rect>::const_iterator it = v.begin(); it != v.end(); ++it) {
                it->upd(p);
            }
            printf("(%d, %d)\n", p.first, p.second);
        }
    }
    assert(scanf("%c", &ch) == EOF);

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//210   2011-04-03 01:06:35     Accepted    A   C++     1920    180     watashi     Source

// 2012-09-07 16:00:03 | Accepted | 3477 | C++ | 1620 | 184 | watashi | Source
