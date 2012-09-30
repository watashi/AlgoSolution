#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define P(p, a, b) ((p * a + (100 - p) * b) / 100.0)
#define LP_INIT_HP 999
#define LP_LEVEL 50
#define LP_GENDER 0
#define RECOVER_HP 200
// #define X_CHOP_ACC 0.3
#define X_CHOP_ACC 30
#define X_CHOP_DAM 300

/*
   inline double max(double a, double b) {
   printf("\t%lf\n", b);
   if (a > b) return a; else return b;
   }
   */
struct LegendaryPokemon {
    int level, gender, maxhp;
    int run[5], p[5];
    int n, c[4][4];

    struct StatusA {    // sizeof(A) = 8
        char b[5];      // the number of corresponding balls you have: 1~5
        int hp: 12;     // initial(and maximal) HP value: -???~999+200
        int nhp: 5;     // the number of Hyper Potions: 0~10
    };

    struct StatusB {    // sizeof(B) = 8
        int hp: 12;     // initial(and maximal) HP value: -???~999
        int nhp: 5;     // the number of Hyper Potions: 0~10
        int confuse: 8; // confusion: 0~100
        int status: 2;  // sleepy(0), confused(1)
        int sr: 3;      // These will be effective within 3 rs
        int poison: 11; // poison value: 0~999
        int pr: 3;      // The effect lasts for 3 rs
    };

    int p1, p2, bb[5];
    /*
        void dump(int r, StatusA a, StatusB b) const {
        printf("Round %d:\n", r);

        printf("%d(%d): {", a.hp, a.nhp);
        for (int i = 0; i < 5; ++i) {
        printf("%d, ", (int)a.b[i]);
        }
        puts("}");

        printf("%d(%d):", b.hp, b.nhp);
        printf(" pr=%d(%d) sr=%d(%d,%d)\n", b.pr, b.poison, b.sr, b.status, b.confuse);
        }
        */
    double gao() {
        StatusA a;
        StatusB b;

        for (int i = 0; i < 5; ++i) {
            a.b[i] = bb[i];
        }
        a.hp = maxhp;
        a.nhp = p1;

        memset(&b, 0, sizeof(StatusB));
        b.hp = LP_INIT_HP;
        b.nhp = p2;

        p[0] = 5;
        p[1] = 10;
        p[2] = 15;
        p[3] = level > LP_LEVEL ? 18 : p[1];
        p[4] = gender != LP_GENDER ? 20 : 0;

        // dump(-1, a, b);

        return gao1(0, a, b);
    }

    double gao1(int r, StatusA a, StatusB b) const {
        // dump(r, a, b);
        if (a.hp <= 0 || b.hp <= 0) {
            return 0;
        }
        if (a.b[0] == 0 && a.b[1] == 0 && a.b[2] == 0 && a.b[3] == 0 && a.b[4] == 0) {
            return 0;
        }

        double ret = 0;

        // A move
        double tmp = gao2(r, a, b);
        for (int i = 0; i < n; ++i) {
            // printf("> move %d\n", i);
            StatusB b2 = b;
            int pp = c[i][2];
            switch (c[i][0]) {
            case 1:
                b2.hp -= c[i][1];
                break;
            case 2:
                if (b2.sr == 0) {
                    b2.sr = 3;
                    if (c[i][1] == 0) {
                        b2.status = 0;
                    } else {
                        b2.status = 1;
                        b2.confuse = c[i][1];
                    }
                }
                break;
            case 3:
                b2.hp -= c[i][1];
                if (b2.pr == 0) {
                    b2.pr = 3;
                    b2.poison = c[i][2];
                }
                pp = c[i][3];
                break;
            }
            ret = max(ret, P(pp, gao2(r, a, b2), tmp));
        }

        // A BALL
        for (int i = 0; i < 5; ++i) {
            // printf("> ball %d\n", i);
            if (a.b[i] > 0) {
                int pp = p[i];
                if (b.hp <= 50) {   // CriticalLifeBonus
                    pp += 10;
                } else if (b.hp <= 100) {
                    pp += 5;
                }
                if (b.pr > 0) { // PoisonedBonus
                    pp += 10;
                }
                if (b.sr > 0) { // StatusBonus
                    pp += 5;
                }
                --a.b[i];
                ret = max(ret, P(pp, 1, gao2(r, a, b)));
                ++a.b[i];
            }
        }

        // heal
        if (a.nhp > 0) {
            // HP values can never be greater than their maximal values (@fix{1})
            a.hp = min(maxhp, a.hp + RECOVER_HP);
            --a.nhp;
            ret = max(ret, gao2(r, a, b));
        }

        return max(ret, tmp);   // do_nothing (@fix{3})
    }

