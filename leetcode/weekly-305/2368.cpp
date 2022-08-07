class Solution {
public:
  int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<vector<int>> e(n);
    for (const auto& i : edges) {
      e[i[0]].push_back(i[1]);
      e[i[1]].push_back(i[0]);
    }
    vector<bool> mark(n, false), ban(n, false);
    queue<int> q;
    q.push(0);
    mark[0] = true;
    for (int i : restricted) {
      ban[i] = true;
    }
    while (!q.empty()) {
      int s = q.front();
      q.pop();
      for (int i: e[s]) {
        if (!mark[i] && !ban[i]) {
          q.push(i);
          mark[i] = true;
        }
      }
    }
    return count(mark.begin(), mark.end(), true);
  }
};
