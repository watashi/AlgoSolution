class Solution {
public:
  int findMinimumTime(vector<vector<int>>& tasks) {
    int n = tasks.size();
    int m = 0;
    vector<int> start(n), end(n), latest(n);
    for (int i = 0; i < n; ++i) {
      start[i] = tasks[i][0];
      end[i] = tasks[i][1] + 1;
      latest[i] = end[i] - tasks[i][2];
      m = max(m, end[i]);
    }
    int ret = 0;
    for (int i = 0; i < m; ++i) {
      bool flag = false;
      for (int j = 0; j < n; ++j) {
        if (latest[j] == i) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        continue;
      }
      ++ret;
      for (int j = 0; j < n; ++j) {
        if (latest[j] != -1 && start[j] <= i) {
          if (++latest[j] == end[j]) {
            latest[j] = -1;
          }
        }
      }
    }
    return ret;
  }
};
