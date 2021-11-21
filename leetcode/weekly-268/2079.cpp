class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ret = 0, rem = capacity;
        for (int i = 0; i < (int)plants.size(); ++i) {
            if (rem < plants[i]) {
                rem = capacity;
                ret += 2 * i;
            }
            rem -= plants[i];
        }
        ret += (int)plants.size();
        return ret;
    }
};
