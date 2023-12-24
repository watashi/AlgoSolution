class Solution {
public:
  vector<int> findPeaks(vector<int>& a) {
    vector<int> ret;
    for (int i = 1; i + 1 < (int)a.size(); ++i) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
