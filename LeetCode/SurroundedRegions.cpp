/**
  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

  A region is captured by flipping all 'O's into 'X's in that surrounded region .

  For example,

  X X X X
  X O O X
  X X O X
  X O X X
  After running your function, the board should be:

  X X X X
  X X X X
  X X X X
  X O X X
  
  */

class Solution {
public:
  int M, N;
  
  void dfs(int x, int y, bool &isValid, vector<vector<char> > &board, vector<vector<bool> > &visited)
  {
    if (x >= 0 && y >= 0 && x < M && y < N && !visited[x][y]) {
      
      if (board[x][y] == 'O') {
        board[x][y] = 'D';
        visited[x][y] = true;
        
        if (x == 0 || y == 0 || x == M - 1 || y == M - 1) {
          isValid = false;
        }
      }
      
      int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
      
      for (int i = 0; i < 4; i ++) {
        dfs(x + dx[i], y + dy[i], isValid, board, visited);
      }
    }
  }
  
  bool bfs(int x, int y, vector<vector<char> > &board, vector<vector<bool> > &visited)
  {
    bool isValid = true;
    
    if (x == 0 || y == 0 || x == M - 1 || y == M - 1) {
      isValid = false;
    }
    
    queue<pair<int, int> > q;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    q.push(make_pair(x, y));
    
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      board[p.first][p.second] = 'D';
      
      for (int i = 0; i < 4; i ++) {
        int tmpx = p.first + dx[i], tmpy = p.second + dy[i];
        
        if (tmpx >= 0 && tmpy >= 0 && tmpx < M && tmpy < N && !visited[tmpx][tmpy]) {
          visited[tmpx][tmpy] = true;
          q.push(make_pair(tmpx, tmpy));
          
          if (tmpx == 0 || tmpy == 0 || tmpx == M - 1 || tmpy == M - 1) {
            isValid = false;
          }
        }
      }
    }
    
    return isValid;
  }
  
  void solve(vector<vector<char> > &board) {
    M = board.size();
    N = M > 0 ? board[0].size() : 0;

    if (M < 3 || N < 3) return;
    
    vector<vector<bool> > visited(M, vector<bool>(N, false));
    
    for (int i = 0; i < M; i ++) {
      for (int j = 0; j < N; j ++) {
        if (board[i][j] == 'X') {
          visited[i][j] = true;
        }
      }
    }
    
    for (int i = 0; i < M; i ++) {
      for (int j = 0; j < N; j ++) {
        if (!visited[i][j]) {
          bool isValid = bfs(i, j, board, visited);
          
          char tmpChar = isValid ? 'X' : 'O';
          
          for (int ii = 0; ii < M; ii ++) {
            for (int jj = 0; jj < N; jj ++) {
              if (board[ii][jj] == 'D') {
                board[ii][jj] = tmpChar;
              }
            }
          }
        }
      }
    }
    
  }
};