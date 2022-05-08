class Solution {
public:
  string largestGoodInteger(string num) {
    string ret = "";
    for (int i = 3; i <= (int)num.length(); ++i) {
      if (num[i - 1] == num[i - 2] && num[i - 1] == num[i - 3]) {
        ret = max(ret, num.substr(i - 3, 3));
      }
    }
    return ret;
  }
};
