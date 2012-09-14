#include <cstdio>

const int dLen[] = {
    0,
    9,
    2 * 90,
    3 * 900,
    4 * 9000,
    5 * 90000,
    6 * 900000
};

int Digit(int x, int i) // begin from right from 1
{
    while(--i) x /= 10;
    return x % 10;
}

int NN(int n) //begin with 0
{
    int len = 1, begin = 1;

    while(n >= dLen[len]) {
        n -= dLen[len];
        ++len;
        begin *= 10;
    }
    begin += n / len;
    n %= len;
    return Digit(begin, len - n);
}

int JJ(int n, bool even) // begin with 1
{
    if(n == 1) return 1;
    else if(even) return 2 * JJ((n + 1) / 2, false) - 1;
    else return 2 * JJ(n / 2, true);
}

int main(void)
{
    int x, y, t, c;

    while(scanf("%d", &x) != EOF) {
        y = 0;
        t = 9;
        c = 1;
        while (x > t) {
            y += t * c;
            x -= t;
            ++c;
            t *= 10;
        }
        y += x * c;
        printf("%d\n", NN(JJ(y, true) - 1));
    }
}

//2772351 2008-03-06 14:36:31 Accepted 2273 C++ 00:00.15 440K ¤ï¤¿¤·

// 2012-09-07 01:17:27 | Accepted | 2273 | C++ | 50 | 180 | watashi | Source
