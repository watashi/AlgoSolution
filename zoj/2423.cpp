#include <cstdio>

bool show(int x, int y, int n)
{
    bool ret = true;
    int m;

    while(n > 1) {
        n /= 3;
        m = n << 1;
        if(x < n) {
            if(y < n) ret = false;
            else if(y < m) {
                putchar(' ');
                return false;
            }
            else y -= m;
        }
        else if(x < m) {
            if(y < n) {
                putchar(' ');
                return false;
            }
            else if(y < m) {
                x -= n;
                y -= n;
            }
            else {
                putchar(' ');
                return false;
            }
        }
        else {
            if(y < n) {
                x -= m;
                ret = false;
            }
            else if(y < m) {
                putchar(' ');
                return false;
            }
            else {
                x -= m;
                y -= m;
            }
        }
    }
    putchar('X');
    return ret;
}

int main(void)
{
    int n, m;

    while(scanf("%d", &n) != EOF && n > 0) {
        m = 1;
        while(--n) m *= 3;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                if(show(i, j, m)) {
                    putchar('\n');
                    break;
                }
        }
        puts("-");
    }
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795932 2008-03-22 01:27:23 Accepted 2423 C++ 00:00.05 392K ¤ï¤¿¤·

// 2012-09-07 01:23:04 | Accepted | 2423 | C++ | 20 | 180 | watashi | Source
