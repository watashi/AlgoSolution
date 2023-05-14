class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<bool>> e(n, vector<bool>(n, false));
    for (const auto& i : edges) {
      int a = i[0], b = i[1];
      e[a][b] = e[b][a] = true;
    }
    int ret = 0;
    vector<bool> mark(n, false);
    for (int i = 0; i < n; ++i) {
      if (mark[i]) {
        continue;
      }
      queue<int> q;
      vector<int> cc;
      mark[i] = true;
      q.push(i);
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        cc.push_back(a);
        for (int b = 0; b < n; ++b) {
          if (!mark[b] && e[a][b]) {
            mark[b] = true;
            q.push(b);
          }
        }
      }
      for (int a : cc) {
        for (int b : cc) {
          if (a != b && !e[a][b]) {
            goto NEXT;
          }
        }
      }
      ++ret;
NEXT:
      continue;
    }
    return ret;
  }
};
