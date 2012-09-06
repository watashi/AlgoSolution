#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[10001], str[128];
string i2s[1000];
map<string, int> s2i;
map<int, int> mp;

void init()
{
    i2s[0] = "";
    i2s[1] = "I";
    i2s[2] = "II";
    i2s[3] = "III";
    i2s[4] = "IV";
    i2s[5] = "V";
    i2s[6] = "VI";
    i2s[7] = "VII";
    i2s[8] = "VIII";
    i2s[9] = "IX";
    i2s[10] = "X";
    i2s[20] = "XX";
    i2s[30] = "XXX";
    i2s[40] = "XL";
    i2s[50] = "L";
    i2s[60] = "LX";
    i2s[70] = "LXX";
    i2s[80] = "LXXX";
    i2s[90] = "XC";
    for (int i = 1; i < 10; i++) {
        int t = 10 * i;
        for (int j = 1; j < 10; j++)
            i2s[t + j] = i2s[t] + i2s[j];
    }
    i2s[100] = "C";
    i2s[200] = "CC";
    i2s[300] = "CCC";
    i2s[400] = "CD";
    i2s[500] = "D";
    i2s[600] = "DC";
    i2s[700] = "DCC";
    i2s[800] = "DCCC";
    i2s[900] = "CM";
    for (int i = 1; i < 10; i++) {
        int t = 100 * i;
        for (int j = 1; j < 100; j++)
            i2s[t + j] = i2s[t] + i2s[j];
    }
    for (int k = 0; k < 1000; k++)
        s2i.insert(make_pair(i2s[k], k));
}

inline int r2i(const string& r)
{
    if(r == "O") return 0;
    int i = 0, res = 0;
    while(i < r.size() && r[i] == 'M') {
        res += 1000;
        i++;
    }
    if(i < r.size()) return res + s2i[r.substr(i)];
    else return res;
}

inline string i2r(int i)
{
    if(i == 0) return "O";
    string res = "";
    while(i >= 1000) {
        res += 'M';
        i -= 1000;
    }
    return res + i2s[i];
}

inline void doit(char p[])
{
    int i = 0, r = 0, v = 0;
    int flag, name;
    string str;

    while(p[i] != '=') {
        r *= 10;
        r += p[i] - '0';
        ++i;
    }
    p[i] = '+';
    while(p[i] != '\0') {
        if(p[i] == '-') flag = -1;
        else flag = 1;
        ++i;
        if(isdigit(p[i])) {
            name = 0;
            do {
                name *= 10;
                name += p[i] - '0';
            }while(isdigit(p[++i]));
            map<int, int>::iterator itr = mp.find(name);
            if(itr == mp.end()) {
                puts("Error");
                return;
            }
            else if(flag == -1) v -= itr -> second;
            else v += itr -> second;
        }
        else {
            str = "";
            do {
                str += p[i];
            }while(isupper(p[++i]));
            if(flag == -1) v -= r2i(str);
            else v += r2i(str);
        }
    }
    if(v < 0 || v > 10000) {
        puts("Error");
        return;
    }
    else {
        printf("%d=%s\n", r, i2r(v).c_str());
        map<int, int>::iterator itr = mp.find(r);
        if(itr == mp.end()) mp.insert(make_pair(r, v));
        else itr -> second = v;
    }
}

int main(void)
{
    init();
    while(true) {
        if(gets(buf) == NULL) break;;
        if(strcmp(buf, "RESET") == 0) {
            puts("Ready");
            mp.clear();
        }
        else if(strcmp(buf, "QUIT") == 0) {
            puts("Bye");
            break;
        }
        else {
            doit(buf);
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2750498 2008-02-13 22:43:06 Accepted 2905 C++ 00:00.02 904K ¤ï¤¿¤·

// 2012-09-07 01:46:15 | Accepted | 2905 | C++ | 0 | 192 | watashi | Source
