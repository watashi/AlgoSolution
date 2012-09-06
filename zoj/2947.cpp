#include <cstdio>
#include <cstring>
int main(void)
{
    int re, cl[2];
    char ch[2][20];

    scanf("%d", &re);
    while(re--) {
        for (int i = 0; i < 2; i++) {
            scanf("%d", &cl[i]);
            for (int j = 0; j < cl[i]; j++)
                scanf("%s", ch[i] + j);
        }
        puts((cl[0] != cl[1] || strncmp(ch[0], ch[1], cl[0])) ? "DIFFERENT" : "SAME");
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2813261 2008-03-31 13:03:25 Accepted 2947 C++ 00:00.00 388K ¤ï¤¿¤·

// 2012-09-07 01:49:19 | Accepted | 2947 | C++ | 0 | 180 | watashi | Source
