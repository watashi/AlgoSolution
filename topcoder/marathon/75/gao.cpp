#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

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

enum endType {
    HEAD,
    TAIL
};

const int MAXN = 102;
const char BLACK = '.';
const char WHITE = 'X';
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int mask;
int sz, sz_1, crw[MAXN];
char tile, board[MAXN][MAXN];
vector<pair<int, int> > op, ans;

template<bool byRow>
pair<int, int> coordinate(int r, int i) {
    return byRow ? make_pair(r, i) : make_pair(i, r);
}

template<bool byRow>
char& cell(int r, int i) {
    return byRow ? board[r][i] : board[i][r];
}

template<bool byRow>
void reverse(int r) {
    for (int i = 1; i + i <= sz; ++i) {
        swap(cell<byRow>(r, i), cell<byRow>(r, sz_1 - i));
    }
}

template<bool byRow>
void rotate(int r, int p) {
    static char buf[MAXN + MAXN];
    if (byRow && tile == WHITE) {
        ++crw[r];
    }
    cell<byRow>(r, 0) = tile;
    for (int i = 0, j = p; i <= sz; ++i, ++j) {
        buf[j] = cell<byRow>(r, i);
    }
    for (int i = 0, j = sz_1; i < p; ++i, ++j) {
        cell<byRow>(r, i) = buf[j];
    }
    for (int i = p; i <= sz; ++i) {
        cell<byRow>(r, i) = buf[i];
    }
    tile = cell<byRow>(r, 0);
    if (byRow && tile == WHITE) {
        --crw[r];
    }
    cell<byRow>(r, 0) = BLACK;
}

void transform() {
    if (mask & 1) {
        for (int i = 1; i <= sz; ++i) {
            reverse<true>(i);
        }
    }
    if (mask & 2) {
        for (int i = 1; i <= sz; ++i) {
            reverse<false>(i);
        }
    }
    if (mask & 4) {
        for (int i = 1; i <= sz; ++i) {
            for (int j = 1; j < i; ++j) {
                swap(board[i][j], board[j][i]);
            }
        }
    }
}

void untransform(vector<pair<int, int> >& v, int mask) {
    for (int i = 0; i < (int)v.size(); ++i) {
        if (mask & 4) {
            swap(v[i].first, v[i].second);
        }
        if (mask & 2) {
            v[i].first = sz_1 - v[i].first;
        }
        if (mask & 1) {
            v[i].second = sz_1 - v[i].second;
        }
    }
}

inline void upd() {
    if (op.size() < ans.size()) {
        ans = op;
        untransform(ans, mask);
    }
}

void init(const vector<string>& board_, int mask_) {
    mask = mask_;
    sz = (int)board_.size();
    sz_1 = sz + 1;
    tile = BLACK;
    for (int i = 0; i < sz; ++i) {
        copy(board_[i].begin(), board_[i].end(), board[i + 1] + 1);
    }
    transform();
    for (int i = 1; i <= sz; ++i) {
        crw[i] = count(board[i] + 1, board[i] + sz_1, WHITE); // countByRow(WHITE)
    }
    op.clear();
}

inline int prev(int i) {
    return i == 1 ? sz : i - 1;
}

inline int next(int i) {
    return i == sz ? 1 : i + 1;
}

void shift(int x, int y, int z) {
    if (x == 0) {
        rotate<false>(y, z);
    } else if (x == sz_1) {
        rotate<false>(y, sz_1 - z);
    } else if (y == 0) {
        rotate<true>(x, z);
    } else if (y == sz_1) {
        rotate<true>(x, sz_1 - z);
    } else {
        throw make_pair(x, y);
    }
}

void doit(int x, int y, int z = 1) {
    shift(x, y, z);
    for (int i = 0; i < z; ++i) {
        op.push_back(make_pair(x, y));
    }
}

void undoit(int x, int y, int z = 1) {
    shift(x, y, sz_1 - z);
    op.resize((int)op.size() - z);
}

/** \defgroup tryCons
 *  @{
 */
template<bool byRow>
endType whichEnd(int r, char color) {
    for (int h = 1, t = sz; h < t; ++h, --t) {
        if (cell<byRow>(r, h) != cell<byRow>(r, t)) {
            return cell<byRow>(r, h) == color ? HEAD : TAIL;
        }
    }
    return HEAD;
}

