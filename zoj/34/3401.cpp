#include <algorithm> // auto fix CE
#include <cstdio>

const int p[6] = {24, 19, 15, 10, 5, 0};
const char *sym[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

int main() {
    int k[6], m;
    bool blank = false;
    static char buf[1024];

    while (gets(buf) != NULL) {
        if (blank) {
            puts("");
        } else {
            blank = true;
        }
        k[0] = k[1] = k[2] = k[3] = k[4] = k[5] = 0;
        do {
            switch (sscanf(buf, "%d%d%d%d%d%d", &m, k + 1, k + 2, k + 3, k + 4, k + 5)) {
            case 1:
                if (m == 0) {
                    break;
                }
                m = 4 + p[m - 1] + k[m - 1];
                printf("%c%d%s\n", sym[m % 12][0], m / 12 + 3, sym[m % 12] + 1);
                break;
            case 6:
                k[0] = m;
                break;
            default:
                throw 1;
            }
        } while (gets(buf) != NULL && buf[0] != '\0');
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name   Admin
//1247  2010-07-31 20:32:38     Accepted    1148    C++     40  180     anotherpeg  Source

// 2012-09-07 15:51:59 | Accepted | 3401 | C++ | 20 | 180 | watashi | Source
