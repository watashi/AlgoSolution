class Solution {
public:
  long long cc(vector<int> x, vector<int> y) {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long z = 0;
    for (int i = 0; i < (int)x.size() && i < (int)y.size(); ++i) {
      z += max(0, y[i] - x[i]);
    }
    return z / 2;
  }

  long long makeSimilar(vector<int>& nums, vector<int>& target) {
    vector<int> x[2], y[2];
    for (int i : nums) {
      x[i % 2].push_back(i);
    }
    for (int i : target) {
      y[i % 2].push_back(i);
    }
    return cc(x[0], y[0]) + cc(x[1], y[1]);
  }
};
