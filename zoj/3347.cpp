#include <cctype>
#include <cstdio>

using namespace std;

static char ch;

inline int nextInt() {
    do {
        ch = getchar();
    } while (isspace(ch));
    int ret = 0;
    bool flag = (ch == '-');
    if (ch == '-') {
        ch = getchar();
    }
    while (isdigit(ch)) {
        ret = ret * 10 + (ch - '0');
        ch = getchar();
    }
    return flag ? -ret : ret;
}

int a[256][256];
int x1[100100], y1[100100], x2[100100], y2[100100], op[100100];

int main() {
    int w, h, n, x, y, z, s;

    while ((w = nextInt()) > 0) {
        h = nextInt();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                a[i][j] = nextInt();
            }
        }
        n = nextInt();
        for (int i = 0; i < n; ++i) {
            x1[i] = nextInt();
            y1[i] = nextInt();
            x2[i] = nextInt();
            y2[i] = nextInt();
            op[i] = nextInt();
        }
        x = nextInt();
        y = nextInt();
        z = 0;
        s = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (x1[i] <= x && x <= x2[i] && y1[i] <= y && y <= y2[i]) {
                switch (op[i]) {
                    case 1:
                        z = -z;
                        s = -s;
                        break;
                    case 2:
                        ++z;
                        break;
                    case 3:
                        --z;
                        break;
                    case 4:
                        x = x1[i] + x2[i] - x;
                        break;
                    case 5:
                        y = y1[i] + y2[i] - y;
                        break;
                }
            }
        }
        printf("%d\n", s * (a[y][x] + z));
    }

    return 0;
}

// 2012-09-07 15:47:19 | Accepted | 3347 | C++ | 70 | 2392 | watashi | Source