    double gao2(int r, StatusA a, StatusB b) const {
        if (a.hp <= 0 || b.hp <= 0) {
            return 0;
        }

        // dump(r, a, b);
        // 1. In the ith r, he may decide to run away. ...
        if (run[r] >= 100) {
            return 0;
        }

        // 2. If he decided to continue the battle, he check if his HP. ...
        if (b.hp <= 150 && b.nhp > 0) {
            b.hp += RECOVER_HP; //
            --b.nhp;
            if (b.pr > 0) { //
                --b.pr;
                if ((b.hp -= b.poison) <= 0) {
                    return 0;
                }
            }
            if (b.sr > 0) { //
                --b.sr;
            }
            return (1 - run[r] / 100.0) * gao1(r + 1, a, b);
        }

        if (b.pr > 0) {
            --b.pr;
            if ((b.hp -= b.poison) <= 0) {
                return 0;
            }
        }

        if (b.sr > 0) {
            --b.sr;
            double tmp = gao1(r + 1, a, b);
            if (b.status == 0) {    // WA.. 手抖
                return (1 - run[r] / 100.0) * tmp;
            } else {
                StatusA a2 = a;
                a2.hp -= X_CHOP_DAM;
                StatusB b2 = b;
                b2.hp -= X_CHOP_DAM;
                return (1 - run[r] / 100.0) * P(b.confuse,
                    P(X_CHOP_ACC, gao1(r + 1, a, b2), tmp),
                    P(X_CHOP_ACC, gao1(r + 1, a2, b), tmp));
            }
        } else {
            StatusA a2 = a;
            a2.hp -= X_CHOP_DAM;
            return (1 - run[r] / 100.0) * P(X_CHOP_ACC, gao1(r + 1, a2, b), gao1(r + 1, a, b));
        }
    }
};

int main() {
    LegendaryPokemon lp;

    while (scanf("%d%d%d", &lp.level, &lp.gender, &lp.maxhp) != EOF && lp.maxhp > 0) {
        for (int i = 0; i < 5; ++i) {
            scanf("%d", &lp.run[i]);
        }
        scanf("%d%d", &lp.p1, &lp.p2);
        for (int i = 0; i < 5; ++i) {
            scanf("%d", &lp.bb[i]);
        }
        scanf("%d", &lp.n);
        for (int i = 0; i < lp.n; ++i) {
            scanf("%d%d%d", &lp.c[i][0], &lp.c[i][1], &lp.c[i][2]);
            if (lp.c[i][0] == 3) {
                scanf("%d", &lp.c[i][3]);
            }
        }
        printf("%.4lf\n", lp.gao());
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//412   2010-07-07 16:03:51     Accepted    1019    C++     310     180     anotherpeg  Source

/*
0 0 800
10 20 30 100 100
1
4
1 1 0 2 0
4
2 21 87
2 0 57
2 33 93
2 2 71
0 0 0
0.2572  <- xgy
0.2584  <- gougou
0.2581  <- watashi
*/

// 2012-09-30 23:39:06 | Accepted | 1230 | C++ | 200 | 180 | watashi | Source
