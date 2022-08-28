class Solution {
public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    vector<int> a = nums;
    sort(a.begin(), a.end());
    vector<int> s;
    int sum = 0;
    s.push_back(sum);
    for (int i : a) {
      sum += i;
      s.push_back(sum);
    }
    vector<int> ret;
    for (int i : queries) {
      ret.push_back(upper_bound(s.begin(), s.end(), i) - s.begin() - 1);
    }
    return ret;
  }
};
