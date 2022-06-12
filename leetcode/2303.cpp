class Solution {
public:
  double calculateTax(vector<vector<int>>& brackets, int income) {
    int64_t tax = 0;
    int pre = 0;
    for (const auto& i : brackets) {
      if (income > pre) {
        tax += (min(i[0], income) - pre)* (int64_t)i[1];
      }
      pre = i[0];
    }
    return tax / 100.0;
  }
};
