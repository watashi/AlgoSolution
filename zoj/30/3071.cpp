#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

const int z[5][4] = {{}, {-1, 0, 1, 2}, {-1, 3, 4, 5}, {-1, 6, 7, 8}, {-1, 9, 10}};
const int x[11] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
const int y[11] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2};
const char d[] = "78945612300";
const int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef pair<int, pair<int, int> > state;
int mind[101][11][11];
vector<pair<int, int> > both[11][11], left[11][11], right[11][11];

bool isvalid(int xx, int yy)
{
    return xx == 4 ? (yy == 1 || yy == 2) : (xx >= 1 && xx <= 3 && yy >= 1 && yy <= 3);
}

bool isvalid(int xl, int yl, int xr, int yr)
{
    return yl < yr && isvalid(xl, yl) && isvalid(xr, yr);
}

void gen(int l, int r)
{
    static int x1[5], y1[5], x2[5], y2[5];

    for (int j = 0; j < 5; j++) {
        x2[j] = x[r] + dir[j][0];
        y2[j] = y[r] + dir[j][1];
        if (isvalid(x[l], y[l], x2[j], y2[j])) {
            right[l][r].push_back(make_pair(z[x[l]][y[l]], z[x2[j]][y2[j]]));
        }
    }
    for (int i = 0; i < 5; i++) {
        x1[i] = x[l] + dir[i][0];
        y1[i] = y[l] + dir[i][1];
        if (isvalid(x1[i], y1[i], x[r], y[r])) {
            left[l][r].push_back(make_pair(z[x1[i]][y1[i]], z[x[r]][y[r]]));
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (isvalid(x1[i], y1[i], x2[j], y2[j])) {
                both[l][r].push_back(make_pair(z[x1[i]][y1[i]], z[x2[j]][y2[j]]));
            }
        }
    }
}

void gen()
{
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (isvalid(x[i], y[i], x[j], y[j])) {
                gen(i, j);
            }
        }
    }
}

int main()
{
    static char buf[1024];

    gen();
    while (scanf("%s", buf) != EOF && strcmp(buf, "eof") != 0) {
        queue<state> q;
        int k, l, r;

        memset(mind, 0xff, sizeof(mind[0]) * (strlen(buf) + 1));
        mind[0][3][4] = 0;
        q.push(make_pair(0, make_pair(3, 4)));
        while (!q.empty()) {
            k = q.front().first;
            l = q.front().second.first;
            r = q.front().second.second;
            q.pop();
            if (buf[k] == '\0') {
                printf("%d\n", mind[k][l][r]);
                break;
            }
            if (buf[k] == d[l]) {
                for (vector<pair<int, int> >::const_iterator i = right[l][r].begin(); i != right[l][r].end(); ++i) {
                    if (mind[k + 1][i->first][i->second] == -1) {
                        mind[k + 1][i->first][i->second] = mind[k][l][r] + 1;
                        q.push(make_pair(k + 1, make_pair(i->first, i->second)));
                    }
                }
            }
            if (buf[k] == d[r]) {
                for (vector<pair<int, int> >::const_iterator i = left[l][r].begin(); i != left[l][r].end(); ++i) {
                    if (mind[k + 1][i->first][i->second] == -1) {
                        mind[k + 1][i->first][i->second] = mind[k][l][r] + 1;
                        q.push(make_pair(k + 1, make_pair(i->first, i->second)));
                    }
                }
            }
            for (vector<pair<int, int> >::const_iterator i = both[l][r].begin(); i != both[l][r].end(); ++i) {
                if (mind[k][i->first][i->second] == -1) {
                    mind[k][i->first][i->second] = mind[k][l][r] + 1;
                    q.push(make_pair(k, make_pair(i->first, i->second)));
                }
            }
        }
    }

    return 0;
}

//Run ID    Submit Time     Judge Status    Problem ID      Language    Run Time(ms)    Run Memory(KB)      User Name
//1750230   2009-01-28 15:46:37     Accepted    3071    C++     0   228     watashi@Zodiac

// 2012-09-07 01:59:59 | Accepted | 3071 | C++ | 0 | 232 | watashi | Source
