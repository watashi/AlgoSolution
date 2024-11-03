class Solution {
public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    static constexpr int INF = 1900000007;
    static constexpr int DX[] = { 0, 1, 0, -1 };
    static constexpr int DY[] = { 1, 0, -1, 0 };

    const int n = moveTime.size();
    const int m = moveTime[0].size();
    vector<vector<int>> d(n, vector<int>(m, INF));
    priority_queue<pair<int, pair<int, int>>> pq;
    d[0][0] = 0;
    pq.emplace(0, make_pair(0, 0));
    while (!pq.empty()) {
      int z, x, y;
      tie(x, y) = pq.top().second;
      z = -pq.top().first;
      pq.pop();
      if (d[x][y] < z) {
        continue;
      }
      for (int k = 0; k < 4; ++k) {
        int xx = x + DX[k];
        int yy = y + DY[k];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
          continue;
        }
        int zz = max(z, moveTime[xx][yy]) + 2 - (xx + yy) % 2;
        if (d[xx][yy] > zz) {
          d[xx][yy] = zz;
          pq.emplace(-zz, make_pair(xx, yy));
        }
      }
    }
    return d[n - 1][m - 1];
  }
};
