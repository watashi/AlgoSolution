#include <cstdio>
#include <cstring>

inline int ChrToInt(const char ch)
{
    return ch - '0';
}

inline char IntToChr(const int i)
{
    return '0' + i;
}

bool isodd(char *p, const int l)
{
    return (p[l - 1] & 1) != 0;
}

char* div2(char *p, const int l)
{
    for (int i = 0; i < l; i++) {
        if(p[i] & 1)
            p[i + 1] += 10;
        p[i] >>= 1;
    }
    p[l] = 0;
    while(*p == 0)
        ++p;

    return p;
}

char* dec1(char *p, const int l)
{
    int i = l - 1;

    while(p[i] == 0)
        p[i--] = 9;
    --p[i];
    while(*p == 0)
        ++p;

    return p;
}

char buf[2002];

int main(void)
{
    int re, len;
    char *p;

    scanf("%d ", &re);
    while(re--) {
        gets(buf);
        scanf("\n");
        len = strlen(buf);
        for (int i = 0; i < len; i++)
            buf[i] = ChrToInt(buf[i]);
        if(isodd(buf, len)) {
            p = div2(buf, len);
        }
        else {
            p = div2(buf, len);
            p = dec1(buf, len);
            if(!isodd(buf, len))
                p = dec1(buf, len);
        }
        for (int i = 0; i < len; i++)
            buf[i] = IntToChr(buf[i]);
        puts(p);
        if(re)
            putchar('\n');
    }
}
//2868299   2008-04-25 13:26:41     Accepted    2313    C++     00:00.01    392K    Re:ReJudge

// 2012-09-07 15:37:18 | Accepted | 2313 | C++ | 0 | 180 | watashi | Source
