// You must perform a transformation in such a way that as many words as possible are transformed to numbers
// If there are several way to perform the transformation in such a way, you must do it so that the first number is as great as possible. If there are still several ways, maximize the second number, and so on.

#include <map>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>

using namespace std;

const char* str[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90};
map<string, int> mp;
map<int, string> pm;

const int MAXN = 1000000;
char buf[MAXN];
int wc[MAXN], dp[MAXN], pre[MAXN], val[MAXN];
string w[MAXN];

bool isalpha(const string& s) {
  return s.length() > 0 && isalpha(s[0]);
}

bool isspace(const string& s) {
  for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
    if (!isspace(*i)) {
      return false;
    }
  }
  return true;
}

string tolower(string s) {
  for (string::iterator i = s.begin(); i != s.end(); ++i) {
    *i = (char)tolower(*i);
  }
  return s;
}

typedef const string* ptr;

ptr skip(ptr p) {
  while (isspace(*p)) {
    ++p;
  }
  return p;
}

// gao5
int find(const string& s) {
  return mp.count(s) == 0 ? -1 : mp[s];
}

// [yz]
pair<int, ptr> gao4(ptr p) {
  // fprintf(stderr, "[4] '%s'\n", p->c_str());
  int val = find(tolower(*p));
  // assert(isalpha(*p));
  if (val < 20) { // include (val == -1)
    return make_pair(val, p + 1);
  } else {
    ptr q = skip(p + 1);
    int t = find(tolower(*q));
    if (t != -1 && t < 10) {
      return make_pair(val + t, q + 1);
    } else {
      return make_pair(val, p + 1);
    }
  }
}

// [xyz]
pair<int, ptr> gao3(ptr p) {
  // fprintf(stderr, "[3] '%s'\n", p->c_str());
  int val;
  // assert(isalpha(*p));
  val = find(tolower(*p));
  if (val == -1) {
    return make_pair(-1, p + 1);
  } else if (val < 10) {
    ptr q = skip(p + 1);
    if (tolower(*q) == "hundred") {
      ptr r = skip(q + 1);
      if (tolower(*r) == "and") {
        pair<int, ptr> pip = gao4(skip(r + 1));
        if (pip.first == -1) {
          return make_pair(val * 100, q + 1);
        } else {
          return make_pair(val * 100 + pip.first, pip.second);
        }
      } else {
        return make_pair(val * 100, q + 1);
      }
    } else {
      return make_pair(val, p + 1);
    }
  } else {
    return gao4(p);
  }
}

// [def] thousand [ghi]
pair<int, ptr> gao2(ptr p) {
  // fprintf(stderr, "[2] '%s'\n", p->c_str());
  pair<int, ptr> pip = gao3(p);
  if (pip.first == -1) {
    return pip;
  }
  ptr q = skip(pip.second);
  if (tolower(*q) == "thousand") {
    pair<int, ptr> qiq = gao3(skip(q + 1));
    if (qiq.first == -1) {
      return make_pair(pip.first * 1000, q + 1);
    } else {
      return make_pair(pip.first * 1000 + qiq.first, qiq.second);
    }
  } else {
    return pip;
  }
}

// [abc] million [def] thousand [ghi]
pair<int, ptr> gao1(ptr p) {
  // fprintf(stderr, "[1] '%s'\n", p->c_str());
  pair<int, ptr> pip = gao3(p);
  if (pip.first == -1) {
    return pip;
  }
  ptr q = skip(pip.second);
  if (tolower(*q) == "million") {
    pair<int, ptr> qiq = gao2(skip(q + 1));
    if (qiq.first == -1) {
      return make_pair(pip.first * 1000000, q + 1);
    } else {
      return make_pair(pip.first * 1000000 + qiq.first, qiq.second);
    }
  } else {
    return gao2(p);
  }
}

pair<int, ptr> gao(ptr p) {
  // fprintf(stderr, "[0] '%s'\n", p->c_str());
  if (!isalpha(*p)) {
    return make_pair(-1, p + 1);
  } else if (tolower(*p) == "zero") {
    return make_pair(0, p + 1);
  } else {
    return gao1(p);
  }
}

int main() {
  for (size_t i = 0; i < sizeof(num) / sizeof(int); ++i) {
    mp[str[i]] = num[i];
    pm[num[i]] = str[i];
  }

#ifndef __WATASHI__
  freopen("numbers.in", "r", stdin);
  freopen("numbers.out", "w", stdout);
#endif

  int n = 0;
  while (fgets(buf, sizeof(buf), stdin) != NULL) {
    for (int begin = 0; buf[begin] != '\0';) {
      int end = begin + 1;
      if (isalpha(buf[begin])) {
        while (buf[end] != '\0' && isalpha(buf[end])) {
          ++end;
        }
      } else {
        while (buf[end] != '\0' && !isalpha(buf[end])) {
          ++end;
        }
      }
      w[n++] = string(buf + begin, buf + end);
      if (n >= MAXN) { throw 1; }
      begin = end;
    }
  }
  w[n] = "0";

  char ch = '0';
  //string s = "0";
  wc[0] = 0;
  for (int i = 1; i <= n; ++i) {
    wc[i] = wc[i - 1] + isalpha(w[i - 1]);
  }
  dp[n] = 0;
  val[n] = -1;
  pre[n] = -1;
  for (int i = n - 1; i >= 0; --i) {
    dp[i] = -1;
    //printf("[%d] ", i);
    for (int j = n, k = j; j > i; j = k - 1) {
      swap(w[j][0], ch);
      //swap(s, w[j]); -> MLE
      //printf("%d,", j);
      pair<int, ptr> pip = gao(w + i);
      k = pip.second - w;
      int d = pip.first == -1 ? 0 : wc[k] - wc[i];
      int v = pip.first == -1 ? val[i + 1] : pip.first;
      if (dp[i] < dp[k] + d || (dp[i] == dp[k] + d && val[i] < v)) {
        dp[i] = dp[k] + d;
        val[i] = v;
        pre[i] = k;
      }
      swap(w[j][0], ch);
      //swap(s, w[j]); -> MLE
    }
    //printf(":: %d, %d, %d\n", dp[i], val[i], pre[i]);
  }

  for (int i = 0; i != n; i = pre[i]) {
    if (dp[i] == dp[pre[i]]) {
      printf("%s", w[i].c_str());
    } else {
      printf("%d", val[i]);
    }
  }

  return 0;
}

