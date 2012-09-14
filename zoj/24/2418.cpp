#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int n, mat[7][7], sum[7], pos[7], mod[20];

bool next_pos(int p[], int n)
{
    for (int i = n - 1; i >= 0; i--) {
        pos[i]++;
        if(pos[i] < n) return true;
        pos[i] = 0;
    }
    return false;
}

int main(void)
{
    while(scanf("%d", &n) != EOF && n != -1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        for (int i = 0; i < n; i++) {
            pos[i] = 0;
            mod[i] = mod[i + n] = i;
        }
        int ans = numeric_limits<int>::max();
        do {
            for (int i = 0; i < n; i++)
                sum[i] = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    sum[j] += mat[i][mod[pos[i] + j]];
            ans = min(ans, *max_element(sum, sum + n));
        }while(next_pos(pos, n) && pos[0] == 0);
        printf("%d\n", ans);
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746810 2008-02-08 23:09:38 Accepted 2418 C++ 00:00.51 436K ¤ï¤¿¤·

// 2012-09-07 01:22:46 | Accepted | 2418 | C++ | 190 | 180 | watashi | Source
