#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

vector<vector<string> > cells;
vector<vector<int> > sheet;

const char* next_cell(const char* p, int& r, int& c)
{
    if (isupper(*(p + 1))) {
        c = (*p - 'A' + 1) * 26 + *(p + 1) - 'A';
        p += 2;
    }
    else {
        c = *p - 'A';
        ++p;
    }
    r = 0;
    while (isdigit(*p)) {
        r *= 10;
        r += *p - '0';
        ++p;
    }
    --r;

    return p;
}

int getValue(int i, int j)
{
    int& ret = sheet[i][j];

    if (cells[i][j] == "") {
        return ret;
    }
    if (cells[i][j][0] != '=') {
        ret = atoi(cells[i][j].c_str());
    }
    else {
        int r, c;
        const char *p = cells[i][j].c_str() + 1;

        ret = 0;
        while (true) {
            p = next_cell(p, r, c);
            ret += getValue(r, c);
            if (*p == '\0') {
                break;
            }
            else {
                ++p;
            }
        }
    }
    cells[i][j] = "";

    return ret;
}

int main(void)
{
    int re, r, c;
    static char buf[1024];

    scanf("%d", &re);
    while (re--) {
        scanf("%d%d", &c, &r);
        cells = vector<vector<string> >(r, vector<string>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%s", buf);
                cells[i][j] = buf;
            }
        }
        sheet = vector<vector<int> >(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%d%c", getValue(i, j), (j == c - 1) ? '\n' : ' ');
            }
        }
        printf("\n");
    }
}

//Run ID    Submit time     Judge Status    Problem ID  Language    Run time    Run memory      User Name
//3009320   2008-07-27 20:21:59     Accepted    3009    C++     00:00.12    1684K   Re:ReJudge

// 2012-09-07 01:54:35 | Accepted | 3009 | C++ | 40 | 576 | watashi | Source
