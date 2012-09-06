#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Pyraminx
{
public:
    Pyraminx();
    void DoIt(const string& cmd);
    const string ToString() const;
private:
    char ch[36];
    inline static void Rotate(char& a, char& b, char& c);
    void RotateA();
    void RotateB();
    void RotateC();
    void RotateD();
};

Pyraminx::Pyraminx()
{
    for (int i = 0; i < 9; i++)
        ch[i] = 'R';
    for (int i = 9; i < 18; i++)
        ch[i] = 'G';
    for (int i = 18; i < 27; i++)
        ch[i] = 'B';
    for (int i = 27; i < 36; i++)
        ch[i] = 'Y';
}

void Pyraminx::DoIt(const string& cmd)
{
    switch(cmd[0]) {
        case 'A':
            RotateA();
            if(cmd[1] == '-')
                RotateA();
            break;
        case 'B':
            RotateB();
            if(cmd[1] == '-')
                RotateB();
            break;
        case 'C':
            RotateC();
            if(cmd[1] == '-')
                RotateC();
            break;
        case 'D':
            RotateD();
            if(cmd[1] == '-')
                RotateD();
            break;
    }
}

const string Pyraminx::ToString() const
{
    ostringstream oss;

    oss <<
        "    /" << ch[0] << "\\        /" << ch[9] << "\\        /" << ch[18]<< "\\\n" <<
        "  /" << ch[1] << "\\" << ch[2] << "/" << ch[3] << "\\  " <<
        "  /" << ch[10] << "\\" << ch[11] << "/" << ch[12] << "\\  " <<
        "  /" << ch[19] << "\\" << ch[20] << "/" << ch[21] << "\\\n" <<
        "/" << ch[4] << "\\" << ch[5] << "/" << ch[6] << "\\" << ch[7] << "/" << ch[8] << "\\" <<
        "/" << ch[13] << "\\" << ch[14] << "/" << ch[15] << "\\" << ch[16] << "/" << ch[17] << "\\" <<
        "/" << ch[22] << "\\" << ch[23] << "/" << ch[24] << "\\" << ch[25] << "/" << ch[26] << "\\\n" <<
        "           \\" << ch[27] << "/" << ch[28] << "\\" << ch[29] << "/" << ch[30] << "\\" << ch[31] << "/\n" <<
        "             \\" << ch[32] << "/" << ch[33] << "\\" << ch[34] << "/\n" <<
        "               \\" << ch[35] << "/\n";

    return oss.str();
}

void Pyraminx::Rotate(char &a, char &b, char &c)
{
    char ch = a;

    a = b;
    b = c;
    c = ch;
}

void Pyraminx::RotateA()
{
    Rotate(ch[0], ch[9], ch[18]);
    Rotate(ch[1], ch[10], ch[19]);
    Rotate(ch[2], ch[11], ch[20]);
    Rotate(ch[3], ch[12], ch[21]);
}

void Pyraminx::RotateB()
{
    Rotate(ch[8], ch[27], ch[13]);
    Rotate(ch[7], ch[28], ch[14]);
    Rotate(ch[3], ch[32], ch[15]);
    Rotate(ch[6], ch[29], ch[10]);
}

void Pyraminx::RotateC()
{
    Rotate(ch[22], ch[17], ch[31]);
    Rotate(ch[23], ch[16], ch[30]);
    Rotate(ch[19], ch[15], ch[34]);
    Rotate(ch[24], ch[12], ch[29]);
}

void Pyraminx::RotateD()
{
    Rotate(ch[26], ch[35], ch[4]);
    Rotate(ch[25], ch[33], ch[5]);
    Rotate(ch[24], ch[32], ch[1]);
    Rotate(ch[21], ch[34], ch[6]);
}

int main(void)
{
    bool blank = false;
    string cmd;

    while(cin >> cmd) {
        if(cmd == "START") {
            Pyraminx pyramix;
            while(cin >> cmd) {
                if(cmd == "END")
                    break;
                pyramix.DoIt(cmd);
            }
            if(blank) cout << endl;
            else blank = true;
            cout << pyramix.ToString();
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801448   2009-03-24 04:59:39     Accepted    3074    C++     0   184     watashi@Zodiac

// 2012-09-07 02:00:18 | Accepted | 3074 | C++ | 0 | 188 | watashi | Source
