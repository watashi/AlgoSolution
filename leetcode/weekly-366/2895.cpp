class Solution {
public:
  int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    vector<int> x, y = tasks;
    x.reserve(tasks.size());
    for (int i : processorTime) {
      for (int j = 0; j < 4; ++j) {
        x.push_back(i);
      }
    }
    sort(x.begin(), x.end());
    sort(y.rbegin(), y.rend());
    for (int i = 0; i < (int)x.size(); ++i) {
      x[i] += y[i];
    }
    return *max_element(x.begin(), x.end());
  }
};
