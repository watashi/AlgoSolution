#include <bits/stdc++.h>

using namespace std;

constexpr int dx[4] = {0, 1, 0, -1};
constexpr int dy[4] = {1, 0, -1, 0};

static char grid[28][28];
static bool g[28][28];

int gao(int x, int y) {
  if (!g[x][y]) {
    return 0;
  } else {
    int ret = 1;
    g[x][y] = false;
    for (int i = 0; i < 4; ++i) {
      ret += gao(x + dx[i], y + dy[i]);
    }
    return ret;
  }
}

bool test(int z, bool i, bool j, char c) {
  int k = (i ? 0 : 2) | (j ? 0 : 1);
  char d = ((z >> k) & 1) == 0 ? 'B' : 'W'; // 0 -> B
  return c == d;
}

int main() {
  int re;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    int r, c;
    scanf("%d%d", &r, &c);
    fill(grid[0], grid[r + 2], '\0');
    for (int i = 1; i <= r; ++i) {
      scanf("%s", grid[i] + 1);
    }

    int ans = 1;
    vector<int> zs;

    zs.clear();
    for (int x = 1; x < r; ++x) {
      for (int y = 1; y < c; ++y) {
        int z = 0;
        if (grid[x][y] == 'W') {
          z |= 1;
        }
        if (grid[x][y + 1] == 'W') {
          z |= 2;
        }
        if (grid[x + 1][y] == 'W') {
          z |= 4;
        }
        if (grid[x + 1][y + 1] == 'W') {
          z |= 8;
        }
        zs.emplace_back(z);
      }
    }
    sort(zs.begin(), zs.end());
    zs.erase(unique(zs.begin(), zs.end()), zs.end());
    for (int x = 0; x <= r; ++x) {
      for (int y = 0; y <= c; ++y) {
        for (int z: zs) {
          fill(g[0], g[r + 2], false);
          // printf("%d %d %d\n", x, y, z);
          for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
              g[i][j] = test(z, i <= x, j <= y, grid[i][j]);
              // putchar(grid[i][j] ? '#' : '.');
            }
          }
          // puts("");
          for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
              ans = max(ans, gao(i, j));
            }
          }
        }
      }
    }

    for (int rot = 0; rot < 2; ++rot) {
      zs.clear();
      for (int x = 1; x <= r; ++x) {
        for (int y = 1; y < c; ++y) {
          int z = 0;
          if (grid[x][y] == 'W') {
            z |= 1;
          }
          if (grid[x][y + 1] == 'W') {
            z |= 2;
          }
          zs.emplace_back(z);
        }
      }
      sort(zs.begin(), zs.end());
      zs.erase(unique(zs.begin(), zs.end()), zs.end());
      for (int y = 0; y <= c; ++y) {
        for (int z: zs) {
          fill(g[0], g[r + 2], false);
          // printf("%d %d\n", y, z);
          for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
              g[i][j] = test(z, true, j <= y, grid[i][j]);
              // putchar(g[i][j] ? '#' : '.');
            }
            // puts("");
          }
          for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
              ans = max(ans, gao(i, j));
            }
          }
        }
      }

      for (int i = 1; i <= max(r, c); ++i) {
        for (int j = 1; j <= i; ++j) {
          swap(grid[i][j], grid[j][i]);
        }
      }
      swap(r, c);
    }

    printf("Case #%d: %d\n", ri, ans);
  }

  return 0;
}
