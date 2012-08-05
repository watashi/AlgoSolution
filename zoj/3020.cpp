// ZOJ3020. Puzzle Quest
#include <cstdio>
#include <vector>
#include <ext/hash_set>

using namespace std;
using namespace __gnu_cxx;

class Puzzle
{
private:
    friend class __puzzle_state;
    const static int MAXN = 8;
    class __puzzle_state
    {
        friend class Puzzle;
        friend class __puzzle_state_hash;
    private:
        static int n;
        int a[MAXN];
    public:
        class __puzzle_state_hash
        {
        public:
            size_t operator()(const __puzzle_state& s) const;
        };
        bool operator==(const __puzzle_state& s) const;
    };
    class __puzzle_solved
    {
    };
public:
    typedef __puzzle_state State;
    typedef State::__puzzle_state_hash HashFunction;
    typedef __puzzle_solved Solved;
    const int n, m;
private:
    static const char* dir[4];
    static State END;
    hash_set<State, HashFunction> hs;
    State vs[MAXN * MAXN];
    char s[MAXN * MAXN][MAXN][MAXN];
    pair<pair<int, int>, int> ins[MAXN * MAXN];

    Puzzle(int n, int m);
    Puzzle(const Puzzle& p);
    void dfs(int l);
    bool isvalid(char buf[MAXN][MAXN], int x, int y, char ch);
    bool isvalid(char buf[MAXN][MAXN], int x1, int y1, int x2, int y2);
    State toState(char buf[MAXN][MAXN]);
public:
    static bool run();
};

size_t Puzzle::HashFunction::operator()(const State& s) const
{
    size_t ret = 0;

    for (int i = 0; i < State::n; i++) {
        ret ^= (s.a[i] << i);
    }

    return ret;
}

int Puzzle::State::n;

bool Puzzle::State::operator==(const State& s) const
{
    for (int i = 0; i < n; i++) {
        if (a[i] != s.a[i]) {
            return false;
        }
    }
    return true;
}

const char* Puzzle::dir[4] = {"left", "up", "right", "down"};

Puzzle::State Puzzle::END;

Puzzle::Puzzle(int n, int m)
    : n(n), m(m)
{

}

void Puzzle::dfs(int l)
{
    if (vs[l].a[0] < 0 || hs.count(vs[l]) > 0) {
        return;
    }
    else if (vs[l] == END) {
        printf("%d\n", l);
        for (int i = 0; i < l; i++) {
            printf("%d %d %s\n", ins[i].first.first, ins[i].first.second, dir[ins[i].second]);
        }
        putchar('\n');  // 忘记空行 WA
        throw Solved();
    }
    hs.insert(vs[l]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0 && isvalid(s[l], i, j, i, j - 1)) {
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < m; jj++) {
                        s[l + 1][ii][jj] = s[l][ii][jj];
                    }
                }
                swap(s[l + 1][i][j], s[l + 1][i][j - 1]);
                vs[l + 1] = toState(s[l + 1]);
                ins[l] = make_pair(make_pair(i, j), 0);
                dfs(l + 1);
            }
            if (i > 0 && isvalid(s[l], i, j, i - 1, j)) {
                for (int ii = 0; ii < n; ii++) {
                    for (int jj = 0; jj < m; jj++) {
                        s[l + 1][ii][jj] = s[l][ii][jj];
                    }
                }
                swap(s[l + 1][i][j], s[l + 1][i - 1][j]);
                vs[l + 1] = toState(s[l + 1]);
                ins[l] = make_pair(make_pair(i, j), 1);
                dfs(l + 1);
            }
        }
    }
}

bool Puzzle::isvalid(char buf[MAXN][MAXN], int x, int y, char ch)
{
    if (x >= 2 && buf[x - 1][y] == ch && buf[x - 2][y] == ch) return true;
    if (x < n - 2 && buf[x + 1][y] == ch && buf[x + 2][y] == ch) return true;
    if (y >= 2 && buf[x][y - 1] == ch && buf[x][y - 2] == ch) return true;
    if (y < m - 2 && buf[x][y + 1] == ch && buf[x][y + 2] == ch) return true;
    if (x >= 1 && x < n - 1 && buf[x - 1][y] == ch && buf[x + 1][y] == ch) return true;
    if (y >= 1 && y < m - 1 && buf[x][y - 1] == ch && buf[x][y + 1] == ch) return true;
    return false;
}

