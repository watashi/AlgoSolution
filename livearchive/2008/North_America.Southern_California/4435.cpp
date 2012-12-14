#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> Rec;

const int MAXN = 128;
const int INF = 1000000007;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int w[MAXN][MAXN], d[MAXN][MAXN];

int main() {
    int ri = 0, n;
   
    //freopen("d.in", "r", stdin);
    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &w[i][j]);
                d[i][j] = INF;
            }
        }
        priority_queue<Rec, vector<Rec>, greater<Rec> > q;
        q.push(Rec(d[0][0] = 0, PII(0, 0)));
        while (!q.empty()) {
            int z = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if (d[x][y] != z) {
                continue;
            }
            z += w[x][y];
            for (int k = 0; k < 4; ++k) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && d[xx][yy] > z) {
                    d[xx][yy] = z;
                    q.push(Rec(z, PII(xx, yy)));
                }
            }
        }
        printf("Problem %d: %d\n", ++ri, d[n - 1][n - 1] + w[n - 1][n - 1]);
    }

    return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727364  	2011-01-29 12:22:31 	Accepted	0.049	Minimum	26909	C++	4435 - Obstacle Course

/*
id => 1174034
pid => 4435
pname => Obstacle Course
status => Accepted
lang => C++
time => 0.018
date => 2012-12-14 17:13:09
*/
