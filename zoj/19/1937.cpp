#include <cstdio>

int stop, step;
int a[10];
int c[128], b[128][10];

void dfs(int l)
{
    if (l == step) {
        if (a[l] == stop) {
            throw "";
        }
        else {
            return;
        }
    }
    else if (/*a[l] > stop || */(a[l] << (step - l)) < stop) {
        return;
    }
    else {
        for (int i = l; i >= 0; i--) {  // faster than ++
            for (int j = l; j >= i; j--) {
                a[l + 1] = a[i] + a[j];
                dfs(l + 1);
            }
        }
    }
}

void gao(int n)
{
    stop = n;
    step = 0;
    while ((1 << step) < stop) {
        ++step;
    }
    a[0] = 1;
    try {
        for (; ; ) {
            dfs(0);
            ++step;
        }
    }
    catch (...) {
        /*for (int i = 0; i <= step; i++) {
            printf("%d%c", a[i], (i == step) ? '\n' : ' ');
        }*/
        //printf("%d\n", step);
        c[n] = step;
        for (int i = 0; i <= step; i++) {
            b[n][i] = a[i];
        }
    }
}

int main(void)
{
    int n;

    for (int i = 1; i <= 100; i++) {
        c[i] = -1;
    }
    while (scanf("%d", &n) != EOF && n > 0) {
        if (c[n] == -1) {
            gao(n);
        }
        for (int i = 0; i <= c[n]; i++) {
            printf("%d%c", b[n][i], (i == c[n]) ? '\n' : ' ');
        }
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3025535 2008-08-06 21:59:23 Accepted 1937 C++ 00:00.11 444K Re:ReJudge
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3025546 2008-08-06 22:07:10 Accepted 1937 C++ 00:00.06 444K Re:ReJudge
//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3025550 2008-08-06 22:08:17 Accepted 1937 C++ 00:00.05 448K Re:ReJudge

// 2012-09-07 01:07:15 | Accepted | 1937 | C++ | 20 | 188 | watashi | Source
