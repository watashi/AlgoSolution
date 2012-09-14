#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Term
{
    int uns;
    int pos;
    int neg;
    inline void clear()
    {
        uns = pos = neg = 0;
    }
};
class Word
{
private:
    string str;
    int mask;
public:
    Word(const char* buf)
    {
        str = (string)buf;
        mask = 0;
        for (size_t i = 0; i < str.length(); i++)
            mask |= (1 << (str[i] - 'a'));
    }
    inline void cput() const
    {
        puts(str.c_str());
    }
    inline bool operator<(const Word& rhs) const
    {
        return str < rhs.str;
    }
    inline bool ismatch(const Term& term) const
    {
        return ((mask & term.uns) != 0)
            && ((mask & term.pos) == term.pos)
            && ((mask & term.neg) == 0);
    }
};

vector <Word> vs;
Term terms[40];
int pos, cnt;
bool flag;
char buf[88];

int main(void)
{
    while(gets(buf) != NULL && buf[0] != '#') {
        vs.clear();
        do {
            vs.push_back(buf);
            gets(buf);
        }while(buf[0] != '*');
        sort(vs.begin(), vs.end());
        while(gets(buf) != NULL && buf[0] != '*') {
            pos = 0;
            for (cnt = 0; buf[pos]; ++cnt) {
                terms[cnt].clear();
                while(true) {
                    if(buf[pos] == '\0') break;
                    else if(buf[pos] == '|') {
                        ++pos;
                        break;
                    }
                    else if(buf[pos] == '+') terms[cnt].pos |= 1 << buf[++pos] - 'a';
                    else if(buf[pos] == '-') terms[cnt].neg |= 1 << buf[++pos] - 'a';
                    else terms[cnt].uns |= 1 << buf[pos] - 'a';
                    ++pos;
                }
                if(terms[cnt].pos & terms[cnt].neg != 0) --cnt;
            }
            flag = true;
            for(size_t i = 0; flag && i < vs.size(); i++)
                for (int j = 0; j < cnt; j++)
                    if(vs[i].ismatch(terms[j])) {
                        vs[i].cput();
                        flag = false;
                        break;
                    }
            if(flag) puts("NONE");
        }
        puts("$");
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2769883 2008-03-04 16:14:30 Accepted 2816 C++ 00:00.01 848K ¤ï¤¿¤·

// 2012-09-07 01:41:09 | Accepted | 2816 | C++ | 0 | 180 | watashi | Source
