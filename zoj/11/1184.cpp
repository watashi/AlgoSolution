#include <cstdio>

inline int Chr2Int(char ch)
{
    return ch - 'A';
}

inline char Int2Chr(int i)
{
    return 'A' + i;
}

const int light = 0, heavy = 2;
int w[12];
char test[3][3][10];

char flag(int x)
{
    if (x == 0)
        return 'e';
    else if (x > 0)
        return 'u';
    else
        return 'd';
}

bool judge()
{
    for (int i = 0; i < 3; i++) {
        int s = 0;
        for (int j = 0; test[i][0][j] != '\0'; j++) {
            s += w[Chr2Int(test[i][0][j])];
        }
        for (int j = 0; test[i][1][j] != '\0'; j++) {
            s -= w[Chr2Int(test[i][1][j])];
        }
        if (flag(s) != test[i][2][0]) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int re;

    scanf("%d", &re);
    while (re--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%s", test[i][j]);
            }
        }

        for (int i = 0; i < 12; i++) {
            w[i] = 1;
        }
        for (int i = 0; i < 12; i++) {
            w[i] = light;
            if (judge()) {
                printf("%c is the counterfeit coin and it is light.\n", Int2Chr(i));
                break;
            }
            w[i] = heavy;
            if (judge()) {
                printf("%c is the counterfeit coin and it is heavy.\n", Int2Chr(i));
                break;
            }
            w[i] = 1;
        }
    }
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2958026   2008-06-28 20:24:47     Accepted    1184    C++     00:00.00    392K    Re:ReJudge

// 2012-09-07 00:40:31 | Accepted | 1184 | C++ | 0 | 180 | watashi | Source
