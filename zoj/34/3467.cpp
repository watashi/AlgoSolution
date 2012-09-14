#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, z;
    Point() { }
    Point(int x, int y, int z) : x(x), y(y), z(z) { }
};

bool operator<(const Point& lhs, const Point &rhs) {
    if(lhs.x != rhs.x) {
        return lhs.x < rhs.x;
    } else if (lhs.y != rhs.y) {
        return lhs.y < rhs.y;
    } else {
        return lhs.z < rhs.z;
    }
}

Point operator+(const Point& lhs, const Point& rhs) {
    return Point(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

vector<Point> dir;

void init(int x, int y, int z) {
    int d[3] = {x, y, z};
    dir.clear();
    sort(d, d + 3);
    do {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    dir.push_back(Point(d[0], d[1], d[2]));
                    d[2] = -d[2];
                }
                d[1] = -d[1];
            }
            d[0] = -d[0];
        }
    } while (next_permutation(d, d + 3));
}

typedef map<Point, vector<Point> > Hash;

void gao(const Hash& from, Hash& to) {
    for (Hash::const_iterator i = from.begin(); i != from.end(); ++i) {
        for (vector<Point>::const_iterator j = dir.begin(); j != dir.end(); ++j) {
            vector<Point>& k = to[i->first + *j];
            if (k.empty() || k > i->second) {
                k = i->second;
            }
        }
    }
}

int main(void)
{
    bool flag;
    Hash bfs[4], rbfs[4];
    vector<Point> tmp, ans;
    Hash::const_iterator ptr;
    int x0, y0, z0, x1, y1, z1, x, y, z;

    while(scanf("%d%d%d%d%d%d%d%d%d", &x0, &y0, &z0, &x1, &y1, &z1, &x, &y, &z) != EOF) {
        init(x, y, z);
        for (int i = 0; i <= 3; i++) {
            bfs[i].clear();
            rbfs[i].clear();
        }
        ans.clear();

        flag = false;
        bfs[0][Point(x0, y0, z0)];
        rbfs[0][Point(x1, y1, z1)];
        if ((ptr = bfs[0].find(rbfs[0].begin()->first)) != bfs[0].end()) {
            flag = true;
        }

        for (int i = 1; i <= 3 && !flag; i++) {
            gao(bfs[i - 1], bfs[i]);
            for (Hash::iterator j = bfs[i].begin(); j != bfs[i].end(); ++j) {
                j->second.push_back(j->first);
            }
            if ((ptr = bfs[i].find(rbfs[0].begin()->first)) != bfs[i].end()) {
                ans = ptr->second;
                flag = true;
            }
        }

        for (int i = 1; i <= 3 && !flag; i++) {
            for (Hash::iterator j = rbfs[i - 1].begin(); j != rbfs[i - 1].end(); ++j) {
                j->second.insert(j->second.begin(), j->first);
            }
            gao(rbfs[i - 1], rbfs[i]);
            for (Hash::const_iterator j = rbfs[i].begin(); j != rbfs[i].end(); ++j) {
                if ((ptr = bfs[3].find(j->first)) != bfs[3].end()) {
                    tmp = ptr->second;
                    tmp.insert(tmp.end(), j->second.begin(), j->second.end());
                    ans = ans.empty() ? tmp : min(ans, tmp);
                    flag = true;
                }
            }
        }

        printf("To get from (%d,%d,%d) to (%d,%d,%d) takes ", x0, y0, z0, x1, y1, z1);
        if(!flag) {
            printf("more than 6 3D knight moves (%d,%d,%d).\n", x, y, z);
        } else {
            printf("%d 3D knight moves (%d,%d,%d): (%d,%d,%d)", ans.size(), x, y, z, x0, y0, z0);
            for (int i = 0; i < (int)ans.size(); ++i) {
                printf(" => (%d,%d,%d)", ans[i].x, ans[i].y, ans[i].z);
            }
            puts(".");
        }
    }
}

//Run ID    Submit Time     Judge Status    Problem ID  Language    Run Time(ms)    Run Memory(KB)  User Name   Admin
//706   2011-02-08 20:17:29     Accepted    A   C++     2270    2292    watashi@ArcOfDream  Source

// 2012-09-07 15:59:02 | Accepted | 3467 | C++ | 2220 | 2292 | watashi | Source
