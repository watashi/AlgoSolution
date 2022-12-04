class Solution {
public:
  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<int>> e(n);
    for (const auto& i : roads) {
      int a = i[0] - 1, b = i[1] - 1;
      e[a].push_back(b);
      e[b].push_back(a);
    }

    vector<bool> mark(n);
    queue<int> q;
    mark[0] = true;
    q.push(0);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (int b : e[a]) {
        if (!mark[b]) {
          mark[b] = true;
          q.push(b);
        }
      }
    }

    int ret = numeric_limits<int>::max();
    for (const auto& i : roads) {
      int a = i[0] - 1, b = i[1] - 1;
      e[a].push_back(b);
      e[b].push_back(a);
      if (mark[a] && mark[b]) {
        ret = min(ret, i[2]);
      }
    }
    return ret;
  }
};
