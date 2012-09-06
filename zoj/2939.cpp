#include <map>
#include <cstdio>
#include <string>
using namespace std;

const char* one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const char* ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char* hun[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const char* tho[] = {"", "M", "MM", "MMM", "MMMM"};

map <string, int> Roman;

void ini_gen(void)
{
    string x, y, z;
    int num = 0;

    for (int i = 0; i < 5; i++) {
        x = tho[i];
        for (int j = 0; j < 10; j++) {
            y = x + hun[j];
            for (int k = 0; k < 10; k++) {
                z = y + ten[k];
                for (int l = 0; l < 10; l++)
                    Roman.insert(make_pair(z + one[l], num++));
            }
        }
    }
}

void showRoman(int x)
{
    printf("%s", tho[x / 1000]);
    printf("%s", hun[x % 1000 / 100]);
    printf("%s", ten[x % 100 / 10]);
    printf("%s", one[x % 10]);
}

char buf[80];

int main(void)
{
    int ri = 0, n, s;

    ini_gen();
    while(scanf("%d", &n) != EOF && n > 0) {
        s = 0;
        while (n--) {
            scanf("%s", buf);
            s += Roman[buf];
        }
        printf("Case ");
        showRoman(++ri);
        printf(": ");
        showRoman(s);
        printf("\n");
    }

    return 0;
}

//Run ID Submit time Judge Status Problem ID Language Run time Run memory User Name
//2777601 2008-03-10 19:09:47 Accepted 2939 C++ 00:00.03 1084K ¤ï¤¿¤·

// 2012-09-07 01:49:00 | Accepted | 2939 | C++ | 0 | 444 | watashi | Source
