class Solution {
public:
  int maximumGroups(vector<int>& grades) {
    int n = grades.size();
    int ret = 0;
    while (n > ret) {
      n -= ++ret;
    }
    return ret;
  }
};