template<bool byRow>
void pushEnd(int r, endType end) {
    if (end == HEAD) {
        doit(r, 0, 1);
    } else {
        doit(r, sz_1, 1);
    }
}

void tryCons(const vector<string>& board_, int mask_, int start) {
    init(board_, mask_);
    int w = start, b = prev(start);
    endType dw = whichEnd<true>(w, WHITE), db = whichEnd<true>(b, BLACK);
    // fprintf(stderr, "tryCons(%d, %d)\n", mask_, start);
    while (w != b && op.size() < ans.size()) {
        while (crw[w] == sz) {
            w = next(w);
            dw = whichEnd<true>(w, WHITE);
        }
        while (crw[b] == 0) {
            b = prev(b);
            db = whichEnd<true>(b, BLACK);
        }
        if (tile == WHITE) {
            pushEnd<true>(w, dw);
        } else {
            pushEnd<true>(b, db);
        }
    }
    while (tile == WHITE && op.size() < ans.size()) {
        pushEnd<true>(w, dw);
    }
    if (crw[1] == 0 || crw[sz] == 0) {
        upd();
    }
}
/** @}*/ // tryCons

/** \defgroup tryConsZebra
 *  @{
 */
template<bool byRow>
bool zipAnd(int i, int j) {
    for (int k = 1; k <= sz; ++k) {
        if (cell<byRow>(i, k) == WHITE && cell<byRow>(j, k) == WHITE) {
            return true;
        }
    }
    return false;
}

template<bool byRow>
void zip2(int i, int j, bool mark[MAXN]) {
    for (int k = 1; k <= sz; ++k) {
        mark[k] = cell<byRow>(i, k) == WHITE && cell<byRow>(j, k) == WHITE;
    }
    for (int k = 1; k <= sz; ++k) {
        if (mark[k]) {
            for (int kk = k - 1; kk >= 1 && cell<byRow>(j, kk) == WHITE; --kk) {
                if (mark[kk]) {
                    break;
                } else {
                    mark[kk] = true;
                }
            }
        } else if (cell<byRow>(j, k) == WHITE && mark[k - 1]) {
            mark[k] = true;
        }
    }
}

template<bool byRow>
bool zip3(int u, int m, int d) {
    static bool mu[MAXN], md[MAXN];
    bool flag = false;
    zip2<byRow>(u, m, mu);
    zip2<byRow>(d, m, md);
    for (int k = 1; k <= sz; ++k) {
        if (cell<byRow>(m, k) == WHITE) {
            if (!mu[k] && !md[k]) {
                return false;
            } else if (!flag && mu[k] && md[k]) {
                flag = true;
            }
        }
    }
    return flag;
}

void restore(int s) {
    while ((int)op.size() > s) {
        pair<int, int> p = op.back();
        int r = (int)op.size() - 1;
        while (r > s && op[r - 1] == p) {
            --r;
        }
        undoit(p.first, p.second, (int)op.size() - r);
    }
}

bool tryConsZebra(int w, int b, endType dw, endType db) {
    int s = (int)op.size();
    if (s >= (int)ans.size() || timeout()) {
        return true;
    }
    while (w != b && crw[w] < sz) {
        while (crw[b] == 0) {
            b = prev(b);
            db = whichEnd<true>(b, BLACK);
        }
        if (tile == WHITE) {
            pushEnd<true>(w, dw);
        } else {
            pushEnd<true>(b, db);
        }
    }
    if (w == b) {
    } else if (w == prev(b)) {
        do {
            w = next(w);
        } while (crw[w] == sz);
        dw = whichEnd<true>(w, WHITE);
        while (tile == WHITE) {
            pushEnd<true>(w, dw);
        }
        if (crw[1] == 0 || crw[sz] == 0) {
            upd();
            return true;
        }
    } else if (w < sz) {
        int ww = next(w);
        if (ww < sz) {
            ww = next(ww);
            if (ww < sz && zipAnd<true>(next(w), next(next(w)))) {
                ww = next(ww);
                if (ww < sz && zip3<true>(next(w), next(next(w)), next(next(next(w))))) {
                    ww = next(ww);
                }
            }
        }
        while (ww != w) {
            endType dww = whichEnd<true>(ww, WHITE);
            if (tryConsZebra(ww, b, dww, db)) {
                return true;
            }
            ww = prev(ww);
        }
    }
    restore(s);
    return false;
}

