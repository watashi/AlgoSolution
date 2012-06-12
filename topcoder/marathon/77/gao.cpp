#include <cmath>
#include <ctime>
#include <limits>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

typedef long long llint;

timeval startti, endti;
llint startll, endll;

const llint MSEC_PER_SEC = 1000000LL;

#ifdef __WATASHI__
const llint TIME_LIMIT = 3868686;
#else
const llint TIME_LIMIT = 9543210;
#endif

void startTimer() {
    gettimeofday(&startti, NULL);
    startti.tv_sec += TIME_LIMIT / MSEC_PER_SEC;
    startti.tv_usec += TIME_LIMIT % MSEC_PER_SEC;
    startll = startti.tv_sec * MSEC_PER_SEC + startti.tv_usec;
}

bool timeout() {
    gettimeofday(&endti, NULL);
    endll = endti.tv_sec * 1000000LL + endti.tv_usec;
    return endll > startll;
}

const int MAXC = 10;    // the number of cakes; [1, 10]
const int MAXG = 10 * MAXC; // the number of guests; [2C, 10C]
const int MAXS = 100;   // the size of the side of one cake (in sections); [20, 100], even
const int MAXI = 10;    // the number of ingredients; [2, 10]

int C, G, I, S, SS;
int prefs[MAXG][MAXI];
int cakes[MAXC][MAXS * MAXS][MAXI];
int pts[MAXG][MAXC][MAXS * MAXS + 1];
int per[MAXG], qer[MAXG];

inline int idx(int r, int c) {
    return r * S + c;
}

int init() {
    for (int i = 0; i < G; ++i) {
        for (int j = 0; j < C; ++j) {
            static int tmp[MAXS * MAXS];
            for (int k = 0; k < SS; ++k) {
                tmp[k] = 0;
                for (int l = 0; l < I; ++l) {
                    tmp[k] += prefs[i][l] * cakes[j][k][l];
                }
            }
            partial_sum(tmp, tmp + SS, pts[i][j] + 1);
        }
    }

    int ret = numeric_limits<int>::max();
    int gPerC = (G + C - 1) / C;
    int rPerG = S / gPerC;

    for (int i = 0; i < G; ++i) {
        int cid = i / gPerC;
        int rid = i % gPerC;
        int sum = pts[i][cid][(rid + 1) * rPerG] - pts[i][cid][rid * rPerG];
        ret = min(ret, sum);
    }

    return ret;
}

bool gen(int target) {
    int cid = 0;
    int pid = 0;
    for (int i = 0; i < G; ++i) {
        if (cid == C) {
            return false;
        }
        int qid = lower_bound(pts[per[i]][cid] + pid, pts[per[i]][cid] + SS + 1, pts[per[i]][cid][pid] + target) - pts[per[i]][cid];
        qid = max(qid, pid + S + 1);
        if (qid > SS) {
            ++cid;
            pid = 0;
            --i;
            continue;
        }
        pid = qid;
    }
    // fprintf(stderr, "%d is true\n", target);
    return true;
}

void regen(int target, vector<int>& ret) {
    ret.resize(C * SS);
    fill(ret.begin(), ret.end(), -1);

    int cid = 0;
    int pid = 0;
    for (int i = 0; i < G; ++i) {
        if (cid == C) {
            throw 1;
        }
        int qid = lower_bound(pts[qer[i]][cid] + pid, pts[qer[i]][cid] + SS + 1, pts[qer[i]][cid][pid] + target) - pts[qer[i]][cid];
        qid = max(qid, pid + S + 1);
        if (qid > SS) {
            ++cid;
            pid = 0;
            --i;
            continue;
        }
        fill(ret.begin() + cid * SS + pid, ret.begin() + cid * SS + qid, qer[i]);
        // fprintf(stderr, "%d:%d-%d => %d\n", cid, pid, qid, i);
        pid = qid;
    }
    fprintf(stderr, "%d/%d:%d/%d\n", cid, C, pid, SS);
}

struct Cakes {
    vector<int> split(int C, int G, int I, int S, const vector<int>& prefs, const vector<int>& cakes) {
        startTimer();
        ::C = C;
        ::G = G;
        ::I = I;
        ::S = S;
        SS = S * S;
        fprintf(stderr, "C = %d; G = %d; I = %d; S = %d\n", C, G, I, S);
        fprintf(stderr, "C * G * I * SS = %d\n", C * G * I * SS);
        vector<int>::const_iterator it = prefs.begin();
        for (int i = 0; i < G; ++i) {
            for (int j = 0; j < I; ++j) {
                ::prefs[i][j] = *it++;
            }
        }
        vector<int>::const_iterator jt = cakes.begin();
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < SS; ++j) {
                for (int k = 0; k < I; ++k) {
                    ::cakes[i][j][k] = *jt++;
                }
            }
        }

        int ans = init();
        for (int i = 0; i < G; ++i) {
            per[i] = qer[i] = i;
        }
        int counter1 = 0;
        int counter2 = 0;
        while (counter1 % 100 != 0 || !timeout()) {
            ++counter1;
            if (gen(ans + 1)) {
                ++counter2;
                int l = ans + 1;
                int r = l * 2;
                while (gen(r)) {
                    l = r;
                    r = l * 2;
                }
                while (l < r) {
                    int m = (l + r) / 2;
                    if (gen(m)) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }
                copy(per, per + G, qer);
                ans = r - 1;
            }
            random_shuffle(per, per + G);
        }
        fprintf(stderr, "counter1 = %d\n", counter1);
        fprintf(stderr, "counter2 = %d\n", counter2);
        fprintf(stderr, "ans = %d\n", ans);

        vector<int> ret;
        regen(ans, ret);
        /*
        for (int i = 0; i < G; ++i) {
            fprintf(stderr, "%d ", count(ret.begin(), ret.end(), i));
        }
        fprintf(stderr, "\n");
        */
        fprintf(stderr, "time = %lf\n", (double)clock() / CLOCKS_PER_SEC);
        return ret;
    }
};

#ifdef __WATASHI__
/**
 * main
 */
int main() {
    int C, G, I, S;
    scanf("%d%d%d%d", &C, &G, &I, &S);
    vector<int> prefs(G * I);
    for (int i = 0; i < (int)prefs.size(); ++i) {
        scanf("%d", &prefs[i]);
    }
    vector<int> cakes(C * S * S * I);
    for (int i = 0; i < (int)cakes.size(); ++i) {
        scanf("%d", &cakes[i]);
    }
    Cakes instance;
    vector<int> ret = instance.split(C, G, I, S, prefs, cakes);
    for (int i = 0; i < (int)ret.size(); ++i){
        printf("%d\n", ret[i]);
    }
    fflush(stdout);
    return 0;
}
// vim: ft=cpp.doxygen
#endif
