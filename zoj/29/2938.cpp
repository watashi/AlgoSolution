//solution for rock by whatashya@ZJU
#include <stdio.h>
#include <string.h>
char buf[64];
int main()
{
    int i, d, c, p, l;
    int cnt, len, ini, dis;

    while(gets(buf) && strcmp(buf, "END")) {
        l = strlen(buf);
        len = l - 1;
        cnt = (buf[len] == '.');
        ini = len;
        dis = 1;
        for (i = 0; i < l; i++)
            for (d = 1; i + d < l; d++) {
                c = 0;
                p = i;
                while(buf[p] == '.') {
                    c++;
                    if(p + d >= l) break;
                    else p += d;
                }
                if(c > cnt) {
                    cnt = c;
                    len = p;
                    ini = i;
                    dis = d;
                }
                else if(c == cnt) {
                    if(p > len) {
                        len = p;
                        ini = i;
                        dis = d;
                    }
                    else if(p == len) {
                        if(i > ini) {
                            ini = i;
                            dis = d;
                        }
                        else if(i == ini && d < dis) {
                            dis = d;
                        }
                    }
                }
            }
        printf("%d %d\n", ini, dis);
    }
    return 0;
}
/*
real    0m0.485s
user    0m0.030s
sys     0m0.249s
*/

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2768722 2008-03-03 16:44:15 Accepted 2938 C++ 00:00.01 384K ¤ï¤¿¤·

// 2012-09-07 01:48:54 | Accepted | 2938 | C++ | 0 | 180 | watashi | Source
