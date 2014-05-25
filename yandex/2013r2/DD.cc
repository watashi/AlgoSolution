#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void upd(string& ans, string ret) {
  if (ans == "") {
    ans = ret;
  } else {
    ans = "Invalid";
  }
}

int main() {
  string ans = "";
  long long a, b, c;

  cin >> a >> b >> c;
  if (a + b == c) {
    upd(ans, "+");
  }
  if (a - b == c) {
    upd(ans, "-");
  }
  if (a * b == c) {
    upd(ans, "*");
  }
  if (b != 0 && a == b * c) {
    upd(ans, "/");
  }
  if (ans == "") {
    ans = "Invalid";
  }
  cout << ans << endl;

  return 0;
}

