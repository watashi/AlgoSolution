class Solution {
public:
  string smallestString(string s) {
    bool pre = true;
    for (char& c : s) {
      if (c == 'a') {
        if (!pre) {
          break;
        }
      }
      else {
        pre = false;
        --c;
      }
    }
    if (pre) {
      s.back() = 'z';
    }
    return s;
  }
};
