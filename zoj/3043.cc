#include <cstdio> // auto fix CE
#include <stdio.h>
#include <cstdio> // auto fix CE
#include <string.h>

const char* psuit[] = {"Heart", "Spade", "Diamond", "Club"};

int getsuit(const char buf[])
{
    int i;

    for (i = 0; i < 4 && strcmp(buf, psuit[i]); i++);

    return i;
}

int getvalue(const char buf[])
{
    switch(buf[0]) {
        case '1': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default: return buf[0] - '0';
    }
}

int suit[4], value[4], pts[4];
int pig, sheep, change, red[15];

int judge(int begin)
{
    int i, k, v;

    k = 0;
    v = value[k];
    for (i = 1; i < 4; i++) {
        if (suit[i] == suit[0] && value[i] > v) {
            k = i;
            v = value[i]; // 555 -_-b WA+1
        }
    }
    begin = (begin + k) % 4;
    for (i = 0; i < 4; i++) {
        if (suit[i] == 0) {
            red[value[i]] = begin;
        }
        else if (suit[i] == 1 && value[i] == 12) {
            pig = begin;
        }
        else if (suit[i] == 2 && value[i] == 11) {
            sheep = begin;
        }
        else if (suit[i] == 3 && value[i] == 10) {
            change = begin;
        }
    }

    return begin;
}

void calc()
{
    int i;

    for (i = 0; i < 4; i++) {
        pts[i] = 0;
    }
    for (i = 2; i <= 14 && red[i] != -1 && red[i] == red[2]; ++i);
    if (i == 15) {
        if (pig == red[2] && sheep == red[2] && change == red[2]) {
            pts[red[2]] = 800;
            pig = sheep = change = -1;
        }
        else {
            pts[red[2]] = 200;
        }
    }
    else {
        for (i = 5; i <= 14; i++) {
            if (red[i] != -1) {
                pts[red[i]] += -10 * ((i < 10) ? 1 : (i - 9));
            }
        }
    }
    if (pig != -1) pts[pig] += -100;
    if (sheep != -1) pts[sheep] += 100;
    //if (change != -1) pts[change] = (pts[change] == 0) ? 50 : (2 * pts[change]);
    if (change != -1) {
        if (pts[change] == 0 && red[2] != change && red[3] != change && red[4] != change && /**/sheep != change/**/) { // 去掉也能AC，数据需加强
            pts[change] += 50;
        }
        else {
            pts[change] *= 2;
        }
    }
    /*WA+1*/
}

int main(int argc, char* argv[])
{
    static char player[5][128], buf[16], buff[4];
    int re, r, i, begin;

    scanf("%d", &re);
    while (re--) {
        for (i = 0; i < 4; i++) {
            scanf("%s", player[i]);
        }
        scanf("%s", player[4]);

        for (begin = 0; begin < 4 && strcmp(player[4], player[begin]); ++begin);
        pig = sheep = change = -1;
        for (i = 2; i <= 14; i++) {
            red[i] = -1;
        }

        scanf("%d", &r);
        while (r--) {
            for (i = 0; i < 4; i++) {
                scanf("%s%s", buf, buff);
                suit[i] = getsuit(buf);
                value[i] = getvalue(buff);
            }
            begin = judge(begin);
        }
        calc();

        for (i = 0; i < 4; i++) {
            printf("%s %d\n", player[i], pts[i]);
        }
        if (re) {
            printf("\n");
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1644798   2008-09-15 15:57:30     Accepted    3043    C++     0   256     watashi

// 2012-09-07 14:11:41 | Accepted | 3043 | C++ | 0 | 180 | watashi | Source
