#include <cctype>
#include <cstdio>
#include <cstring>

bool begin;
int length;

bool gao()
{
    static int len;
    static char ch, buf[1024], buff[1024];

    scanf(" ");
    if (scanf("%[#]", buff) == 1) {
        return false;
    }

    if (scanf("%[A-Za-z]", buf) != 1) {
        throw -1;
    }
    ch = getchar();
    if (ch == '-') {
        scanf(" %[A-Za-z]", buff);
        strcat(buf, buff);
        ch = ' ';
    }
    if (begin) {
        buf[0] = toupper(buf[0]);
        begin = false;
    }
    if (isspace(ch) && scanf(" %1[,.?!]", buff) == 1) {
        ch = buff[0];
    }
    if (!isspace(ch)) {
        if (ch != ',') {
            begin = true;
        }
        buff[0] = ch;
        buff[1] = '\0';
        strcat(buf, buff);
    }
    len = strlen(buf);
    if (length + len + (length != 0) <= 80) {
        if (length != 0) {
            putchar(' ');
        }
        printf("%s", buf);
        length = length + len + (length != 0);
    }
    else {
        printf("\n%s", buf);
        length = len;
    }

    return true;
}

int main(void)
{
    int re;

    scanf("%d", &re);
    while (re--) {
        begin = true;
        length = 0;
        while (gao());
        putchar('\n');
        if (re > 0) {
            putchar('\n');
        }
    }

    return 0;
}
//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1801445   2009-03-24 04:55:11     Accepted    3079    C++     0   180     watashi@Zodiac

// 2012-09-07 02:00:36 | Accepted | 3079 | C++ | 0 | 184 | watashi | Source
