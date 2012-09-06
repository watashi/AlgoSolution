#include <cctype>
#include <cstdio>
#include <cstring>
/*
inline int CharToInt(const char ch)
{
    return ch - 'a';
}

inline char IntToChar(const int i)
{
    return 'a' + i;
}
*/
const char pstr[] = "the quick brown fox jumps over the lazy dog";

char code[128];

bool Try(const char str[])
{
    //static char tmp[26];
    if(strlen(str) != sizeof(pstr) - 1)
        return false;
    for (char i = 'a'; i <= 'z'; i++)
        code[i] = -1;
    for (size_t i = 0; i < sizeof(pstr) - 1; i++)
        if(pstr[i] == ' ') {
            if(str[i] != ' ')
                return false;
        }
        else if(islower(pstr[i])) {
            if(!islower(str[i]))
                return false;
            if(code[str[i]] != -1 && code[str[i]] != pstr[i])
                return false;
            else
                code[str[i]] = pstr[i];
        }
        else {
            return false;
        }

    return true;
}

char s[101][88];

int main(void)
{
    bool blank = false, decode;
    int n;

    //printf("length: %d %d\n", sizeof(pstr), strlen(pstr));
    while(gets(s[0]) != NULL) {
        n = 0;
        while(gets(s[++n]) != NULL && strcmp(s[n], ""));
        decode = false;
        for (int i = 0; i < n; i++)
            if(Try(s[i])) {
                decode = true;
                break;
            }
        if(blank)
            putchar('\n');
        else
            blank = true;
        if(!decode)
            puts("No solution.");
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; s[i][j] != '\0'; j++)
                    if(islower(s[i][j]))
                        s[i][j] = code[s[i][j]];
                puts(s[i]);
            }
        }
    }
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2841662   2008-04-13 15:42:09     Accepted    1838    C++     00:00.00    400K    Re:ReJudge

// 2012-09-07 01:02:28 | Accepted | 1838 | C++ | 0 | 188 | watashi | Source
