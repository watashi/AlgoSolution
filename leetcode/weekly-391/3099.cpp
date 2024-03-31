class Solution {
public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    int a = x, b = 0;
    for (int i = x; i > 0; i /= 10) {
      b += i % 10;
    }
    return a % b == 0 ? b : -1;
  }
};
