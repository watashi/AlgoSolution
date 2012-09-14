/*

*/


#include <cctype>
#include <cstdio>
#include <algorithm>
using namespace std;

char board[108][108] = {'\0'};
double dp[108][108] = {0.0};

int main(void)
{
    int t, h, w;

    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &h, &w);
        for (int i = 1; i <= h; i++)
            scanf("%s", board[i] + 1);
        fill(dp[h + 1] + 1, dp[h + 1] + w + 1, 0.0);
        for (int i = h; i > 0; i--) {
            for (int j = 1; j <= w; j++) {
                if(board[i][j] == '.') dp[i][j] = dp[i + 1][j];
                else if(isdigit(board[i][j])) dp[i][j] = board[i][j] - '0';
            }
            for (int j = 1; j <= w; j++)
                if(board[i][j] == '*') dp[i][j] = (dp[i][j - 1] + dp[i][j + 1]) / 2; //none ara located in the leftmost or rightmost column.
        }
        printf("%.6lf\n", *max_element(dp[1] + 1, dp[1] + w + 1));
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2756988 2008-02-21 18:24:49 Accepted 2918 C++ 00:00.00 544K ¤ï¤¿¤·

// 2012-09-07 01:47:17 | Accepted | 2918 | C++ | 0 | 284 | watashi | Source
