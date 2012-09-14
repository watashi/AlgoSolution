#include <stdio.h>
#include <string.h>
char str[102][102];
int color[102][102];

void colorit(int i, int j, int k)
{
    if(color[i][j] == k) return;
    switch(str[i][j]){
    case '-':
        color[i][j] = k;
        if(color[i][j - 1] != k && (str[i][j - 1] == '-' || str[i][j - 1] == '+' || str[i][j - 1] == '*')) colorit(i, j - 1, k);
        if(color[i][j + 1] != k && (str[i][j + 1] == '-' || str[i][j + 1] == '+' || str[i][j + 1] == '*')) colorit(i, j + 1, k);
        break;
    case '|':
        color[i][j] = k;
        if(color[i - 1][j] != k && (str[i - 1][j] == '|' || str[i - 1][j] == '+' || str[i - 1][j] == '*')) colorit(i - 1, j, k);
        if(color[i + 1][j] != k && (str[i + 1][j] == '|' || str[i + 1][j] == '+' || str[i + 1][j] == '*')) colorit(i + 1, j, k);
        break;
    case '+':
        color[i][j] = k;
        if(color[i][j - 1] != k && (str[i][j - 1] == '-' || str[i][j - 1] == '+' || str[i][j - 1] == '*')) colorit(i, j - 1, k);
        if(color[i][j + 1] != k && (str[i][j + 1] == '-' || str[i][j + 1] == '+' || str[i][j + 1] == '*')) colorit(i, j + 1, k);
        if(color[i - 1][j] != k && (str[i - 1][j] == '|' || str[i - 1][j] == '+' || str[i - 1][j] == '*')) colorit(i - 1, j, k);
        if(color[i + 1][j] != k && (str[i + 1][j] == '|' || str[i + 1][j] == '+' || str[i + 1][j] == '*')) colorit(i + 1, j, k);
        break;
    case '/':
        color[i][j] = k;
        if(color[i - 1][j + 1] != k && (str[i - 1][j + 1] == '/' || str[i - 1][j + 1] == 'X' || str[i - 1][j + 1] == '*')) colorit(i - 1, j + 1, k);
        if(color[i + 1][j - 1] != k && (str[i + 1][j - 1] == '/' || str[i + 1][j - 1] == 'X' || str[i + 1][j - 1] == '*')) colorit(i + 1, j - 1, k);
        break;
    case '\\':
        color[i][j] = k;
        if(color[i - 1][j - 1] != k && (str[i - 1][j - 1] == '\\' || str[i - 1][j - 1] == 'X' || str[i - 1][j - 1] == '*')) colorit(i - 1, j - 1, k);
        if(color[i + 1][j + 1] != k && (str[i + 1][j + 1] == '\\' || str[i + 1][j + 1] == 'X' || str[i + 1][j + 1] == '*')) colorit(i + 1, j + 1, k);
        break;
    case 'X':
        color[i][j] = k;
        if(color[i - 1][j + 1] != k && (str[i - 1][j + 1] == '/' || str[i - 1][j + 1] == 'X' || str[i - 1][j + 1] == '*')) colorit(i - 1, j + 1, k);
        if(color[i + 1][j - 1] != k && (str[i + 1][j - 1] == '/' || str[i + 1][j - 1] == 'X' || str[i + 1][j - 1] == '*')) colorit(i + 1, j - 1, k);
        if(color[i - 1][j - 1] != k && (str[i - 1][j - 1] == '\\' || str[i - 1][j - 1] == 'X' || str[i - 1][j - 1] == '*')) colorit(i - 1, j - 1, k);
        if(color[i + 1][j + 1] != k && (str[i + 1][j + 1] == '\\' || str[i + 1][j + 1] == 'X' || str[i + 1][j + 1] == '*')) colorit(i + 1, j + 1, k);
        break;
    case '*':
        color[i][j] = k;
        if(color[i][j - 1] != k && (str[i][j - 1] == '-' || str[i][j - 1] == '+' || str[i][j - 1] == '*')) colorit(i, j - 1, k);
        if(color[i][j + 1] != k && (str[i][j + 1] == '-' || str[i][j + 1] == '+' || str[i][j + 1] == '*')) colorit(i, j + 1, k);
        if(color[i - 1][j] != k && (str[i - 1][j] == '|' || str[i - 1][j] == '+' || str[i - 1][j] == '*')) colorit(i - 1, j, k);
        if(color[i + 1][j] != k && (str[i + 1][j] == '|' || str[i + 1][j] == '+' || str[i + 1][j] == '*')) colorit(i + 1, j, k);
        if(color[i - 1][j + 1] != k && (str[i - 1][j + 1] == '/' || str[i - 1][j + 1] == 'X' || str[i - 1][j + 1] == '*')) colorit(i - 1, j + 1, k);
        if(color[i + 1][j - 1] != k && (str[i + 1][j - 1] == '/' || str[i + 1][j - 1] == 'X' || str[i + 1][j - 1] == '*')) colorit(i + 1, j - 1, k);
        if(color[i - 1][j - 1] != k && (str[i - 1][j - 1] == '\\' || str[i - 1][j - 1] == 'X' || str[i - 1][j - 1] == '*')) colorit(i - 1, j - 1, k);
        if(color[i + 1][j + 1] != k && (str[i + 1][j + 1] == '\\' || str[i + 1][j + 1] == 'X' || str[i + 1][j + 1] == '*')) colorit(i + 1, j + 1, k);
        break;
    default:
        break;
    }
}

int main()
{
    int i, j, k, n, m;

    while(scanf("%d%d", &n, &m) != EOF) {
        getchar();
        memset(str, 0, sizeof(str));
        memset(color, 0, sizeof(color));
        for (i = 1; i <= n; i++)
            gets(str[i] + 1);
        scanf("%d", &m);
        while(m--) {
            scanf("%d%d%d", &i, &j, &k);
            colorit(i + 1, j + 1, k);
        }
        for (i = 1; i <= n; i++) {
            j = 1;
            while(str[i][j]) {
                if(color[i][j] == 0) putchar(str[i][j++]);
                else{
                    k = j + 1;
                    while(color[i][k] == color[i][j]) k++;
                    printf("[m%d", color[i][j]);
                    do{
                        putchar(str[i][j++]);
                    }while(j < k);
                    printf("m]");
                }
            }
            putchar('\n');
        }
    }

    return 0;   /* NZEC */
}

/* //Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name */
/* //2722604 2008-01-10 14:28:52 Accepted 2572 C 00:00.04 648K ¤ï¤¿¤· */

// 2012-09-07 03:11:47 | Accepted | 2572 | C | 0 | 208 | watashi | Source
