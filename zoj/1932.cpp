#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

char buf[81], *ptr;
double s[5], ss;
double c[5], cc;
double p[5], pp;
double x[5] = {9, 4, 4, 4, 7};

int main(void)
{
    while(gets(buf) != NULL && buf[0] != '-') {
        for (int i = 0; i < 5; i++)
            s[i] = 0;
        do {
            cc = pp = 0;
            ptr = buf;
            for (int i = 0; i < 5; i++) {
                c[i] = atoi(ptr);
                p[i] = -1;
                while(isdigit(*++ptr));
                switch(*ptr) {
                    case 'g': cc += c[i] *= x[i]; break;
                    case 'C': cc += c[i]; break;
                    case '%': pp += p[i] = c[i]; break;
                }
                while(isspace(*++ptr));
            }
            pp = 100 - pp;
            for (int i = 0; i < 5; i++) {
                if(p[i] >= 0) c[i] = cc * p[i] / pp;
                s[i] += c[i];
            }
            gets(buf);
        }while(buf[0] != '-');
        ss = 0;
        for (int i = 0; i < 5; i++)\
            ss += s[i];
        printf("%.0lf%%\n", 100 * s[0] / ss);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2771656 2008-03-05 21:05:26 Accepted 1932 C++ 00:00.01 396K ¤ï¤¿¤·

// 2012-09-07 01:07:09 | Accepted | 1932 | C++ | 0 | 180 | watashi | Source