bool Puzzle::isvalid(char buf[MAXN][MAXN], int x1, int y1, int x2, int y2)
{
    char ch;

    if (buf[x1][y1] != 0) {
        ch = buf[x1][y1];
        buf[x1][y1] = buf[x2][y2];
        if (isvalid(buf, x2, y2, ch)) {
            buf[x1][y1] = ch;
            return true;
        }
        buf[x1][y1] = ch;
    }
    if (buf[x2][y2] != 0 && isvalid(buf, x1, y1, buf[x2][y2]) ) {
        ch = buf[x2][y2];
        buf[x2][y2] = buf[x1][y1];
        if (isvalid(buf, x1, y1, ch)) {
            buf[x2][y2] = ch;
            return true;
        }
        buf[x2][y2] = ch;
    }

    return false;
}

Puzzle::State Puzzle::toState(char buf[MAXN][MAXN])
{
    static int cnt[8];
    State ret;
    int k;
    bool flag = true, loop = true;

    do {
        loop = false;
        // clear
        for (int i = 0; i < n; i++) {
            k = 0;
            while (k < m - 2) {
                if (buf[i][k] != 0 && abs(buf[i][k + 1]) == abs(buf[i][k]) && abs(buf[i][k + 2]) == abs(buf[i][k])) {
                    buf[i][k] = -abs(buf[i][k]);
                    while (++k < m && abs(buf[i][k]) == -buf[i][k - 1]) {
                        buf[i][k] = buf[i][k - 1];
                    }
                    loop = true;
                }
                else {
                    ++k;
                }
            }
        }
        for (int j = 0; j < m; j++) {
            k = 0;
            while (k < n - 2) {
                if (buf[k][j] != 0 && abs(buf[k + 1][j]) == abs(buf[k][j]) && abs(buf[k + 2][j]) == abs(buf[k][j])) {
                    buf[k][j] = -abs(buf[k][j]);
                    while (++k < n && abs(buf[k][j]) == -buf[k - 1][j]) {
                        buf[k][j] = buf[k - 1][j];
                    }
                    loop = true;
                }
                else {
                    ++k;
                }
            }
        }
        if (!loop) {
            break;
        }
        for (int i = 1; i < 8; i++) {
            cnt[i] = 0;
        }
        // fall
        for (int j = 0; j < m; j++) {
            k = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (buf[i][j] <= 0) {
                    continue;
                }
                buf[k--][j] = buf[i][j];
                ++cnt[buf[i][j]];
            }
            while (k >= 0) {
                buf[k--][j] = 0;
            }
        }
        for (int i = 1; i < 8; i++) {
            // 强剪枝
            if (cnt[i] > 0 && cnt[i] < 3) {
                flag = false;
                break;
            }
        }
    } while (flag);

    if (!flag) {
        ret.a[0] = -1;
    }
    else {
        for (int i = 0; i < n; i++) {
            ret.a[i] = 0;
            for (int j = 0; j < m; j++) {
                ret.a[i] ^= (buf[i][j] << 3 * j);
            }
        }
    }

    return ret;
}

bool Puzzle::run()
{
    int n, m;

    if (scanf("%d%d", &n, &m) == EOF) {
        return false;
    }

    Puzzle p(n, m);
    char ch;

    State::n = n;
    for (int i = 0; i < State::n; i++) {
        END.a[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while((ch = getchar()) == '\n');
            switch (ch) {
                case ' ': p.s[0][i][j] = 0; break;
                case 'B': p.s[0][i][j] = 1; break;
                case 'G': p.s[0][i][j] = 2; break;
                case 'R': p.s[0][i][j] = 3; break;
                case 'Y': p.s[0][i][j] = 4; break;
                case 'O': p.s[0][i][j] = 5; break;
                case 'P': p.s[0][i][j] = 6; break;
                case 'M': p.s[0][i][j] = 7; break;
            }
        }
    }
    p.vs[0] = p.toState(p.s[0]);
    try {
        p.dfs(0);
        //throw 1;
    }
    catch(Solved& sig) {

    }

    return true;
}

int main()
{
    while (Puzzle::run());

    return 0;
}

//3043668  	2008-08-20 21:45:23  	Accepted 	3020 	C++  	00:04.40  	7568K  	Re:ReJudge

//Run ID 	Submit Time 	Judge Status 	Problem ID 	Language 	Run Time(ms) 	Run Memory(KB) 	User Name 	Admin
//3001273 	2012-08-05 11:13:30 	Accepted 	3020 	C++ 	2090 	7220 	watashi 	Source
