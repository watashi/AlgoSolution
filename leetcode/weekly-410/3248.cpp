class Solution {
public:
  int finalPositionOfSnake(int n, vector<string>& commands) {
    int x = 0, y = 0;
    for (const auto& cmd : commands) {
      switch (cmd[0]) {
      case 'U':
        --x;
        break;
      case 'R':
        ++y;
        break;
      case 'D':
        ++x;
        break;
      case 'L':
        --y;
        break;
      }
    }
    return x * n + y;
  }
};
