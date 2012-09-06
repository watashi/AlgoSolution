#include <cstdio>

const int bin[7] = {1, 2, 4, 8, 16, 32, 64};
const int digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
const int pos[7][2] = {{0, 1}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {1, 0}, {1, 1}};
const int off[9] = {0, 3, 6, 9, 12, 15, 18, 21, 24};

void trans(char buf[3][33], int ini[9])
{
    for (int i = 0; i < 9; i++) {
        ini[i] = 0;
        for (int j = 0; j < 7; j++)
            if(buf[pos[j][0]][off[i] + pos[j][1]] != '.')
                ini[i] |= bin[j];
    }
}

bool isok(int src, int tar)
{
    return src != tar /*so won't cnted twice */ && (src | tar) == tar;
}

char buf[3][33];
int ini[9], tmp[9], ans[9], cnt, ind, sum;

int main(void)
{
/*  for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                buf[j][k] = '.';
        for (int j = 0; j < 7; j++) {
            if(digit[i] & bin[j])
                buf[pos[j][0]][pos[j][1]] = 'x';
        }
        for (int j = 0; j < 3; j++)
            puts(buf[j]);
    }
*/  while(scanf("%s", buf[0]) != EOF) {
        scanf("%s%s", buf[1], buf[2]);
        trans(buf, ini);
        ind = -1;
        sum = 0;
        for (int i = 0; i < 9; i++) {
            tmp[i] = -1;
            for (int j = 0; j < 10; j++)
                if(ini[i] == digit[j])
                    tmp[i] = j;
            if(tmp[i] == -1) {
                if(ind == -1)
                    ind = i;
                else
                    ind = -2;
            }
            else {
                sum += (9 - i) * tmp[i];
            }
        }
        if(ind == -2) {
            printf("failure\n");
        }
        else if(ind == -1) {
            if(sum % 11 == 0) {
                cnt = 1;
                for (int i = 0; i < 9; i++)
                    ans[i] = tmp[i];
            }
            else {
                cnt = 0;
            }
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 10; j++)
                    if((sum + (9 - i) * (j - tmp[i])) % 11 == 0 && isok(ini[i], digit[j])) {
                        ++cnt;
                        for (int k = 0; k < 9; k++)
                            ans[k] = tmp[k];
                        ans[i] = j;
                    }
            if(cnt == 0) {
                printf("failure\n");
            }
            else if(cnt == 1) {
                for (int i = 0; i < 9; i++)
                    putchar('0' + ans[i]);
                putchar('\n');
            }
            else {
                printf("ambiguous\n");
            }
        }
        else {
            cnt = 0;
//          printf("%d:%d\n", ind, sum);
            for (int j = 0; j < 10; j++)
                if((sum + (9 - ind) * j) % 11 == 0 && isok(ini[ind], digit[j])) {
                    ++cnt;
                    for (int k = 0; k < 9; k++)
                        ans[k] = tmp[k];
                    ans[ind] = j;
                }
            if(cnt == 0) {
                printf("failure\n");
            }
            else if(cnt == 1) {
                for (int i = 0; i < 9; i++)
                    putchar('0' + ans[i]);
                putchar('\n');
            }
            else {
                printf("ambiguous\n");
            }
        }
    }

    return 0;
}
//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//2917714   2008-05-16 11:06:52     Accepted    2958    C++     00:00.00    388K    Re:ReJudge

// 2012-09-07 01:50:18 | Accepted | 2958 | C++ | 0 | 180 | watashi | Source
