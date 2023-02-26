static constexpr int DX[] = { 0, 1, 0, -1 };
static constexpr int DY[] = { 1, 0, -1, 0 };

class Solution {
public:
  int minimumTime(vector<vector<int>>& g) {
    int r = g.size(), c = g[0].size();
    if (g[0][1] > 1 && g[1][0] > 1) {
      return -1;
    }
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> d(r, vector<int>(c, numeric_limits<int>::max()));
    d[0][0] = 0;
    pq.push(make_pair(0, make_pair(0, 0)));
    while (!pq.empty()) {
      int z = -pq.top().first;
      int x = pq.top().second.first;
      int y = pq.top().second.second;
      pq.pop();
      if (z != d[x][y]) {
        continue;
      }
      for (int k = 0; k < 4; ++k) {
        int xx = x + DX[k];
        int yy = y + DY[k];
        if (xx < 0 || xx >= r || yy < 0 || yy >= c) {
          continue;
        }
        int zz = z + 1;
        if (zz < g[xx][yy]) {
          zz = g[xx][yy] + (g[xx][yy] - zz) % 2;
        }
        if (zz < d[xx][yy]) {
          d[xx][yy] = zz;
          pq.push(make_pair(-zz, make_pair(xx, yy)));
        }
      }
    }
    return d[r - 1][c - 1];
  }
};
