// There needn't be any exits from the maze.

#include <cstdio>

class AI
{
    static const int dir[4][2];
private:
    int r, c;
    char mp[66][66];
    int x, y, z;
public:
    bool cget();
    void cput();
    bool doit(char ch);
};

const int AI::dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool AI::cget()
{
    if(scanf("%d%d ", &r, &c) != 2) return false;
    for (int i = 0; i < r; i++)
        gets(mp[i]);
    scanf("%d%d", &x, &y);
    --x;
    --y;
    z = 0;
    return true;
}

void AI::cput()
{
    printf("%d %d ", x + 1, y + 1);
    switch(z) {
        case 0: putchar('N'); break;
        case 1: putchar('E'); break;
        case 2: putchar('S'); break;
        case 3: putchar('W'); break;
    }
    putchar('\n');
}

bool AI::doit(char ch)
{
    int xx, yy;

    switch(ch) {
        case 'Q':
            return false;
        case 'R':
            ++z;
            if(z == 4) z = 0;
            return true;
        case 'L':
            --z;
            if(z == -1) z = 3;
            return true;
        case 'F':
            xx = x + dir[z][0];
            yy = y + dir[z][1];
            if(mp[xx][yy] != '*') {
                x = xx;
                y = yy;
            }
            return true;
        default:
            return false;
    }
}

int main()
{
    char ch;
    AI ai;

    while(ai.cget()) {
        while(scanf(" %c", &ch) != EOF && ai.doit(ch));
        ai.cput();
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2796443 2008-03-22 13:41:15 Accepted 1824 C++ 00:00.00 392K ¤ï¤¿¤·

// 2012-09-07 01:01:57 | Accepted | 1824 | C++ | 0 | 180 | watashi | Source
