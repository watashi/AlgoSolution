#include <cstdlib> // auto fix CE
#include <utility> // auto fix CE
#include <cstdlib> // auto fix CE
#include <list>
#include <cstdlib> // auto fix CE
#include <utility> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cmath>
#include <cstdlib> // auto fix CE
#include <utility> // auto fix CE
#include <cstdlib> // auto fix CE
#include <cstdio>
#include <cstdlib> // auto fix CE
#include <utility> // auto fix CE
#include <cstdlib> // auto fix CE
#include <vector>
#include <cstdlib> // auto fix CE
#include <utility> // auto fix CE
#include <cstdlib> // auto fix CE
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

inline double invoke(int op, double lhs, double rhs) {
    switch (op) {
    case 0: return lhs + rhs;
    case 1: return lhs - rhs;
    case 2: return lhs * rhs;
    case 3: return rhs / lhs;
    default: return NAN;
    }
}

bool valid[1 << 16];

void init() {
    int a[4], b[4], op[3];
#define FORA(i) for (a[i] = i == 0 ? 1 : a[i - 1]; a[i] <= 10; ++a[i])
#define FOROP(i) for (op[i] = 0; op[i] < 4; ++op[i])
    FORA(0) FORA(1) FORA(2) FORA(3) {
        copy(a, a + 4, b);
        FOROP(0) FOROP(1) FOROP(2) {
            do {
                if (fabs(invoke(op[0], invoke(op[1], b[0], b[1]), invoke(op[2], b[2], b[3])) - 24) < EPS ||
                    fabs(invoke(op[0], invoke(op[1], invoke(op[2], b[0], b[1]), b[2]), b[3]) - 24) < EPS ||
                    fabs(invoke(op[0], b[0], invoke(op[1], b[1], invoke(op[2], b[2], b[3]))) - 24) < EPS) {
                    goto VALID;
                }
            } while (next_permutation(b, b + 4));
        }
        continue;
VALID:
        sort(b, b + 4);
        do {
            valid[b[0] ^ (b[1] << 4) ^ (b[2] << 8) ^ (b[3] << 12)] = true;
        } while (next_permutation(b, b + 4));
    }
#undef FORA
#undef FOROP
}

typedef pair<bool, int> Card;

Card readCard() {
    char ch;
    int num;
    scanf("%d %c", &num, &ch);
    return make_pair(ch == 'b', num);
}

Card cards[4];
list<Card> cardsSM;
vector<Card> cardsZJ;

bool gao(bool sm, bool first = false) {
    bool ok = valid[cards[0].second ^ (cards[1].second << 4) ^ (cards[2].second << 8) ^ (cards[3].second << 12)];
    if (sm) {
        bool ret = (first && gao(false)) || (!first && ok);
        list<Card>::iterator it = cardsSM.begin();
        while (it != cardsSM.end() && !ret) {
            Card swp = *it;
            it = cardsSM.erase(it);
            for (int i = 0; i < 4 && !ret; ++i) {
                swap(cards[i], swp);
                if (gao(false)) {
                    ret = true;
                }
                swap(cards[i], swp);
            }
            cardsSM.insert(it, swp);
        }
        return ret;
    } else {
        bool ret = ok;
        for (vector<Card>::iterator it = cardsZJ.begin(); it != cardsZJ.end() && ret; ++it) {
            if (!it->first) {
                continue;
            }
            for (int i = 0; i < 4 && ret; ++i) {
                swap(cards[i], *it);
                if (!gao(true)) {
                    ret = false;
                }
                swap(cards[i], *it);
            }
        }
        return ret;
    }
}

int main() {
    int re, n, m;

    init();
    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        for (int i = 0; i < 4; ++i) {
            cards[i] = readCard();
        }
        scanf("%d%d", &n, &m);
        cardsSM.clear();
        for (int i = 0; i < n; ++i) {
            cardsSM.push_back(readCard());
        }
        cardsZJ.clear();
        for (int i = 0; i < m; ++i) {
            cardsZJ.push_back(readCard());
        }
        puts(gao(true, true) ? "Sima Yi Wins!" : "Zhang Jiao Wins!");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//688   2011-01-30 14:16:20     Accepted    C   C++     50  244     watashi@ArcOfDream  Source

// 2012-09-07 15:58:13 | Accepted | 3459 | C++ | 50 | 244 | watashi | Source
