#include <cstdio>

int ToInt(const char str[])
{
    int i = 0, pre = 1, ret = 0;

    while(str[i]) {
        switch(str[i]) {
            case 'm':
                ret += pre * 1000;
                pre = 1;
                break;
            case 'c':
                ret += pre * 100;
                pre = 1;
                break;
            case 'x':
                ret += pre * 10;
                pre = 1;
                break;
            case 'i':
                ret += pre;
                pre = 1;
                break;
            default:
                pre = str[i] - '0';
                break;
        }
        ++i;
    }

    return ret;
}

char* ToStr(int num)
{
    static char str[80];
    static int m, c, x, i, k;


    i = num % 10;
    num /= 10;
    x = num % 10;
    num /= 10;
    c = num % 10;
    m = num / 10;

    k = 0;
    if(m > 1) str[k++] = '0' + m;
    if(m > 0) str[k++] = 'm';
    if(c > 1) str[k++] = '0' + c;
    if(c > 0) str[k++] = 'c';
    if(x > 1) str[k++] = '0' + x;
    if(x > 0) str[k++] = 'x';
    if(i > 1) str[k++] = '0' + i;
    if(i > 0) str[k++] = 'i';
    str[k] = '\0';

    return str;
}

char a[80], b[80];

int main(void)
{
    int re;

    scanf("%d", &re);
    while(re--) {
        scanf("%s%s", a, b);
        printf("%s\n", ToStr(ToInt(a) + ToInt(b)));
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2841814   2008-04-13 16:35:34     Accepted    2791    C++     00:00.00    392K    Re:ReJudge

// 2012-09-07 01:40:09 | Accepted | 2791 | C++ | 0 | 180 | watashi | Source
