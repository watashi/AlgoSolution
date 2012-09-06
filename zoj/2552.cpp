#include <cstdio>

int w[101], l[101];

int main(void)
{
    bool blank = false;
    int n, m, k;
    int i, j;
    char x, y;

    while(scanf("%d%d", &n, &k) == 2 && n > 0) {
        m = k * n * (n - 1) / 2;
        for (k = 1; k <= n; k++)
            w[k] = l[k] = 0;
        while(m--) {
            scanf("%d %c%*s%d %c%*s", &i, &x, &j, &y);
            switch(x) {
                case 'r':
                    switch(y) {
                        case 'r':
                            break;
                        case 'p':
                            ++l[i];
                            ++w[j];
                            break;
                        case 's':
                            ++w[i];
                            ++l[j];
                            break;
                    }
                    break;
                case 'p':
                    switch(y) {
                        case 'r':
                            ++w[i];
                            ++l[j];
                            break;
                        case 'p':
                            break;
                        case 's':
                            ++l[i];
                            ++w[j];
                            break;
                    }
                    break;
                case 's':
                    switch(y) {
                        case 'r':
                            ++l[i];
                            ++w[j];
                            break;
                        case 'p':
                            ++w[i];
                            ++l[j];
                            break;
                        case 's':
                            break;
                    }
                    break;
            }
        }
        if(blank) putchar('\n');
        else blank = true;
        for (k = 1; k <= n; k++)
            if((l[k] += w[k]) == 0) puts("-");
            else printf("%.3lf\n", (double)w[k] / l[k]);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795922 2008-03-22 00:50:16 Accepted 2552 C++ 00:01.21 388K ¤ï¤¿¤·

// 2012-09-07 01:28:04 | Accepted | 2552 | C++ | 250 | 180 | watashi | Source
