class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    int l = count(moves.begin(), moves.end(), 'L');
    int r = count(moves.begin(), moves.end(), 'R');
    int x = count(moves.begin(), moves.end(), '_');
    return abs(l - r) + x;
  }
};
