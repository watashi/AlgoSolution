#include <cstdio>

class Die
{
public:
    Die();
    void roll(const char *const dir);
    int top() const;
private:
    int a[6];
    enum Dir
    {
        Up,
        Down,
        North,
        South,
        West,
        East
    };
    static const Dir north[4], south[4], west[4], east[4];
};

const Die::Dir Die::north[4] = {North, Up, South, Down};
const Die::Dir Die::south[4] = {South, Up, North, Down};
const Die::Dir Die::west[4] = {West, Up, East, Down};
const Die::Dir Die::east[4] = {East, Up, West, Down};

Die::Die()
{
    a[Up] = 1;
    a[Down] = 6;
    a[North] = 2;
    a[South] = 5;
    a[West] = 3;
    a[East] = 4;
}

void Die::roll(const char *const dir)
{
    const Dir* p;

    switch(dir[0]) {
        case 'n': p = north; break;
        case 's': p = south; break;
        case 'w': p = west; break;
        case 'e': p = east; break;
        default: p = NULL; break;
    }

    int t = a[p[0]];

    a[p[0]] = a[p[1]];
    a[p[1]] = a[p[2]];
    a[p[2]] = a[p[3]];
    a[p[3]] = t;
}

int Die::top() const
{
    return a[Up];
}

char buf[80];

int main(void)
{
    int n;
    Die* die;

    while(scanf("%d", &n) != EOF && n > 0) {
        die = new Die();
        while(n--) {
            scanf("%s", buf);
            die->roll(buf);
        }
        printf("%d\n", die->top());
        delete die;
        die = NULL;
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2839913   2008-04-12 14:41:28     Accepted    1667    C++     00:00.00    436K    Re:ReJudge

// 2012-09-07 00:57:35 | Accepted | 1667 | C++ | 0 | 180 | watashi | Source
