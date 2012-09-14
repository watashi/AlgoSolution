#include <cstdio>
using namespace std;

int a[1000][1000];

int main(void)
{
    int n, m;

    while(scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        int res = 0;
        for (int j = 0; j < m; j++)
            for (int i = n - 1; i >= 0; i--) {
                if(a[i][j] != 0) {
                    ++res;
                    for (int k = j + 1; k < m; k++)
                        if(k - j <= a[i][k]) {
                            --res;
                            break;
                        }
                    break;
                }
            }
        printf("%d\n", res);
    }
    return 0;
};

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2762254 2008-02-26 22:18:18 Accepted 2922 C++ 00:00.62 4296K ¤ï¤¿¤·

// 2012-09-07 01:47:35 | Accepted | 2922 | C++ | 180 | 4084 | watashi | Source
