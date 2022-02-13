class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num2 == 0) {
            return 0;
        } else {
            return num1 / num2 + countOperations(num2, num1 % num2);
        }
    }
};
