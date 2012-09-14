#include <cstdio>

char str[66];
int bit[66];

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int k;
        long long n;
        scanf("%d%s%lld", &k, str, &n);
        if(n < 0) {
            n = -n;
            for (int i = 0; str[i]; i++)
                str[i] = (str[i] == 'p') ? 'n' : 'p';
        }
        for (int i = 0, j = k - 1; i < j; i++, j--)
            if(str[i] == str[j]) continue;
            else {
                str[i] = str[j];
                str[j] = (str[j] == 'p') ? 'n' : 'p';
            }
        for (int i = 0; i < 66; i++){
            bit[i] = n & 1;
            n >>= 1;
        }
        for (int i = 0; i < k; i++) {
            switch(bit[i]) {
            case 0:
                break;
            case 1:
                if(str[i] == 'n') ++bit[i + 1];
                break;
            case 2:
                bit[i] = 0;
                ++bit[i + 1];
                break;
            }
        }
        for (int i = k; i < 66; i++)
            if(bit[i] != 0) n = -1;
        if(n != 0) puts("Impossible");
        else {
            for (int i = k - 1; i >= 0; i--)
                putchar('0' + bit[i]);
            putchar('\n');
        }
    }
    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2746252 2008-02-07 22:19:28 Accepted 1408 C++ 00:00.00 392K ¤ï¤¿¤·

// 2012-09-07 00:48:44 | Accepted | 1408 | C++ | 0 | 180 | watashi | Source
