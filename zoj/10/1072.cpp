#include <string>
#include <iostream>
using namespace std;
class Microprocessor
{
private:
    bool running;
    int mem[256];
    int accA, accB;
    int p;

    inline int char2int(char ch) const
    {
        if('A' <= ch && ch <= 'F') return ch - 'A' + 10;
        else return ch - '0';
    }
    inline char int2char(int x) const
    {
        if(x < 10) return x + '0';
        else return x - 10 + 'A';
    }
    inline int format(int x) const
    {
        return (x + 16) % 16;
    }
    inline int address() const
    {
        return (mem[p] << 4) + mem[p + 1];
    }

    inline void LD()
    {
        p++;
        accA = mem[address()];
        p+=2;
    }
    inline void ST()
    {
        p++;
        mem[address()] = accA;
        p+=2;
    }
    inline void SWP()
    {
        int accT;
        accT = accA;
        accA = accB;
        accB = accT;
        p++;
    }
    inline void ADD()
    {
        int sum = accA + accB;
        accB = sum >> 4;
        accA = sum - (accB << 4);
        accB = format(accB);//
        accA = format(accA);//
        p++;
    }
    inline void INC()
    {
        accA = format(accA + 1);
        p++;
    }
    inline void DEC()
    {
        accA = format(accA - 1);
        p++;
    }
    inline void BZ()
    {
        p++;
        if(accA == 0) p = address();
        else p+=2;
    }
    inline void BR()
    {
        p++;
        p = address();
    }
    inline void STP()
    {
        running = false;
    }
public:
    int count;

    inline void step()
    {
        count++;
        switch(mem[p]) {
        case 0: LD(); break;
        case 1: ST(); break;
        case 2: SWP(); break;
        case 3: ADD(); break;
        case 4: INC(); break;
        case 5: DEC(); break;
        case 6: BZ(); break;
        case 7: BR(); break;
        case 8: STP(); break;
        }
    }
    void setup(string str)
    {
        accA = accB = 0;
        count = 0;
        p = 0;
        for (int i = 0; i < 256; i++)
            mem[i] = char2int(str[i]);
        running = true;
    }
    void run()
    {
        while(running)
            step();
    }
    friend inline istream& operator>>(istream& is, Microprocessor& it)
    {
        string str = "";
        string cur;
        while(str.length() < 256 && is >> cur)
            str += cur;
        if(str.length() >= 256) it.setup(str);
        return is;
    }
    friend inline ostream& operator<<(ostream& os, const Microprocessor& it)
    {
        for (int i = 0; i < 256; i++)
            os << it.int2char(it.mem[i]);
        return os;
    }
};
int main()
{
    Microprocessor microprocessor;
    while(cin >> microprocessor) {
        microprocessor.run();
        if(microprocessor.count > 1) cout << microprocessor << endl;
        else break;
    }
    return 0;
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2715766 2007-12-29 09:19:53 Accepted 1072 C++ 00:00.01 860K ¤ï¤¿¤·

// 2012-09-07 00:35:38 | Accepted | 1072 | C++ | 0 | 188 | watashi | Source
