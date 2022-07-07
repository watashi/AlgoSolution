#include "bits/stdc++.h"

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using llint = long long;
using PII = pair<int, int>;
// BEGIN CUT HERE
#define __WATASHI__
// <errf>
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template <typename, typename = void>
constexpr bool is_iterable{};

template <typename T>
constexpr bool is_iterable<
  T,
  std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())
  >
> = true;

template<typename T, typename = enable_if_t<is_iterable<T>>>
inline void errf(const char* fmt, const T& v) {
  errf("{");
  for (const auto& i: v) {
    errf(fmt, i);
  }
  errf("}\n");
}
// </errf>
// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct TwoDimensionalSort {
  vector <int> sortLetters(vector <string> board);
};

static void add(vector<int>& ret, int x1, int y1, int x2, int y2) {
  if (x1 != x2 || y1 != y2) {
    ret.push_back(x1);
    ret.push_back(y1);
    ret.push_back(x2);
    ret.push_back(y2);
    errf("%d,%d -> %d,%d\n", x1, y1, x2, y2);
  }
}

vector <int> TwoDimensionalSort::sortLetters(vector <string> board) {
  vector<int> ret;
  vector<int> cols;
  map<char, pair<int, int>> pos;
  FOR(i, 26) {
    cols.push_back(i);
  }
  FOR(i, 26) {
    vector<pair<int, char>> todo;
    FOR(j, 26) {
      if (board[i][j] != '.') {
        todo.emplace_back(j, board[i][j]);
      }
    }
    for (int k = (int)todo.size() - 1; k >= 0; --k) {
      if (todo[k].first <= cols[k]) {
        add(ret, i, todo[k].first, i, cols[k]);
        pos[todo[k].second] = make_pair(i, cols[k]);
      }
    }
    for (int k = 0; k < (int)todo.size(); ++k) {
      if (todo[k].first > cols[k]) {
        add(ret, i, todo[k].first, i, cols[k]);
        pos[todo[k].second] = make_pair(i, cols[k]);
      }
    }
    cols.erase(cols.begin(), cols.begin() + todo.size());
  }
  for (const auto& i : pos) {
    int x = i.second.first;
    int y = i.second.second;
    add(ret, x, y, i.first - 'A', y);
  }
  return ret;
}

// BEGIN CUT HERE
// <main>
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << "{";
  FOR(i, v.size()) {
    os << "\"" << v[i] << "\",";
  }
  os << "}";

  return os;
}

vector<bool> __eq__;

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    __eq__.push_back(true);
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    __eq__.push_back(false);
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

      {
        string boardARRAY[] = {"..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            ".........................."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TwoDimensionalSort theObject;
        eq(0, theObject.sortLetters(board),vector <int>());
    }
    {
        string boardARRAY[] = {"..........................",
            "..........................",
            "......B...................",
            "..............Q...........",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            ".........................."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        int retrunValueARRAY[] = {3, 14, 3, 17 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TwoDimensionalSort theObject;
        eq(1, theObject.sortLetters(board),retrunValue);
    }
    {
        string boardARRAY[] = {"..........................",
            "..........................",
            "..........................",
            ".....BCDE.................",
            ".....F....................",
            ".....G.A..................",
            ".....H....................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            ".........................."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        int retrunValueARRAY[] = {5, 7, 5, 9, 5, 9, 2, 9 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TwoDimensionalSort theObject;
        eq(2, theObject.sortLetters(board),retrunValue);
    }
    {
        string boardARRAY[] = {"..........................",
            "..........................",
            "..........................",
            ".....BCED.................",
            ".....F....................",
            ".....G.A..................",
            ".....H....................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            "..........................",
            ".........................."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        int retrunValueARRAY[] = {3, 7, 2, 7, 2, 7, 2, 11, 5, 7, 0, 7, 2, 11, 3, 11 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        TwoDimensionalSort theObject;
        eq(3, theObject.sortLetters(board),retrunValue);
    }

  int __pass__ = count(ALL(__eq__), true);
  int __fail__ = count(ALL(__eq__), false);
  if (__fail__ == 0) {
    errf("\033[1;32mAll %d Passed\033[0m\n", __pass__);
  } else if (__pass__ == 0) {
    errf("\033[1;31mAll %d Failed\033[0m\n", __fail__);
  } else {
    errf("\033[1;31m%d Passed; %d Failed\033[0m\n", __pass__, __fail__);
    if (__eq__[0]) {
      errf("\033[1;31mDid you reset global variables?\033[0m\n");
    }
  }
  errf("\033[1;33mPress any key to continue...\033[0m\n");
  (void)getchar();

  return 0;
}

/*
 * __builtin_popcount __builtin_ctz
 * make_pair first second
 * iterator const_iterator
 * priority_queue
 * push_back
 */
/*
 * vim: ft=cpp.doxygen
 */
// </main>
// END CUT HERE
