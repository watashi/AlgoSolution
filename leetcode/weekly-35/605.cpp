class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = 0, c = 1;
        for (int i: flowerbed) {
            if (i == 0) {
                ++c;
            } else {
                m += (c - 1) / 2;
                c = 0;
            }
        }
        ++c;
        m += (c - 1) / 2;
        return m >= n;
    }
};
