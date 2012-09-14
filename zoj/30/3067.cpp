#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    static int k[1024], s;

    while (scanf("%d", &n) != EOF && n > 0) {
        s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &k[i]);
            s ^= k[i];
        }
        m = 0;
        for (int i = 0; i < n; i++) {
            m += ((k[i] ^ s) < k[i]);
        }
        printf("%d\n", m);
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750210   2009-01-28 15:37:10     Accepted    3066    C++     10  176     watashi@Zodiac

// 2012-09-07 01:59:41 | Accepted | 3067 | C++ | 20 | 184 | watashi | Source
