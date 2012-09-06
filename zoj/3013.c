#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* p[26];
    int f;
}Node;

void tire_init(Node *p)
{
    int i;

    for (i = 0; i < 26; i++) {
        p->p[i] = NULL;
    }
    p->f = 0;
}

void tire_add(Node *p, const char *s)
{
    while (*s != EOF) {
        if (p->p[*s] == NULL) {
            p->p[*s] = (Node *)malloc(sizeof(Node));
            tire_init(p->p[*s]);
        }
        p = p->p[*s];
        ++s;
    }
    p->f = 1;
}

void tire_clear(Node *p)
{
    int i;

    for (i = 0; i < 26; i++) {
        if (p->p[i] != NULL) {
            tire_clear(p->p[i]);
            free(p->p[i]);
        }
    }
}

int convert(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        str[i] -= 'a';
    }
    str[i] = EOF;

    return i;
}

int main(void)
{
    int i, j, l, m, n;
    Node root, *p;
    static char buf[5120];
    static int pre[5120], dp[5120];

    tire_init(&root);
    while (scanf("%d%d", &m, &n) != EOF) {
        tire_clear(&root);
        tire_init(&root);
        for (i = 0; i < m; i++) {
            scanf("%s", buf);
            convert(buf);
            tire_add(&root, buf);
        }
        while (n--) {
            scanf("%s", buf);
            l = convert(buf);
            for (i = 0; i <= l; i++) {
                dp[i] = i;
                pre[i] = i - 1;
            }
            for (i = 0; i < l; i++) {
                p = root.p[buf[i]];
                j = i + 1;
                while (p != NULL) {
                    if (p->f) {
                        if (dp[j] > dp[i]) {
                            dp[j] = dp[i];
                            pre[j] = i;
                        }
                    }
                    if (j == l) {
                        break;
                    }
                    p = p->p[buf[j]];
                    ++j;
                }
                if (dp[i + 1] > dp[i] + 1) {
                    dp[i + 1] = dp[i] + 1;
                    pre[i + 1] = i;
                }
            }

            i = pre[l];
            while (i != 0) {
                j = i;
                i = pre[i];
                pre[j] = -2;
            }
            printf("%d\n", dp[l]);
            for (i = 0; i < l; i++) {
                if (pre[i] == -2) {
                    putchar('#');
                }
                putchar('a' + buf[i]);
            }
            putchar('\n');
        }
    }
    tire_clear(&root);

    return 0;
}

/* //Run ID     Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name */
/* //3009332    2008-07-27 20:25:17     Accepted    3013    C   00:00.16    568K    Re:ReJudge */

/*
Rank    Submit time     Run time    Run memory      Language    User
1   2008-07-26 18:35:52     00:00.15    4424K   C++     Percy
2   2008-07-27 20:25:17     00:00.16    568K    C   Re:ReJudge
3   2008-07-26 21:53:06     00:00.33    5700K   C++     a332371235
4   2008-07-27 10:45:50     00:00.42    836K    C++     11
5   2008-07-26 19:09:04     00:00.43    14740K  C++     dreamzk
6   2008-07-26 17:47:30     00:00.48    2420K   C++     WWDDCC
7   2008-07-26 21:45:30     00:00.56    5524K   C++     Arsalan
8   2008-07-26 18:55:26     00:00.59    23404K  C++     xming
9   2008-07-27 10:04:15     00:00.61    1984K   C++     wer2
10  2008-07-27 04:35:12     00:00.66    992K    C++     sms
11  2008-07-27 00:45:08     00:00.89    5932K   C++     Cossack
12  2008-07-26 19:30:32     00:01.04    11524K  C++     ´ôÖÍµÄÂý°å
13  2008-07-26 18:23:00     00:01.04    22072K  C++     Rainco_test
14  2008-07-26 22:04:12     00:01.05    11528K  C++     ying
15  2008-07-26 18:23:41     00:01.06    11528K  C++     Rainco@shnu
16  2008-07-26 20:17:04     00:01.83    5168K   C++     tiblef
17  2008-07-26 18:26:52     00:01.87    2188K   C++     TJU_HanoiTower
18  2008-07-26 19:00:06     00:01.94    1200K   C++     prayer
19  2008-07-27 09:33:49     00:03.56    2168K   C++     qbx123
20  2008-07-26 21:49:29     00:03.64    2032K   C++     |Dragon|ìáºê
*/

// 2012-09-07 01:54:59 | Accepted | 3013 | C | 60 | 4428 | watashi | Source
