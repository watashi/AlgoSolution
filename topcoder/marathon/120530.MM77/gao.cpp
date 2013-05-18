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
llint startll0, startll, endll;

const llint MSEC_PER_SEC = 1000000LL;

#ifdef __WATASHI__
const llint TIME_LIMIT = 3868686;
#else
const llint TIME_LIMIT = 9500000;
#endif

void startTimer() {
    gettimeofday(&startti, NULL);
    startll0 = startti.tv_sec * MSEC_PER_SEC + startti.tv_usec + TIME_LIMIT / 3;
    startll = startti.tv_sec * MSEC_PER_SEC + startti.tv_usec + TIME_LIMIT;
}

bool timeout0() {
    gettimeofday(&endti, NULL);
    endll = endti.tv_sec * MSEC_PER_SEC + endti.tv_usec;
    return endll > startll0;
}

bool timeout() {
    gettimeofday(&endti, NULL);
    endll = endti.tv_sec * MSEC_PER_SEC + endti.tv_usec;
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
int pg[MAXG], pc[MAXC], qg[MAXG], qc[MAXC];

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

inline int getqid(int gid, int cid, int pid, int target) {
    int* pts = ::pts[gid][cid];
    int qid = lower_bound(pts + pid, pts + SS + 1, pts[pid] + target) - pts;
    if (qid / S != pid / S) {
        qid = max(qid, pid + S + 1);
    }
    return qid;
}

vector<int> dummy;
bool mark[MAXG];

template<bool RET>
bool gen0(int target, vector<int>& ret) {
    int* pg = RET ? ::qg : ::pg;
    int* pc = RET ? ::qc : ::pc;
    int cid = 0;
    int pid = 0;
    fill(mark, mark + G, false);
    if (RET) {
        ret.resize(C * SS);
        fill(ret.begin(), ret.end(), -1);
    }
    for (int i = 0; i < G; ++i) {
        if (cid == C) {
            return false;
        }
        int gid = -1;
        int qid = SS + 1;
        for (int j = 0; j < G; ++j) {
            if (mark[pg[j]]) {
                continue;
            }
            int rid = getqid(pg[j], pc[cid], pid, target);
            if (qid > rid) {
                qid = rid;
                gid = pg[j];
            }
        }
        if (gid == -1) {
            ++cid;
            pid = 0;
            --i;
        } else {
            mark[gid] = true;
            if (RET) {
                fill(ret.begin() + pc[cid] * SS + pid, ret.begin() + pc[cid] * SS + qid, gid);
            }
            pid = qid;
        }
    }
    if (RET) {
        fprintf(stderr, "A %d/%d:%d/%d\n", cid, C, pid, SS);
    }
    return true;
}

bool gen0(int target) {
    return gen0<false>(target, dummy);
}

int gao0(int ans) {
    int counter1 = 0;
    int counter2 = 0;
    int ret = ans;
    while (counter1 % 10 != 0 || !timeout0()) {
        random_shuffle(pg, pg + G);
        random_shuffle(pc, pc + C);
        ++counter1;
        if (!gen0(ret + 1)) {
            continue;
        }
        ++counter2;
        int l = ret;
        int r = l * 2;
        while (gen0(r)) {
            l = r;
            r = l * 2;
        }
        while (l < r) {
            int m = (l + r) / 2;
            if (gen0(m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ret = r - 1;
        copy(pg, pg + G, qg);
        copy(pc, pc + C, qc);
    }
    fprintf(stderr, "counter1 = %d\n", counter1);
    fprintf(stderr, "counter2 = %d\n", counter2);
    fprintf(stderr, "ret = %d\n", ret);
    return ret;
}

template<bool RET>
bool gen(int target, vector<int>& ret) {
    int* pg = RET ? ::qg : ::pg;
    int* pc = RET ? ::qc : ::pc;
    int cid = 0;
    int pid = 0;
    if (RET) {
        ret.resize(C * SS);
        fill(ret.begin(), ret.end(), -1);
    }
    for (int i = 0; i < G; ++i) {
        if (cid == C) {
            return false;
        }
        int gid = pg[i];
        int qid = getqid(gid, pc[cid], pid, target);
        if (qid > SS) {
            ++cid;
            pid = 0;
            --i;
        } else {
            if (RET) {
                fill(ret.begin() + pc[cid] * SS + pid, ret.begin() + pc[cid] * SS + qid, gid);
            }
            pid = qid;
        }
    }
    if (RET) {
        fprintf(stderr, "B %d/%d:%d/%d\n", cid, C, pid, SS);
    }
    return true;
}

bool gen(int target) {
    return gen<false>(target, dummy);
}

int gao(int ans) {
    int counter1 = 0;
    int counter2 = 0;
    int ret = ans;
    while (counter1 % 100 != 0 || !timeout()) {
        random_shuffle(pg, pg + G);
        random_shuffle(pc, pc + C);
        ++counter1;
        if (!gen(ret + 1)) {
            continue;
        }
        ++counter2;
        int l = ret;
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
        ret = r - 1;
        copy(pg, pg + G, qg);
        copy(pc, pc + C, qc);
    }
    fprintf(stderr, "counter1 = %d\n", counter1);
    fprintf(stderr, "counter2 = %d\n", counter2);
    fprintf(stderr, "ret = %d\n", ret);
    return ret;
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

        for (int i = 0; i < G; ++i) {
            pg[i] = qg[i] = i;
        }
        for (int i = 0; i < C; ++i) {
            pc[i] = qc[i] = i;
        }

        int ans0 = gao0(init() / 2);
        int ans = gao(ans0);

        fprintf(stderr, "ans = %d\n", max(ans0, ans));

        vector<int> ret;
        if (ans0 >= ans) {
            gen0<true>(ans0, ret);
        } else {
            gen<true>(ans, ret);
        }
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
