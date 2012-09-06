#include <cctype>
#include <cstdio>

int todigit(char ch)
{
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

int main()
{
    int re;
    int base, num;
    char *p;
    bool f;
    static char buf[65536];

    scanf("%d", &re);
    while (getchar() != '\n');
    while (re--) {
        gets(buf);
        p = buf;
        f = true;
        if (!isdigit(*p)) {
            f = false;
            goto GOTO;
        }
        base = 0;
        while (isdigit(*p)) {
            base *= 10;
            base += todigit(*p);
            if (base > 100) {
                base = 100;
            }
            ++p;
        }
        while (*p == '#') {
            if (!(2 <= base && base <= 16)) {
                f = false;
                break;
            }
            ++p;
            num = 0;
            if (!isxdigit(*p) || isupper(*p)) {
                f = false;
                goto GOTO;
            }
            while (isxdigit(*p) && !isupper(*p)) {
                if (todigit(*p) >= base) {
                    f = false;
                    goto GOTO;
                }
                num *= base;
                num += todigit(*p);
                if (num > 100) {
                    num = 100;
                }
                ++p;
            }
            if (*p != '#') {
                f = false;
                goto GOTO;
            }
            ++p;
            base = num;
        }
        if (*p != '\0') {
            f = false;
            goto GOTO;
        }
GOTO:
        puts(f ? "yes" : "no");
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1647990   2008-09-19 22:51:39     Accepted    1920    C++     0   324     watashi
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1647993   2008-09-19 22:52:26     Accepted    1920    C++     0   256     watashi

// 2012-09-07 01:06:26 | Accepted | 1920 | C++ | 0 | 244 | watashi | Source
