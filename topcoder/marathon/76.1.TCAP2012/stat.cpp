#include <set>
#include <map>
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
    startti.tv_usec += 543210;
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

int n;
Point<int> r[MAXN];
int mind[MAXN], maxd[MAXN], rank[MAXN][MAXN];

struct TheUniverseUnravels {
    vector<string> predictCoordinates(
            vector<string> coords,
            vector<string> ranks,
            vector<int> minDist,
            vector <int> maxDist) {
        n = coords.size();
        for (int i = 0; i < n; ++i) {
            r[i].parse(coords[i]);
            split(ranks[i], rank[i]);
            mind[i] = minDist[i];
            maxd[i] = maxDist[i];
        }

        int dup = 0;
        std::map<int, int> mp, rk;
        for (int i = 0; i < n; ++i) {
            int c = 0;
            for (int j = 0; j < DIMENSION; ++j) {
                if (r[i][j] == -1) {
                    ++c;
                }
            }
            ++mp[c];
            std::set<int> st;
            for (int j = 0; j < n; ++j) {
                ++rk[rank[i][j]];
                st.insert(rank[i][j]);
            }
            dup += n - st.size();
        }
        fprintf(stderr, "n = %d\n", n);
        for (int i = 0; i <= DIMENSION; ++i) {
            fprintf(stderr, "%2d | %d\n", i, mp[i]);
        }
        fprintf(stderr, "dup = %d\n", dup);
        /*
        for (int i = 0; i < n; ++i) {
            if (rk[i] != n) {
                fprintf(stderr, "%d: %+d\n", i, rk[i] - n);
            }
        }
        */

        vector<string> ret;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < DIMENSION; ++j) {
                if (r[i][j] == -1) {
                    r[i][j] = 500;
                }
            }
            ret.push_back(r[i].str());
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
    fprintf(stderr, "n = %d\n", n);
    fprintf(stderr, "time = %lf\n", (double)clock() / CLOCKS_PER_SEC);
    // fprintf(stderr, "sq = %lf\n", sq);
    fflush(stdout);
    return 0;
}
// vim: ft=cpp.doxygen
#endif
