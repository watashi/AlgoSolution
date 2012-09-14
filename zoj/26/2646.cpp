// O(sqrt(n));


#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    long long i, j, n, k, r, s;

    while (scanf("%lld%lld", &n, &k) != EOF) {
        s = (long long)sqrt((double)k);
        r = 0;
        i = 1;
        while (i < s && i <= n) {
            r += k % i;
            ++i;
        }
        while (i <= k && i <= n) {
            j = k / (k / i);
            if (j > n) {
                j = n;
            }
            r += k * (j - i + 1) - (k / i) * (i + j) * (j - i + 1) / 2;
            i = j + 1;
        }
        r += (n - i + 1) * k;
        printf("%lld\n", r);
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//3019853 2008-08-03 19:41:29 Accepted 2646 C++ 00:00.23 404K Re:ReJudge
//

// 2012-09-07 01:33:13 | Accepted | 2646 | C++ | 60 | 180 | watashi | Source
