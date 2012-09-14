/*

// O(2^(logn/log3))

#include <cstdio>

int k;

int gao(int n, int m, int b)
{
    if (b == 0) {
        return m;
    }

    int a = (n - 1) / b, ret = 0;

    switch (a) {
        case 2:
            ret += (n - 2 * b) % k * m % k;
            n = 2 * b;
        case 1:
            ret += gao(n - b, (m * 3 + 1) % k, b / 3);
            n = b;
        case 0:
            ret += gao(n, (m * 3) % k, b / 3);
            break;
    }

    return ret % k;
}

int main()
{
    int n, b;

    while (scanf("%d%d", &n, &k) != EOF) {
        b = 1;
        while (b <= n) {
            b *= 3;
        }
        b /= 3;
        printf("%d\n", gao(n + 1, 0, b));
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1697995   2008-11-11 21:38:34     Accepted    3061    C++     250     176     watashi@Zodiac

*/

// O(logn/log3)

#include <map>
#include <cstdio>

using namespace std;

int k;
map<int, pair<int, int> > mp;
// m * first + second;
// first = 6 * first + base / 3
// second = first + 2 * second

void gen(int n)
{
    mp.clear();
    mp[1] = make_pair(1, 0);
    for (int base = 3; base <= n; base *= 3) {
        mp[base] = make_pair((6 * mp[base / 3].first + base / 3) % k,
                (mp[base / 3].first + 2 * mp[base / 3].second) % k);
    }
}

int gao(int n, int m, int b)
{
    int a = n / b;
    int ret = 0;

    if (a >= 2) {
        ret += (n - 2 * b) % k * m % k;
        ret += ((m * 3 + 1) % k * mp[b].first + mp[b].second) % k;
        ret += ((m * 3) % k * mp[b].first + mp[b].second) % k;
    }
    else if (a == 1) {
        if (n > b) {
            ret += gao(n - b, (m * 3 + 1) % k, b / 3);
        }
        ret += ((m * 3) % k * mp[b].first + mp[b].second) % k;
    }
    else {
        ret += gao(n, m * 3 % k, b / 3);
    }

    return ret % k;
}

int main()
{
    int n, b;

    while (scanf("%d%d", &n, &k) != EOF) {
        b = 1;
        while (b <= n) {
            b *= 3;
        }
        b /= 3;
        gen(n);
        printf("%d\n", gao(n + 1, 0, b));
    }

    return 0;
}

//1698093   2008-11-11 22:57:43       Accepted      3061    C++     0   176     watashi@Zodiac
//1698092   2008-11-11 22:57:27     Accepted    3061    C++     0   176     watashi@Zodiac
//1698091   2008-11-11 22:56:12     Accepted    3061    C++     0   176     watashi@Zodiac

// 2012-09-07 01:59:23 | Accepted | 3061 | C++ | 0 | 180 | watashi | Source
