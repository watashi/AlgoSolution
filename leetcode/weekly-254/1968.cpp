class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> x = nums;
    sort(x.begin(), x.end());
    vector<int> y(x.size());
    auto it = x.begin();
    for (int i = 0; i < (int)x.size(); i += 2) {
      y[i] = *it++;
    }
    for (int i = 1; i < (int)x.size(); i += 2) {
      y[i] = *it++;
    }
    return y;
  }
};
