class Solution {
public:
  string maximumNumber(string num, vector<int>& change) {
    size_t i = 0;
    while (i < num.size() && change[num[i] - '0'] <= num[i] - '0') {
      ++i;
    }
    while (i < num.size() && change[num[i] - '0'] >= num[i] - '0') {
      num[i] = '0' + change[num[i] - '0'];
      ++i;
    }
    return num;
  }
};
