class Solution {
public:
  int countCompleteDayPairs(vector<int>& hours) {
    static constexpr int M = 24;
    vector<long long> c(M);
    for (int i : hours) {
      ++c[i % M];
    }
    long long ret = 0;
    for (int i = 0; i < M; ++i) {
      const int j = (M - i) % M;
      if (i < j) {
        ret += c[i] * c[j];
      }
      else if (i == j) {
        ret += c[i] * (c[i] - 1) / 2;
      }
    }
    return ret;
  }
};
