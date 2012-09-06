#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

// RegisterRef
class RegisterRef
{
public:
    RegisterRef(const int cnt, double &a1, double &a2, double &a3, double &a4);
    int size() const;
    double& operator[](const int index);
private:
    static double nullRef;
    const int cnt;
    double &a1, &a2, &a3, &a4;
};

double RegisterRef::nullRef = 0;

RegisterRef::RegisterRef(const int cnt = 0, double &a1 = nullRef, double &a2 = nullRef, double &a3 = nullRef, double &a4 = nullRef)
    : cnt(cnt), a1(a1), a2(a2), a3(a3), a4(a4)
{
}

int RegisterRef::size() const
{
    return cnt;
}

double& RegisterRef::operator [](const int index)
{
    switch(index)
    {
    case 1: return a1;
    case 2: return a2;
    case 3: return a3;
    case 4: return a4;
    default: return nullRef;
    }
}

// RegisterVector
class RegisterVector
{
public:
    RegisterVector(const double a1, const double a2, const double a3, const double a4);
    RegisterRef operator[](const string& index);
    double& operator[](const int index);
private:
    static double nullRef;
    double a1, a2, a3, a4;
};

double RegisterVector::nullRef = 0;

RegisterVector::RegisterVector(const double a1 = 0, const double a2 = 0, const double a3 = 0, const double a4 = 0)
    : a1(a1), a2(a2), a3(a3), a4(a4)
{
}

RegisterRef RegisterVector::operator [](const std::string &index)
{
    int Cnt;
    string Index = index;

    if(Index == "")
        Index = "xyzw";
    Cnt = (int)Index.length();
    while(Index.length() < 4)
        Index.append("0");
    for (int i = 0; i < 4; i++) {
        switch(Index[i]) {
            case 'x': case 'r':
                Index[i] = '1';
                break;
            case 'y': case 'g':
                Index[i] = '2';
                break;
            case 'z': case 'b':
                Index[i] = '3';
                break;
            case 'w': case 'a':
                Index[i] = '4';
                break;
        }
    }

    return RegisterRef(Cnt, (*this)[Index[0] - '0'], (*this)[Index[1] - '0'], (*this)[Index[2] - '0'], (*this)[Index[3] - '0']);
}

double& RegisterVector::operator [](const int index)
{
    switch(index)
    {
    case 1: return a1;
    case 2: return a2;
    case 3: return a3;
    case 4: return a4;
    default: return nullRef;
    }
}

// Simulator

class Simulator
{
public:
    Simulator();
    void doit(const string& cmd);
    string show();
private:
    RegisterRef parse(const string& str);
    void add(const string& cmd);
    void def(const string& cmd);
    void dp3(const string& cmd);
    void frc(const string& cmd);
    void mad(const string& cmd);
    void max(const string& cmd);
    void mov(const string& cmd);
    void mul(const string& cmd);
    RegisterVector /*t[8], */oC[1], r[32], c[32];
    int slots;
};

Simulator::Simulator() : slots(0)
{
}

void Simulator::doit(const string& cmd)
{
    istringstream iss(cmd);
    string str, arg;

    iss >> str;
    getline(iss, arg);
    for (size_t i = 0; i < arg.length(); i++)
        if(arg[i] == ',' || arg[i] == ';')
            arg[i] = ' ';
    if(str == "add")
        add(arg);
    else if(str == "def")
        def(arg);
    else if(str == "dp3")
        dp3(arg);
    else if(str == "frc")
        frc(arg);
    else if(str == "mad")
        mad(arg);
    else if(str == "max")
        max(arg);
    else if(str == "mov")
        mov(arg);
    else if(str == "mul")
        mul(arg);
}

string Simulator::show()
{
    ostringstream oss;

    oss << setiosflags(ios::fixed) << setprecision(3) <<
        oC[0][1] << " " << oC[0][2] << " " << oC[0][3] << " " << oC[0][4] << " " << slots;

    return oss.str();
}

