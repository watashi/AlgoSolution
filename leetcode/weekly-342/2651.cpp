class Solution {
public:
  int findDelayedArrivalTime(int at, int dt) {
    return (at + dt) % 24;
  }
};
