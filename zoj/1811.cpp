#include <cstdio>

class RANDOM
{
    public:
        void cget();
        void srand();
        int operator()();
    private:
        int _r[1000];
        int _i, _n;
};

void RANDOM::cget()
{
    _n = 0;
    while(scanf("%d", &_r[_n]) != EOF && _r[_n++] != 0);
}

void RANDOM::srand()
{
    _i = -1;
}

int RANDOM::operator()()
{
    ++_i;
    if(_i == _n)
        _i = 0;
    return _r[_i];
}

class Game
{
    public:
        void init();
        bool cget();
        void cput();
    private:
        bool move(int i);
        int n, p[11], s[11];
        int map[101];
        RANDOM rand;
};

void Game::init()
{
    rand.cget();
}

bool Game::cget()
{
    int a, b;

    for (int i = 0; i <= 100; i++)
        map[i] = i;
    scanf("%d", &n);
    if(n == 0)
        return false;
    while(scanf("%d%d", &a, &b) != EOF && a > 0 && b > 0)
        map[a] = b;
    while(scanf("%d", &a) != EOF && a != 0)
        if(a > 0)
            map[a] = 101;
        else
            map[-a] = -1;

    return true;
}

void Game::cput()
{
    rand.srand();
    for (int i = 1; i <= n; i++) {
        p[i] = 0;
        s[i] = false;
    }
    while(true)
        for (int i = 1; i <= n; i++)
            if(move(i)) {
                printf("%d\n", i);
                return;
            }
}

bool Game::move(int i)
{
    int r;

    if(s[i]) {
        s[i] = false;
        return false;
    }
    r = rand();
    p[i] += r;
    if(p[i] > 100) {
        p[i] -= r;
        return false;
    }
    else if(p[i] == 100) {
        return true;
    }
    else {
        switch(map[p[i]]) {
            case -1:
                s[i] = true;
                return false;
            case 101:
                return move(i);
            default:
                p[i] = map[p[i]];// < 100
                return false;
        }
    }
}

int main(void)
{
    Game game;

    game.init();
    while(game.cget())
        game.cput();

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2843872   2008-04-14 19:16:00     Accepted    1811    C++     00:00.00    436K    Re:ReJudge

// 2012-09-07 01:01:39 | Accepted | 1811 | C++ | 0 | 180 | watashi | Source
