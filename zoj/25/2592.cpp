// O(nlogn) TLE

#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <cctype>
#include <cmath> // auto fix CE
#include <algorithm>
using namespace std;

int x[200002], y[200002];

inline int getnum()
{
    bool flag = false;
    char ch;
    int ret = 0;

    while((ch=getchar()) == ' ');
    if(ch == '-') {
        flag = true;
        ch = getchar();
    }
    do {
        ret *= 10;
        ret += ch - '0';
    }while(isdigit(ch=getchar()));
    if(flag) ret = -ret;

    return ret;
}

int main(void)
{
    int re, i, n, a, ans;

    scanf("%d", &re);
    while(re--) {
        scanf("%d ", &n);
        x[0] = 0;
        for (i = 1; i <= n; ++i) {
            x[i] = getnum();
            x[i] += x[i - 1];
        }
        y[n] = x[n];
        for (i = n - 1; i > 0; --i)
            y[i] = min(x[i], y[i + 1]);
        x[0] = x[1];
        ans = (y[1] > 0) ? 1 : 0;
        for (i = 1; i < n; ++i) {
            a = x[i];
            if(x[i - 1] < x[i]) x[i] = x[i - 1];
            if(y[i + 1] - a > 0 && x[i] + x[n] - a > 0) ++ans;
        }
        printf("%d\n", ans);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2795593 2008-03-21 21:38:16 Accepted 2592 C++ 00:00.46 2000K ¤ï¤¿¤·

// only 1 or -1
// the answer is the number of 1 minus the number of -1!

/*
//hhanger's code
#include <cmath> // auto fix CE
#include <cstdio>
#include <cmath> // auto fix CE
#include <cstring>

char str[600000];

int main()
{
    int ct;
    scanf("%d", &ct);
    while(ct--){
        int n;
        char s[2];
        scanf("%d", &n);
        gets(s);
        n *= 5;
        gets(str);
        n = n - 2 * strlen(str) - 2;
        if(n > 0)
            printf("%d\n", n);
        else
            printf("0\n");
    }
    return 0;
}
*/

// 2012-09-07 15:41:35 | Accepted | 2592 | C++ | 140 | 1744 | watashi | Source
