class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    static const int DX[] = {0, 1, 0, -1};
    static const int DY[] = { 1, 0, -1, 0 };
    vector<vector<int>> ret(m, vector<int>(n, -1));
    int x = 0, y = -1, z = 0;
    while (head != nullptr) {
      while (true) {
        int xx = x + DX[z];
        int yy = y + DY[z];
        if (0 <= xx && xx < m && 0 <= yy && yy < n && ret[xx][yy] == -1) {
          x = xx;
          y = yy;
          break;
        }
        z = (z + 1) % 4;
      }
      ret[x][y] = head->val;
      head = head->next;
    }
    return ret;
  }
};
