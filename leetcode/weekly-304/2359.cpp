class Solution {
public:
  static vector<int> bfs(const vector<int>& e, int v) {
    vector<int> d(e.size(), e.size());
    queue<int> q;
    d[v] = 0;
    q.push(v);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      int y = e[x];
      if (y != -1 && d[y] > d[x] + 1) {
        d[y] = d[x] + 1;
        q.push(y);
      }
    }
    return d;
  }

  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    auto d1 = bfs(edges, node1);
    auto d2 = bfs(edges, node2);
    pair<int, int> ret(n, -1);
    for (int i = 0; i < n; ++i) {
      ret = min(ret, make_pair(max(d1[i], d2[i]), i));
    }
    return ret.second;
  }
};
