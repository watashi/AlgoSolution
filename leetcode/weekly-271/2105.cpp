class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int refill = 0;
        int a = capacityA, b = capacityB;
        for (int i = 0, j = (int)plants.size() - 1; i <= j; ) {
            if (i == j) {
                if (max(a, b) < plants[i]) {
                    ++refill;
                }
                break;
            }
            if (a < plants[i]) {
                a = capacityA;
                ++refill;
            }
            a -= plants[i++];
            if (b < plants[j]) {
                b = capacityB;
                ++refill;
            }
            b -= plants[j--];
        }
        return refill;
    }
};
