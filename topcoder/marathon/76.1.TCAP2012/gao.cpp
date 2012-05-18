#include <cmath>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <sys/time.h>

using std::fill;
using std::copy;
using std::sort;
using std::pair;
using std::vector;
using std::string;
using std::make_pair;

typedef long long llint;

timeval startti, endti;
llint startll, endll;

void startTimer() {
    gettimeofday(&startti, NULL);
    startti.tv_sec += 9;
    startti.tv_usec += 654321;
    startll = startti.tv_sec * 1000000LL + startti.tv_usec;
}

bool timeout() {
    gettimeofday(&endti, NULL);
    endll = endti.tv_sec * 1000000LL + endti.tv_usec;
    return endll > startll;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void split(const string& s, T* ret) {
    std::istringstream iss(s);
    while (iss >> *ret) {
        ++ret;
    }
}

const int MAXN = 2012;
const int MAXZ = 1000;
const int DIMENSION = 10;

#define USE_DOUBLE 0

#if USE_DOUBLE
typedef double real;
#define sqrt_ sqrt
#define fabs_ fabs
#else
typedef float real;
#define sqrt_ sqrtf
#define fabs_ fabsf
#endif

template<typename T>
struct Point {
    T p[DIMENSION];

    void clear() {
        fill(p, p + DIMENSION, 0);
    }

    T& operator[](int i) {
        return p[i];
    }

    const T& operator[](int i) const {
        return p[i];
    }

    void parse(const string& s) {
        split(s, p);
    }

    string str() const {
        std::ostringstream oss;
        for (int i = 0; i < DIMENSION; ++i) {
            if (i > 0) {
                oss << ' ';
            }
            oss << p[i];
        }
        return oss.str();
    }

    Point operator-() const {
        Point ret;
        for (int i = 0; i < DIMENSION; ++i) {
            ret[i] = -p[i];
        }
        return ret;
    }

    Point operator*(T q) const {
        Point ret;
        for (int i = 0; i < DIMENSION; ++i) {
            ret[i] = p[i] * q;
        }
        return ret;
    }

    template<typename S>
    Point operator+(const Point<S>& q) const {
        Point ret;
        for (int i = 0; i < DIMENSION; ++i) {
            ret[i] = p[i] + q[i];
        }
        return ret;
    }

    template<typename S>
    Point operator-(const Point<S>& q) const {
        Point ret;
        for (int i = 0; i < DIMENSION; ++i) {
            ret[i] = p[i] - q[i];
        }
        return ret;
    }

    T abs2() const {
        T ret = 0;
        for (int i = 0; i < DIMENSION; ++i) {
            ret += ::sqr(p[i]);
        }
        return ret;
    }

    real abs() const {
        return sqrt_(abs2());
    }
};

const int MAXSTEP = MAXN;
const real RATE = 1.0;
const real GRAVITY = 1.0;

int n;
real sp, sq;
Point<int> p[MAXN], q[MAXN], r[MAXN];
real mind[MAXN], maxd[MAXN];
int rank[MAXN][MAXN];

void upd() {
    if (sq > sp) {
        sq = sp;
        copy(p, p + n, q);
    }
}

void gao(real rate) {
    static Point<real> v[MAXN];
    static Point<int> w[MAXN][MAXN];
    static real dw[MAXN][MAXN], dd[MAXN][MAXN];

    for (int i = 0; i < n; ++i) {
        if ((i & 0x3f) == 0 && timeout()) {
            return;
        }
        w[i][i].clear();
        dw[i][i] = 0;
        for (int j = 0; j < i; ++j) {
            w[i][j] = p[j] - p[i];
            w[j][i] = -w[i][j];
            dw[i][j] = dw[j][i] = w[i][j].abs();
        }
    }
    for (int i = 0; i < n; ++i) {
        if ((i & 0x3f) == 0 && timeout()) {
            return;
        }
        copy(dw[i], dw[i] + n, dd[i]);
        sort(dd[i], dd[i] + n);
    }

    sp = 0;
    for (int i = 0; i < n; ++i) {
        if ((i & 0x3f) == 0 && timeout()) {
            return;
        }
        real s = 0.0;
        v[i].clear();
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            real t = 0.0;
            if (dw[i][j] < mind[i]) {
                t += dw[i][j] - mind[i];
            } else if (dw[i][j] > maxd[i]) {
                t += dw[i][j] - maxd[i];
            }
            t += 0.5 * (dw[i][j] - dd[i][rank[i][j]]);
            s += fabs_(t);
            t = t * fabs_(t) / dw[i][j];
            v[i] = v[i] + w[i][j] * t;
            // fprintf(stderr, "[%d][%d], %lf ; t = %lf\n", i, j, dw[i][j], t);
        }
        sp += s;
        if (s > 0) {
            v[i] = v[i] * (1.0 / s);
        }
        // fprintf(stderr, "%s\n", v[i].str().c_str());
        // sp += v[i].abs();
    }
    upd();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            if (r[i][j] != -1) {
                continue;
            }
            if (v[i][j] > 0) {
                p[i][j] += v[i][j] * rate + .5;
                if (p[i][j] > MAXZ) {
                    p[i][j] = MAXZ;
                }
            } else if (v[i][j] < 0) {
                p[i][j] -= -v[i][j] * rate + .5;
                if (p[i][j] < 0) {
                    p[i][j] = 0;
                }
            }
        }
    }
}

