#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using namespace std;

static int dummy;

bool a[31][31][31][31][8];

// sarchmage > 0
// sarchmage <= swarden
// mana >= 0
// hp > 0
struct State {
    static int varchmage, vwarden;

    short sarchmage;    // the distance between Archmage and enemybase
    short swarden;  // the distance between Warden and enemybase
    short mana;     // the mana point of Warden
    short hp;           // the hp of Archmage
    short poison;

    void gao(int timespan, bool prepare = false) {
        if (poison <= timespan) {
            sarchmage -= poison + varchmage * (timespan - poison);
            poison = 0;
        } else {
            sarchmage -= timespan;  //
            poison -= timespan;
        }

        if (!prepare) {
            swarden -= vwarden * timespan;
        }

        if (swarden < sarchmage) {
            swarden = sarchmage;
        }
    }
};

int State::varchmage;
int State::vwarden;

struct FanOfKnives {
    int t, p, r, h;

    State gao(State s) const {
        s.gao(t, true);
        if (s.swarden - s.sarchmage > r) {
            s.sarchmage = -1;
            return s;
        }
        s.mana -= p;
        s.hp -= h;
        return s;
    }
} fok;

struct ShadowStrike {
    int t, p, r, h, T;

    State gao(State s) const {
        s.gao(t, true);
        if (s.swarden - s.sarchmage > r) {
            s.sarchmage = -1;
            return s;
        }
        s.mana -= p;
        s.hp -= h;
        s.poison = T;
        return s;
    }
} ss;

struct Blink {
    static const int t = 1;
    int p, r;

    State gao(State s) const {
        s.gao(t, true);
        s.mana -= p;
        s.swarden -= r;
        return s;
    }
} blink;

int dp[64];

void gao(const State& s) {
    if (s.sarchmage <= 0 || s.mana < 0) {
        return;
    } else if (s.hp <= 0) {
        throw 1;
    } else if (s.sarchmage > s.swarden) {
        if (dp[s.mana] >= s.hp) {
            throw 1;
        }
    } else {
        if (a[s.sarchmage][s.swarden][s.hp][s.mana][s.poison]) {
            return;
        } else {
            a[s.sarchmage][s.swarden][s.hp][s.mana][s.poison] = true;
        }
        gao(blink.gao(s));
        gao(fok.gao(s));
        gao(ss.gao(s));
        State ss = s;
        ss.gao(1);
        gao(ss);
    }
}

int main() {
    int re;
    State init;

    dummy = scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        dummy = scanf("%hd%hd%d%d%hd%hd", &init.sarchmage, &init.swarden, &State::varchmage, &State::vwarden, &init.mana, &init.hp);
        init.poison = 0;
        dummy = scanf("%d%d%d%d", &fok.t, &fok.p, &fok.r, &fok.h);
        dummy = scanf("%d%d%d%d%d", &ss.t, &ss.p, &ss.r, &ss.h, &ss.T);
        dummy = scanf("%d%d", &blink.p, &blink.r);

        fill(dp, dp + 64, 0);
        for (int i = fok.p; i < 64; ++i) {
            dp[i] = max(dp[i], dp[i - fok.p] + fok.h);
        }
        for (int i = ss.p; i < 64; ++i) {
            dp[i] = max(dp[i], dp[i - ss.p] + ss.h);
        }

        memset(a, 0, sizeof(a));
        try {
            gao(init);
            puts("no");
        } catch (...) {
            puts("yes");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//750   2010-07-18 20:53:20     Accepted    1089    C++     260     7392    anotherpeg  Source

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//281   2010-08-30 17:46:12     Accepted    C   C++     130     7392    watashi@Zodiac  Source

// 2012-09-07 15:51:40 | Accepted | 3398 | C++ | 130 | 7396 | watashi | Source
