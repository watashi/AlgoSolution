class Solution {
public:
  bool isValid(string word) {
    if (word.length() < 3) {
      return false;
    }
    bool v = false, c = false;
    for (char ch : word) {
      if (isdigit(ch)) {
        continue;
      }
      else if ("aeiou"s.find(tolower(ch)) != string::npos) {
        v = true;
      }
      else if (isalpha(ch)) {
        c = true;
      }
      else {
        return false;
      }
    }
    return v && c;
  }
};
