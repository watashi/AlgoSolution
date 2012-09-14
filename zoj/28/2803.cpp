#include <string>
#include <sstream>
#include <iostream>
using namespace std;
enum Dir{
    N = 0,
    E = 1,
    S = 2,
    W = 3
};
const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Instruction
{
    friend class CrashingRobots;
private:
    int robot;
    char action;
    int repeat;
public:
    friend inline istream& operator>>(istream& is, Instruction& that)
    {
        is >> that.robot >> that.action >> that.repeat;
        return is;
    }
};
class Robot
{
    friend class CrashingRobots;
private:
    int x;
    int y;
    int d;
public:
    friend inline istream& operator>>(istream& is, Robot& that)
    {
        char tmp;
        is >> that.x >> that.y >> tmp;
        switch(tmp){
            case 'N': that.d = 0;break;
            case 'E': that.d = 1;break;
            case 'S': that.d = 2;break;
            case 'W': that.d = 3;break;
        }
        return is;
    }
};
class CrashingRobots
{
private:
    int a, b;
    int n, m;
    int mp[101][101];
    Robot rob[101];
    Instruction ins[101];
    string ans;
    inline bool isvalid(int x, int y)
    {
        return x > 0 && y > 0 && x <= a && y <= b;
    }
    bool doit(const Instruction& that)
    {
        int id = that.robot;
        if(that.action == 'L'){
            rob[id].d = (rob[id].d - that.repeat) % 4;
            if(rob[id].d < 0) rob[id].d += 4;
            return true;
        }
        else if(that.action == 'R'){
            rob[id].d = (rob[id].d + that.repeat) % 4;
            return true;
        }
        else{
            int x = rob[id].x, y = rob[id].y, d = rob[id].d;
            mp[x][y] = 0;
            for (int ri = 0; ri < that.repeat; ri++){
                x += dir[d][0];
                y += dir[d][1];
                if(!isvalid(x, y)){
                    ostringstream oss;
                    oss << "Robot " << id << " crashes into the wall";
                    oss.flush();
                    ans = oss.str();
                    return false;
                }
                else if(mp[x][y]){
                    ostringstream oss;
                    oss << "Robot " << id << " crashes into robot " << mp[x][y];
                    oss.flush();
                    ans = oss.str();
                    return false;
                }
            }
            rob[id].x = x;
            rob[id].y = y;
            mp[x][y] = id;
            return true;
        }
    }
public:
    friend inline istream& operator>>(istream& is, CrashingRobots& that)
    {
        is >> that.a >> that.b;
        is >> that.n >> that.m;
        for (int i = 1; i <= that.n; i++)
            is >> that.rob[i];
        for (int i = 1; i <= that.m; i++)
            is >> that.ins[i];
        that.ans = "OK";
        return is;
    }
    void simulate()
    {
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                mp[i][j] = 0;
        for (int k = 1; k <= n; k++)
            mp[rob[k].x][rob[k].y] = k;
        for (int k = 1; k <= m; k++)
            if(!doit(ins[k])) break;
    }
    friend inline ostream& operator<<(ostream& os, const CrashingRobots& that)
    {
        os << that.ans;
        return os;
    }
};
int main()
{
    int re;

    cin >> re;
    while(re--){
        CrashingRobots crashing_robots;
        cin >> crashing_robots;
        crashing_robots.simulate();
        cout << crashing_robots << endl;
    }
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2709195   2007-12-22 13:39:25     Accepted    2803    C++     00:00.03    912K    ¤ï¤¿¤·

// 2012-09-07 01:40:27 | Accepted | 2803 | C++ | 0 | 188 | watashi | Source
