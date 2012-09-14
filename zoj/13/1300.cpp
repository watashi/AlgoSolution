#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Border
{
private:
    static const int SIZE = 32;
    bool illegalRef;
    int x, y;
    bool cl[SIZE + 2][SIZE + 2];
    bool eg[SIZE + 2][SIZE + 2][2]; // 0 for South, 1 for East

    // Cells
    inline bool& CN(int x, int y) { return eg[x][y][1]; }
    inline bool& CS(int x, int y) { if(x > SIZE) return illegalRef; return eg[x + 1][y][1]; }
    inline bool& CW(int x, int y) { return eg[x][y][0]; }
    inline bool& CE(int x, int y) { if(y > SIZE) return illegalRef; return eg[x][y + 1][0]; }

    // Vertex // Vertex is the lefttop corner of Cell
    inline bool& VN(int x, int y) { /*if(x == 0) return illegalRef;*/ return eg[x - 1][y][0]; }
    inline bool& VS(int x, int y) { /*if(x == n) return illegalRef;*/ return eg[x][y][0]; }
    inline bool& VW(int x, int y) { /*if(y == 0) return illegalRef;*/ return eg[x][y - 1][1]; }
    inline bool& VE(int x, int y) { /*if(y == m) return illegalRef;*/ return eg[x][y][1]; }

    void floodfill(int x,int y)
    {
        cl[x][y] = true;
        if(x && CN(x, y) == false && cl[x - 1][y] == false) floodfill(x - 1, y);
        if(x <= SIZE && CS(x, y) == false && cl[x + 1][y] == false) floodfill(x + 1, y);
        if(y && CW(x, y) == false && cl[x][y - 1] == false) floodfill(x, y - 1);
        if(y <= SIZE && CE(x, y) == false && cl[x][y + 1] == false) floodfill(x, y + 1);
    }
public:
    string ToBitmap(int ax, int ay, const string& str)
    {
        illegalRef = true;
        fill(cl[0], cl[SIZE + 2], false);
        fill(eg[0][0], eg[SIZE + 2][0], false);
        x = SIZE - ay + 1;
        y = ax + 1;
        for (int i = 0; str[i] != '.'; i++) {
            switch(str[i]) {
                case 'N': VN(x, y) = true; --x; break;
                case 'S': VS(x, y) = true; ++x; break;
                case 'W': VW(x, y) = true; --y; break;
                case 'E': VE(x, y) = true; ++y; break;
            }
        }
        floodfill(0, 0);
        string res = "";
        for (int i = 1; i <= SIZE; i++) {
            for (int j = 1; j <= SIZE; j++)
                if(cl[i][j] == true && (cl[i - 1][j] == false || cl[i + 1][j] == false || cl[i][j - 1] == false || cl[i][j + 1] == false))
                    res += 'X';
                else res += '.';
            res += '\n';
        }
        return res;
    }
};

int main(void)
{
    Border doit;
    int re;
    cin >> re;
    for (int ri = 1; ri <= re; ++ri) {
        int x, y;
        string cur;
        cin >> x >> y >> cur;
        cout << "Bitmap #" << ri << '\n' << doit.ToBitmap(x, y, cur) << endl;
    }
    return 0;
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2744569 2008-02-05 15:09:38 Accepted 1300 C++ 00:00.01 908K ¤ï¤¿¤·

// 2012-09-07 00:45:05 | Accepted | 1300 | C++ | 0 | 188 | watashi | Source
