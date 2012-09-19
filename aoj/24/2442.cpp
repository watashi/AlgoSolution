#include <cstdio>

const int MAXN = 100;

int x[MAXN], y[MAXN];

int main() {
    int n;

    scanf("%d", &n);
    if (n % 2 != 0) {
        puts("NA");
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    x[n] = x[0] + x[n / 2];
    y[n] = y[0] + y[n / 2];
    for (int i = 1; i < n / 2; ++i) {
        if (x[i] + x[n / 2 + i] != x[n] || y[i] + y[n / 2 + i] != y[n]) {
            puts("NA");
            return 0;
        }
    }
    printf("%.5lf %.5lf\n", x[n] / 2.0, y[n] / 2.0);
    return 0;
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Submission Date
//#486597 	watashi 	C 	: Accepted 	C++ 	00:00 sec 	1064 KB 	Sun Sep 16 15:01:31

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#489325 	watashi 	2442 	: Accepted 	C++ 	00:00 sec 	1064 KB 	705 Bytes 	Wed Sep 19 15:25:09

