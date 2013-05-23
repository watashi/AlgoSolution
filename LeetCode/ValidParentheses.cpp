class Solution {
public:
  map<char, char> pair;
  vector<vector<bool> > isOK;
  vector<vector<bool> > caled;
  
  bool isValid(string s, int b, int e) {
    if (b > e) return true;
    if ((e - b + 1) % 2 == 1) return false;
    
    if (caled[b][e]) return isOK[b][e];
    caled[b][e] = true;
    
    if (pair.find(s[b]) == pair.end() || pair.find(s[e]) != pair.end()) {
      isOK[b][e] = false;
      return false;
    }
    
    for (int i = b + 1; i <= e; i += 2) {
      if (pair[s[b]] == s[i]) {
        // it is "&&"
        isOK[b][e] = isValid(s, b + 1, i - 1) && isValid(s, i + 1, e);
        if (isOK[b][e]) return true;
      }
    }
    
    return false;
  }
  
  bool isValid(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (s.length() % 2 == 1) return false;
    
    isOK.assign(s.length(), vector<bool>(s.length(), false));
    caled.assign(s.length(), vector<bool>(s.length(), false));
    
    pair['('] = ')';
    pair['['] = ']';
    pair['{'] = '}';
    
    return isValid(s, 0, s.length() - 1);
  }
};