struct TheUniverseUnravels {
    void gao() {
        while (!timeout()) {
            for (int i = 0; i < n; ++i) {
                p[i] = r[i];
                for (int j = 0; j < DIMENSION; ++j) {
                    if (p[i][j] == -1) {
                        p[i][j] = rand() % (MAXZ + 1);
                    }
                }
            }
            real rate = RATE;
            for (int i = 0; i < MAXSTEP && !timeout(); ++i) {
                ::gao(rate);
                rate *= GRAVITY;
                fprintf(stderr, "%d: %lf\n", i, sp);
            }
        }
    }

    vector<string> predictCoordinates(
            vector<string> coords,
            vector<string> ranks,
            vector<int> minDist,
            vector <int> maxDist) {
        startTimer();
        n = coords.size();
        for (int i = 0; i < n; ++i) {
            r[i].parse(coords[i]);
            q[i] = r[i];
            for (int j = 0; j < DIMENSION; ++j) {
                if (q[i][j] == -1) {
                    q[i][j] = 0;
                }
            }
            split(ranks[i], rank[i]);
            mind[i] = sqrt_(minDist[i]);
            maxd[i] = sqrt_(maxDist[i]);
        }

        sq = std::numeric_limits<real>::max();
        gao();

        vector<string> ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(q[i].str());
        }
        return ret;
    }
};

#ifdef __WATASHI__
/**
 * main
 */
vector<string> readLines() {
    static int n;
    static char buf[65536];
    vector<string> ret;

    scanf("%d ", &n);
    for (int i = 0; i < n; ++i) {
        fgets(buf, sizeof(buf), stdin);
        ret.push_back(buf);
    }

    return ret;
}

vector<int> readInts() {
    static int n;
    vector<int> ret;

    scanf("%d", &n);
    ret.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ret[i]);
    }

    return ret;
}

int main() {
    auto coords = readLines();
    auto ranks = readLines();
    auto minDist = readInts();
    auto maxDist = readInts();
    TheUniverseUnravels tuu;
    auto ret = tuu.predictCoordinates(coords, ranks, minDist, maxDist);
    printf("%d\n", (int)ret.size());
    for (auto i: ret) {
        puts(i.c_str());
    }
    fprintf(stderr, "time = %lf\n", (double)clock() / CLOCKS_PER_SEC);
    fprintf(stderr, "sq = %lf\n", sq);
    fflush(stdout);
    return 0;
}
// vim: ft=cpp.doxygen
#endif
