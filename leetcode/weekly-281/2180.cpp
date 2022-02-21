class Solution {
public:
    int countEven(int num) {
        int d = num % 10;
        int x = num - d;
        int ans = x / 2 - 1;
        for (int i = x; i <= num; ++i) {
            int s = 0;
            int t = i;
            while (t > 0) {
                s += t % 10;
                t /= 10;
            }
            if (s % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
