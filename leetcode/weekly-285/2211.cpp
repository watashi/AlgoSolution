class Solution {
public:
    int countCollisions(string d) {
        int ans = (int)d.size();
        for (char c: d) {
            if (c == 'S') {
                --ans;
            }
        }
        for (int i = 0; i < (int)d.size() && d[i] == 'L'; ++i) {
            --ans;
        }
        for (int i = (int)d.size() - 1; i >= 0 && d[i] == 'R'; --i) {
            --ans;
        }
        return ans;
    }
};
