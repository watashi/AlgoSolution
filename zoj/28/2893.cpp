#include <cstring> // auto fix CE
#include <string>
#include <cstdio>
using namespace std;
string num[16];
int len[16];
int main()
{
    num[0] = "{}";
    len[0] = num[0].length();
    for (int i = 1; i < 16; i++) {
        num[i] = "{{}";
        for (int j = 1; j < i; j++)
            num[i] += "," + num[j];
        num[i] += "}";
        len[i] = num[i].length();
    }
    int re;
    scanf("%d ", &re);
    while(re--) {
        char str[100000];
        int a, l;
        gets(str);
        l = strlen(str);
        for (int i = 0; i < 16; i++)
            if(l == len[i]) {
                a = i;
                break;
            }
        gets(str);
        l = strlen(str);
        for (int i = 0; i < 16; i++)
            if(l == len[i]) {
                a += i;
                break;
            }
        puts(num[a].c_str());
    }
}
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2717875 2008-01-01 21:37:47 Accepted 2893 C++ 00:00.04 1352K わたし

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//54 2007-12-26 19:53:53 Accepted 1018 C++ 00:00:03 1356K わたし

// 2012-09-07 13:36:59 | Accepted | 2893 | C++ | 10 | 476 | watashi | Source
