// 可以证明如果存在长度必在10^4*10以内，否则类似于求模，将循环

#include <cstdio>
int dp[9][111111];
char buf[1024];
int main(void)
{
    int re;
    scanf("%d ", &re);
    while(re--) {
        while(gets(buf) != NULL && buf[0] != '\0') {
            int k;
            sscanf(buf, "%d", &k);
            for (int i = 0; i < 9; i++)
                dp[i][0] = i + 1;
            int l = 0;
            while(true) {
                for (int i = 0; i < 9; i++) {
                    dp[i][l + 1] = dp[i][l] / 10;
                    dp[i][l] %= 10;
                    dp[i][l + 1] += k * dp[i][l];
                    if(dp[i][l + 1] == i + 1) {
                        putchar('1' + i);
                        while(l > 0) putchar('0' + dp[i][l--]);
                        putchar('\n');
                        l = -1;
                        break;
                    }
                }
                if(l < 0) break;
                ++l;
            }
        }
        if(re) putchar('\n');
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746091 2008-02-07 18:06:03 Accepted 1177 C++ 00:00.01 4300K わたし

// 2012-09-07 00:40:12 | Accepted | 1177 | C++ | 0 | 4088 | watashi | Source
