class Solution {
public:
  string decodeMessage(string key, string message) {
    map<char, char> mp;
    char ch = 'a';
    for (char c : key) {
      if (c != ' ' && mp.count(c) == 0) {
        mp[c] = ch++;
      }
    }
    for (char& c : message) {
      if (c != ' ') {
        c = mp[c];
      }
    }
    return message;
  }
};
