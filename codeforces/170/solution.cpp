#include <ctime>
#include <cstdio>
#include <chrono>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const clock_t TIME_LIMIT = 5 * CLOCKS_PER_SEC - CLOCKS_PER_SEC / 5;

inline bool timeout() {
    return clock() > TIME_LIMIT;
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
            int lo = 1, hi = h + 1;
            while (lo < hi) {
                int mi = (lo + hi) / 2;
                Rect x = r[i].scale(ceil(mi, r[i].h));
                Rect y = r[j].scale(ceil(mi, r[j].h));
                if (x.y2 <= h && y.y2 <= h && x.x2 + y.x2 <= w) {
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

    // process
    temp.flag = best.flag = false;
    best.clear(n);
    trylr();
    rot();
    trylr();
    rot();
    while (!timeout()) {
        break;
    }

    // output
    fprintf(stderr, "score = %d\n", best.score);
    for (int i = 0; i < n; ++i) {
        if (best.flag) {
            best.r[i].rot();
        }
        best.r[i].show();
    }

    return 0;
}