// we can find at least 1 full line and at most 40% full lines
void tryConsZebra(const vector<string>& board_, int mask_, int start) {
    init(board_, mask_);
    if (crw[start] == 0) {
        return;
    }
    int w = start, b = prev(prev(start));
    endType dw = whichEnd<true>(w, WHITE), db = whichEnd<true>(b, BLACK);
    tryConsZebra(w, b, dw, db);
}
/** @}*/

/** \defgroup checkAns
 *  @{
 */

static int ts;
static int tag[MAXN][MAXN];

int dfs(int x, int y) {
    int ret = 0;
    if (board[x][y] == WHITE && tag[x][y] != ts) {
        tag[x][y] = ts;
        ++ret;
        for (int i = 0; i < 4; ++i) {
            ret += dfs(x + dx[i], y + dy[i]);
        }
    }
    return ret;
}

bool checkAns(int total) {
    ++ts;
    for (int i = 1; i <= sz; ++i) {
        for (int j = 1; j <= sz; ++j) {
            if (board[i][j] == WHITE) {
                return dfs(i, j) == total;
            }
        }
    }
    return false;
}

void checkAns(const vector<string>& board_, int total) {
    init(board_, 0);
    for (int i = 0; i < (int)ans.size(); ++i) {
        doit(ans[i].first, ans[i].second, 1);
        if (tile == WHITE) {
            continue;
        }
        if (checkAns(total)) {
            ans.resize(i + 1);
            break;
        }
    }
}

/** @}*/

void guess(const vector<string>& board, int& x, int& y, int& r, int& c) {
    static int sum[MAXN + MAXN][MAXN + MAXN];
    int sz = (int)board.size();
    for (int i = 1; i <= sz; ++i) {
        for (int j = 1; j <= sz; ++j) {
            sum[i][j] = board[i - 1][j - 1] == WHITE ? 1 : 0;
            sum[i][j] += sum[i][j - 1];
        }
        for (int j = 1; j <= sz; ++j) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    int best = -1;
    for (int a = 1; a <= sz; ++a) {
        if (sum[sz][sz] % a != 0) {
            continue;
        }
        int b = sum[sz][sz] / a;
        for (int i = a; i <= sz; ++i) {
            for (int j = b; j <= sz; ++j) {
                int temp = sum[i][j] + sum[i - a][j - b] - sum[i - a][j] - sum[i][j - b];
                if (best < temp) {
                    best = temp;
                    x = i - a + 1;
                    y = j - b + 1;
                    r = a;
                    c = b;
                }
            }
        }
    }
    fprintf(stderr, "guess (%d,%d) %dx%d\n", x, y, r, c);
}

/**
 * BlackAndWhiteGame
 */
struct BlackAndWhiteGame {
    void gao(const vector<string>& board) {
        int sz = (int)board.size();
        int x, y, r, c;

        guess(board, x, y, r, c);
        ans.resize(sz * sz);
        fill(::board[0], ::board[MAXN], BLACK);

        for (int m = 0; m < 8; m += 2) {
            for (int i = 1; i <= sz; ++i) {
                tryCons(board, m, i);
            }
        }
        for (int m = 0; m < 8; m += 2) {
            for (int i = 1; i <= sz; ++i) {
                tryConsZebra(board, r <= c ? m : m ^ 4, i);
            }
        }
        checkAns(board, r * c);
    }

    vector<string> makeConnected(vector<string> board) {
        startTimer();
        gao(board);
        int best = (int)ans.size();
        fprintf(stderr, "time = %lf;\n", 1.0 * clock() / CLOCKS_PER_SEC);
        fprintf(stderr, "best = %d / %d^2 = %lf;\n", best, sz, 100.0 - 100.0 * best / sz / sz);

        char buf[MAXN];
        vector<string> ret;
        for (int i = 0; i < (int)ans.size(); ++i) {
            sprintf(buf, "%d %d", ans[i].first - 1, ans[i].second - 1);
            ret.push_back(buf);
        }
        return ret;
    }
};

#ifdef __WATASHI__
/**
 * main
 */
int main() {
    int sz;
    vector<string> board, ret;
    BlackAndWhiteGame blackAndWhiteGame;

    cin >> sz;
    board.resize(sz);
    for (int i = 0; i < sz; ++i) {
        cin >> board[i];
    }

    ret = blackAndWhiteGame.makeConnected(board);

    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i) {
        cout << ret[i] << endl;
    }

    return 0;
}
// vim: ft=cpp.doxygen
#endif
