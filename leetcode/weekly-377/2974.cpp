class Solution {
public:
  vector<int> numberGame(vector<int>& a) {
    sort(a.begin(), a.end());
    for (int i = 0; i < (int)a.size(); i += 2) {
      swap(a[i], a[i + 1]);
    }
    return a;
  }
};
