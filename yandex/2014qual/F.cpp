#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
char s[MAXN];

void clearBuffer(string& ans, string& buf) {
  ans += move(buf);
  buf.clear();
}

int main() {
  string buf, ans;

  fgets(s, sizeof(s), stdin);
  for (int i = 0; s[i] != '\n'; ++i) {
    const auto c = s[i];
    if (s[i + 1] == ')' &&
        !isalnum(c) && !isspace(c) && c != '(' && c != ')') {
      ++i;
      clearBuffer(ans, buf);
      ans += "<S>";
      ans += c;
      ans += s[i];
      ans += "</S>";
    } else if (c == '(') {
      clearBuffer(ans, buf);
      buf += c;
    } else if (buf.empty()) {
      ans += c;
    } else if (isalpha(c)) {
      buf += c;
    } else if (buf.size() > 1 && c == ')') {  // '()' is invalid
      buf += c;
      ans += "<S>";
      clearBuffer(ans, buf);
      ans += "</S>";
    } else {
      clearBuffer(ans, buf);
      ans += c;
    }
  }
  clearBuffer(ans, buf);  // !!
  puts(ans.c_str());

  return 0;
}
