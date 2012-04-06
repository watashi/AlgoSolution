#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const clock_t TIME_LIMIT = 10 * CLOCKS_PER_SEC - CLOCKS_PER_SEC / 10;
static clock_t time_limit = 0;

bool timeout() {
    return clock() > time_limit;
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
        op.swap(ans);
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
    if (byRow) {
        if (tile == WHITE) {
            ++crw[r];
        }
    }
    if (end == HEAD) {
        doit(r, 0, 1);
        // rotate<byRow>(r, 1);
        // op.push_back(coordinate<byRow>(r, 0));
    } else {
        doit(r, sz_1, 1);
        // rotate<byRow>(r, sz);
        // op.push_back(coordinate<byRow>(r, sz_1));
    }
    if (byRow) {
        if (tile == WHITE) {
            --crw[r];
        }
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
    upd();
}
/** @}*/ // tryCons

/**
 * BlackAndWhiteGame
 */
struct BlackAndWhiteGame {
    vector<string> makeConnected(vector<string> board) {
        int sz = (int)board.size();
        ans.resize(sz * sz);
        for (int m = 0; m < 8; ++m) {
            for (int i = 1; i <= sz; ++i) {
                tryCons(board, m, i);
            }
        }
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
