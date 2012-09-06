#include <cstdio>
#include <algorithm>

using namespace std;

inline int toInt(char ch)
{
    switch (ch)
    {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
    /* NOREACHED */
}

inline char toChar(int i)
{
    static const char p[] = "ACGT";

    return p[i];
}

int main()
{
    int re;
    int n, m, s;
    char ch;
    int* p;
    static int a[1024][4];

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &n, &m);
        for (int j = 0; j < m; j++) {
            a[j][0] = a[j][1] = a[j][2] = a[j][3] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &ch);
                ++a[j][toInt(ch)];
            }
        }
        s = 0;
        for (int j = 0; j < m; j++) {
            p = max_element(a[j], a[j] + 4);
            putchar(toChar(p - a[j]));
            s += n - *p;
        }
        printf("\n%d\n", s);
    }
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750159   2009-01-28 14:53:00     Accepted    3132    C++     790     192     watashi@Zodiac

// 2012-09-07 02:02:39 | Accepted | 3132 | C++ | 690 | 196 | watashi | Source
