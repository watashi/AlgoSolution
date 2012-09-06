#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Die
{
public:
    bool init(const int top, const int front, const int x, const int y);
    void roll(const char dir);
    int top() const;
    int front() const;
    int x() const;
    int y() const;
private:
    int _x, _y;
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
    static const int b[24][6];
};

const Die::Dir Die::north[4] = {North, Up, South, Down};
const Die::Dir Die::south[4] = {South, Up, North, Down};
const Die::Dir Die::west[4] = {West, Up, East, Down};
const Die::Dir Die::east[4] = {East, Up, West, Down};

const int Die::b[24][6] = {
    {1, 6, 5, 2, 4, 3},
    {1, 6, 4, 3, 2, 5},
    {1, 6, 3, 4, 5, 2},
    {1, 6, 2, 5, 3, 4},
    {2, 5, 6, 1, 3, 4},
    {2, 5, 4, 3, 6, 1},
    {2, 5, 3, 4, 1, 6},
    {2, 5, 1, 6, 4, 3},
    {3, 4, 6, 1, 5, 2},
    {3, 4, 5, 2, 1, 6},
    {3, 4, 2, 5, 6, 1},
    {3, 4, 1, 6, 2, 5},
    {4, 3, 6, 1, 2, 5},
    {4, 3, 5, 2, 6, 1},
    {4, 3, 2, 5, 1, 6},
    {4, 3, 1, 6, 5, 2},
    {5, 2, 6, 1, 4, 3},
    {5, 2, 4, 3, 1, 6},
    {5, 2, 3, 4, 6, 1},
    {5, 2, 1, 6, 3, 4},
    {6, 1, 5, 2, 3, 4},
    {6, 1, 4, 3, 5, 2},
    {6, 1, 3, 4, 2, 5},
    {6, 1, 2, 5, 4, 3}
};

bool Die::init(const int top, const int front, const int x, const int y)
{
    bool ret = false;

    _x = x;
    _y = y;
    for (int i = 0; i < 24; i++)
        if(top == b[i][0] && front == b[i][3]) {
            ret = true;
            for (int j = 0; j < 6; j++)
                a[j] = b[i][j];
            break;
        }

    return ret;
}

void Die::roll(const char dir)
{
    const Dir* p;

    switch(dir) {
        case 'N': p = north; ++_y; break;
        case 'S': p = south; --_y; break;
        case 'W': p = west; --_x; break;
        case 'E': p = east; ++_x; break;
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

int Die::front() const
{
    return a[South];
}

int Die::x() const
{
    return _x;
}

int Die::y() const
{
    return _y;
}


int main(void)
{
    int t, f;
    char ch;
    string str;
    istringstream iss;
    Die die;

    cout << "Problem 2 by team x" << endl;
    cout.setf(ios::right);
    while(cin >> t >> f) {
        getline(cin, str);
        cout << endl;
        if(!die.init(t, f, 0, 0)) {
            cout << "Invalid initial orientation:     top =" <<
                setw(2) << t << "  front =" << setw(2) << f << endl;
        }
        else {
            cout << "Initial orientation:             top =" <<
                setw(2) << t << "  front =" << setw(2) << f << endl;
            cout << "Moves:" << str << endl;
            iss.clear();
            iss.str(str);
            while(iss >> ch)
                die.roll(ch);
            cout << "Final orientation and position:  top =" <<
                setw(2) << die.top() << "  front =" << setw(2) << die.front() <<
                "  x =" << setw(4) << die.x() << "  y =" << setw(4) << die.y() << endl;
        }
    }
    cout << "End of problem 2 by team x" << endl;

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2840507   2008-04-12 19:18:44     Accepted    1208    C++     00:00.00    872K    Re:ReJudge

// 2012-09-07 00:41:56 | Accepted | 1208 | C++ | 0 | 188 | watashi | Source