RegisterRef Simulator::parse(const string& str)
{
    char t = 'o';
    int i = 0;
    string index = "";

    if(str[0] == 'o')
        return oC[i][index];
    i = str[1] - '0';
    if(str.length() > 2 && str[2] != '.')
        i = i * 10 + str[2] - '0';
    if(str.find('.') != string::npos)
        index = str.substr(str.find('.') + 1);
    if(str[0] == 'c')
        return c[i][index];
    else
        return r[i][index];
}

void Simulator::add(const string& cmd)
{
    istringstream iss(cmd);
    string str0, str1, str2;

    iss >> str0 >> str1 >> str2;

    RegisterRef dst(parse(str0)), src0(parse(str1)), src1(parse(str2));

    for (int i = 1; i <= dst.size(); i++)
        dst[i] = src0[i] + src1[i];
    ++slots;
}

void Simulator::def(const std::string &cmd)
{
    istringstream iss(cmd);
    string str;

    iss >> str;

    RegisterRef dst(parse(str));

    iss >> dst[1] >> dst[2] >> dst[3] >> dst[4];
}

void Simulator::dp3(const string& cmd)
{
    istringstream iss(cmd);
    string str0, str1, str2;

    iss >> str0 >> str1 >> str2;

    RegisterRef dst(parse(str0)), src0(parse(str1)), src1(parse(str2));
    double ans = 0;

    for (int i = 1; i <= 3; i++)
        ans += src0[i] * src1[i];
    for (int i = 1; i <= dst.size(); i++)
        dst[i] = ans;
    ++slots;
}

void Simulator::frc(const string& cmd)
{
    istringstream iss(cmd);
    string str0, str1;

    iss >> str0 >> str1;

    RegisterRef dst(parse(str0)), src(parse(str1));

    for (int i = 1; i <= dst.size(); i++)
        dst[i] = src[i] - floor(src[i]);
    ++slots;
}

void Simulator::mad(const string& cmd)
{
    istringstream iss(cmd);
    string str0, str1, str2, str3;

    iss >> str0 >> str1 >> str2 >> str3;

    RegisterRef dst(parse(str0)), src0(parse(str1)), src1(parse(str2)), src2(parse(str3));

    for (int i = 1; i <= dst.size(); i++)
        dst[i] = src0[i] * src1[i] + src2[i];
    slots += 2;
}

void Simulator::max(const std::string &cmd)
{
    istringstream iss(cmd);
    string str0, str1, str2;

    iss >> str0 >> str1 >> str2;

    RegisterRef dst(parse(str0)), src0(parse(str1)), src1(parse(str2));

    for (int i = 1; i <= dst.size(); i++)
        dst[i] = (src0[i] >= src1[i]) ? src0[i] : src1[i];
    ++slots;
}

void Simulator::mov(const std::string &cmd)
{
    istringstream iss(cmd);
    string str0, str1;

    iss >> str0 >> str1;

    RegisterRef dst(parse(str0)), src(parse(str1));

    for (int i = 1; i <= dst.size(); i++)
        dst[i] = src[i];
    ++slots;
}

void Simulator::mul(const std::string &cmd)
{
    istringstream iss(cmd);
    string str0, str1, str2;

    iss >> str0 >> str1 >> str2;

    RegisterRef dst(parse(str0)), src0(parse(str1)), src1(parse(str2));

    for (int i = 1; i <= dst.size(); i++)
        dst[i] = src0[i] * src1[i];
    ++slots;
}

//

int main(void)
{
    string cmd;

    while(getline(cin, cmd)) {
        Simulator* simulator = new Simulator();
        while(cmd != "") {
            simulator->doit(cmd);
            getline(cin, cmd);
        }
        cout << simulator->show() << endl;
        delete simulator;
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2838170 2008-04-11 17:13:54 Accepted 2145 C++ 00:00.00 884K ¤ï¤¿¤·

// 2012-09-07 01:14:12 | Accepted | 2145 | C++ | 0 | 188 | watashi | Source
