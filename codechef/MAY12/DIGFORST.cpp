#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 128;
const int MAXM = 3 * 4 * 5 * 7;
const int INF = 1000000007;

vector<int> todo;

int ans;
int tag[MAXN];
bool mark[MAXN];
vector<int> e[MAXN];
int d[MAXN][MAXM];

void gao(int n, int lcm) {
    int x, y, z;
    priority_queue<pair<int, pair<int, int> > > pq;

    for (int i = 0; i < n; ++i) {
        mark[i] = (lcm % tag[i] == 0);
    }
    if (!mark[0] || !mark[n - 1]) {
        return;
    }

    fill(d[0], d[n], INF);
    y = tag[0] % lcm;
    z = tag[0];
    d[0][y] = z;
    pq.push(make_pair(-z, make_pair(0, y)));
    while (!pq.empty()) {
        z = -pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();
        if (z > d[x][y]) {
            continue;
        } else if (z >= ans || (x == n - 1 && y == 0)) {
            break;
        }
        for (vector<int>::const_iterator i = e[x].begin(); i != e[x].end(); ++i) {
            if (!mark[*i]) {
                continue;
            }
            int yy = (y * 10 + tag[*i]) % lcm;
            int zz = z + tag[*i];
            if (d[*i][yy] > zz) {
                d[*i][yy] = zz;
                pq.push(make_pair(-zz, make_pair(*i, yy)));
            }
        }
    }
    ans = min(ans, d[n - 1][0]);
}

int main() {
    int n, x;

    for (int i = 1; i <= MAXM; ++i) {
        if (MAXM % i == 0) {
            todo.push_back(i);
        }
    }
    while (scanf("%d", &n) != EOF && n > 0) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tag[i]);
            e[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &x);
                if (x != 0) {
                    e[i].push_back(j);
                }
            }
        }
        ans = INF;
        for (int i = 0; i < (int)todo.size(); ++i) {
            gao(n, todo[i]);
        }
        printf("%d\n", ans < INF ? ans : -1);
    }

    return 0;
}

//Correct Answer
//Execution Time: 0.33
