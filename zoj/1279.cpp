#include <string>
#include <iostream>
using namespace std;

class NUM;
class OP;

class NUM
{
    friend class OP;
    friend istream& operator>>(istream& is, NUM& num);
    friend bool operator==(const NUM& lhs, const NUM& rhs);
public:
    NUM(int num = 0);
private:
    int num;
};

istream& operator>>(istream& is, NUM& num)
{
    string str;

    is >> str;
    num.num = 0;
    for (size_t i = 0; i < str.length(); i++) {
        num.num <<= 2;
        switch(str[i]) {
            case 'V': break;
            case 'U': ++num.num; break;
            case 'C': num.num += 2; break;
            case 'D': num.num += 3; break;
        }
    }

    return is;
}

bool operator==(const NUM& lhs, const NUM& rhs)
{
    return lhs.num == rhs.num;
}

NUM::NUM(int num) : num(num)
{
}

class OP
{
    friend istream& operator>>(istream& is, OP& op);
public:
    OP(char op = 'N');
    void operator()(const NUM& lhs, NUM& rhs);
private:
    char op;
};

istream& operator>>(istream& is, OP& op)
{
    is >> op.op;

    return is;
}

OP::OP(char op) : op(op)
{
}

void OP::operator ()(const NUM &lhs, NUM &rhs)
{
    switch(op) {
        case 'A':
            rhs.num += lhs.num;
            break;
        case 'L':
            rhs.num <<= 2;
            break;
        case 'R':
            rhs.num >>= 2;
            break;
        case 'N':
            break;
    }
}

int main(void)
{
    int re;
    NUM num1, num2, ans;
    OP op1, op2, op3;

    cout << "COWCULATIONS OUTPUT" << endl;
    cin >> re;
    while(re--) {
        cin >> num1 >> num2 >> op1 >> op2 >> op3 >> ans;
        op1(num1, num2);
        op2(num1, num2);
        op3(num1, num2);
        cout << ((num2 == ans) ? "YES" : "NO") << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2845082 2008-04-15 14:14:52 Accepted 1279 C++ 00:00.00 836K Re:ReJudge

// 2012-09-07 00:44:10 | Accepted | 1279 | C++ | 0 | 188 | watashi | Source
